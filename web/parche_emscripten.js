const fs = require('fs');

const file = process.argv[2] || 'index.js';
let js = fs.readFileSync(file, 'utf8');

const patchBlock = `
          // === INYECCIÓN NATIVA: MODO ESCRITURA EN TIEMPO REAL ===
          if (typeof window !== 'undefined' && window.aboutToType && tty.output.length === 2 && tty.output[0] === 45 && tty.output[1] === 32) {
            window.isTypingName = true;
            window.aboutToType = false;
          }
          if (typeof window !== 'undefined' && window.isTypingName) {
            out(UTF8ArrayToString(tty.output));
            tty.output = [];
          }
          // =======================================================
`;

if (js.includes("INYECCIÓN NATIVA: MODO ESCRITURA")) {
    console.log("El parche ya estaba activo en " + file + ".");
} else {
    let success = false;

    // Caso 1: Emscripten 6.x+ (SYSCALLS_REQUIRE_FILESYSTEM=0 con printCharBuffers y _fd_write)
    if (js.includes("_fd_write") && js.includes("printCharBuffers")) {
        const modernPatch = `
      // === INYECCIÓN NATIVA: MODO ESCRITURA EN TIEMPO REAL ===
      if (printCharBuffers && printCharBuffers[fd] && printCharBuffers[fd].length > 0) {
        (fd === 1 ? out : err)(UTF8ArrayToString(printCharBuffers[fd]));
        printCharBuffers[fd].length = 0;
      }
      // =======================================================
`;
        js = js.replace(/(HEAPU32\[\(\(pnum\)>>2\)\]\s*=\s*num;)/, function(match) {
            success = true;
            return modernPatch + "      " + match;
        });
    }

    // Caso 2: Emscripten legado (put_char en TTY)
    if (!success) {
        js = js.replace(/(put_char\(tty,\s*val\)\s*\{[\s\S]*?)tty\.output\.push\(val\);/m, function(match, p1) {
            success = true;
            return match + patchBlock;
        });
    }

    if (success) {
        fs.writeFileSync(file, js, 'utf8');
        console.log("-> Parche inyectado con exito en " + file + "! (Entrada y salida de consola en tiempo real activa)");
    } else {
        console.warn("-> ADVERTENCIA: No se pudo inyectar el parche en " + file + ".");
    }
}

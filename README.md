# 🏰 Castle Cat

**Castle Cat** es un RPG de mazmorras y combate por turnos programado en **C**, con interfaz visual estilizada mediante secuencias de escape ANSI, animaciones de texto por máquina de escribir, mapa de navegación procedural y soporte tanto para **WebAssembly (Emscripten)** en el navegador como para **Windows nativo**.

---

## 📜 Historia y Lore

En el reino de **Nekovania**, algunos ciudadanos desaparecen sin dejar rastro en la niebla. Cuenta la leyenda que un dragón colosal, el temible **Shadow Meow**, mora en las profundidades del **Castle Cat** custodiando a sus prisioneros. Un valiente gato decide adentrarse en la mazmorra con el único propósito de salvar a su amada y liberar el reino de la maldición.

---

## 🎮 Características del Juego

- **3 Clases de Héroe:**
  - ⚔️ **Guerrero**: Alta vitalidad y daño físico basado en Fuerza (Ataques: *Corte Fino*, *Golpe Resonante*, *Colmillo Flamígero*...).
  - 🔮 **Mago**: Alto maná y daño elemental basado en Inteligencia (Ataques: *Invocación de Raíces*, *Proyectil Lumínico*, *Infinidad Arcana*...).
  - 🗡️ **Asesino**: Rápido y letal basado en Agilidad (Ataques: *Puñalada Sombría*, *Corte Aéreo*, *Mil Cortes de la Noche*...).
- **Mazmorra Procedural**: Mapas generados aleatoriamente con salas de Entrada, Salas vacías, Encuentros con Enemigos `[E]`, Cofres del Tesoro `[T]` y Salas de Jefes `[S]`.
- **Sistema de Combate e Inventario**: Gestión de consumibles, pociones de estadísticas, equipamiento de armas principales y secundarias con escalado de daño y costes de maná.
- **Audio y SFX**: Música de fondo retro chiptune 8-bit y efectos sonoros interactivos (golpes, cofres, habilidades, muerte).

---

## 📂 Estructura del Proyecto

```text
CastleCat-Web/
├── index.html               # Web oficial y panel interactivo en GitHub Pages
├── CastleCat.css            # Estilos de la web oficial
├── sprites/                 # Sprites e ilustraciones (enemigos, jefes, iconos 1-4)
├── .gitignore               # Configuración de exclusiones para Git
├── README.md                # Documentación del proyecto
│
└── game/                    # Proyecto completo del juego en C y WebAssembly
    ├── src/                 # Código fuente en C
    │   ├── Main.c           # Bucle principal del juego y lógica de estados
    │   ├── ComandosBasicos.c# Entrada de teclado, delays typewriter y utilidades
    │   ├── Combate.c        # Motor de combate por turnos y cálculo de daño
    │   ├── Enemigos.c       # Catálogo de enemigos comunes, jefes y arte ASCII
    │   ├── FinDelJuego.c    # Escenas de victoria, muerte y créditos
    │   ├── Habilidades.c    # Definición de skills, multiplicadores y maná
    │   ├── Infor.c          # Renderizado de barras de vida/maná y stats
    │   ├── Intro.c          # Menú principal, selector de héroe y narrativa
    │   ├── Mapa.c           # Generación procedural del mapa y movimiento
    │   └── ObjetosyTesoros.c# Sistema de ítems, armas e inventario
    │
    ├── assets/              # Recursos de audio y efectos
    │   ├── music.mp3        # Banda sonora retro 8-bit
    │   ├── Confirm.mp3
    │   ├── NextOption.mp3
    │   ├── Volume.mp3
    │   ├── glitch.png
    │   └── SFX/             # Efectos de sonido (wav)
    │
    └── web/                 # Plantillas e inyectores para WebAssembly
        ├── shell.html       # Shell HTML con terminal ANSI y reproductor de audio
        └── parche_emscripten.js # Inyector para sincronización de E/S en tiempo real
```

---

## ⚙️ Cómo Compilar y Jugar

### 🌐 1. Versión Web (WebAssembly con Emscripten)

1. Compila con `emcc` desde la raíz del proyecto:
   ```bash
   emcc game/src/Main.c -O2 -s WASM=1 -s ASYNCIFY -s ALLOW_MEMORY_GROWTH=1 --shell-file game/web/shell.html -o index.html
   ```
2. Para probar el juego en tu navegador, inicia un servidor local:
   ```bash
   python -m http.server 8080
   # Abre en tu navegador: http://localhost:8080
   ```

### 💻 2. Versión Nativa (Windows)

1. Compila con GCC vinculando la librería de sonido de Windows (`winmm`):
   ```bash
   gcc game/src/Main.c -o CastleCat.exe -lwinmm
   ```
2. Ejecuta `CastleCat.exe` directamente en la terminal.

---

## 🕹️ Controles

| Tecla | Acción |
| :--- | :--- |
| `W` / `▲` | Moverse arriba / Subir opción |
| `S` / `▼` | Moverse abajo / Bajar opción |
| `A` / `◄` | Moverse izquierda |
| `D` / `►` | Moverse derecha |
| `ENTER` | Confirmar / Seleccionar / Avanzar turno |

---

## 👥 Créditos

- **Creadores & Programadores**: Pau Cremades (**ETERNODEV**), Angel Roig (**BLUELLAMA**).
- **Agradecimientos Especiales**: José Fernando Pérez.
- **Música & SFX**: BLUELLAMA & ETERNODEV.

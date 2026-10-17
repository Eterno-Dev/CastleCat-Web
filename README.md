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
├── styles.html              # Tipografías y estilos embebidos
├── sprites/                 # Sprites e ilustraciones (enemigos, jefes, iconos 1-4)
├── data/                    # Tablas de datos y estadísticas CSV (bosses, enemigos, etc.)
├── .gitignore               # Configuración de exclusiones para Git
├── README.md                # Documentación del proyecto
├── Subir_A_GitHub.bat       # Script para enviar cambios a GitHub
│
└── game/                    # Proyecto completo del juego en C y WebAssembly
    ├── Compilar.bat         # Compila el juego a WebAssembly en game/temp/
    ├── Compilar_Nativo.bat  # Compila el juego a ejecutable Windows en game/temp/
    │
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
    ├── assets/              # Recursos de audio
    │   ├── music.mp3        # Banda sonora retro 8-bit
    │   └── SFX/             # Efectos de sonido (wav)
    │
    ├── web/                 # Herramientas y plantillas para WebAssembly
    │   ├── shell.html       # Shell HTML con terminal ANSI y reproductor de audio
    │   ├── parche_emscripten.js # Inyector para sincronización de E/S en tiempo real
    │   └── generate_temp_sfx.js # Utilidad de audio SFX
    │
    └── temp/                # Archivos generados y ejecutables de compilación
        ├── CastleCat.exe    # Binario nativo para consola Windows
        ├── index.html       # Interfaz WebAssembly con terminal ANSI
        ├── index.js         # Runtime JavaScript de Emscripten
        └── index.wasm       # Binario WebAssembly
```

---

## ⚙️ Cómo Compilar y Jugar

### 🌐 1. Versión Web (WebAssembly con Emscripten)

1. Entra en la carpeta `game/` y ejecuta:
   ```cmd
   Compilar.bat
   ```
2. Los archivos compilados se generarán limpiamente en `game/temp/`.
3. Para probar el juego en tu navegador, inicia un servidor local desde la raíz:
   ```bash
   python -m http.server 8080
   # Abre en tu navegador: http://localhost:8080/game/temp/
   ```

### 💻 2. Versión Nativa (Windows)

1. Entra en la carpeta `game/` y ejecuta:
   ```cmd
   Compilar_Nativo.bat
   ```
2. Se generará `game/temp/CastleCat.exe` que podrás jugar directamente en tu consola de Windows.

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

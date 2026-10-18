#include <stdbool.h>

void menuOpciones();
void menuMusica();

/* Título y Creditos */
void tituloJuego(bool info)
{
    printf("\n\033[1;44m     \033[0m \033[1;44m  _  \033[0m \033[1;44m   __\033[0m \033[1;44m_   _\033[0m \033[1;44m  \033[0m    \033[1;44m   __\033[0m    \033[1;44m     \033[0m \033[1;44m  _  \033[0m \033[1;44m_   _\033[0m \n");
    printf("\033[1;44m   --\033[0m \033[1;44m     \033[0m \033[1;44m__   \033[0m   \033[1;44m \033[0m   \033[1;44m  \033[0m    \033[1;44m   __\033[0m    \033[1;44m   --\033[0m \033[1;44m     \033[0m   \033[1;44m \033[0m   \n");
    printf("\033[1;44m_____\033[0m \033[1;44m__|__\033[0m \033[1;44m_____\033[0m   \033[1;44m_\033[0m   \033[1;44m_____\033[0m \033[1;44m_____\033[0m    \033[1;44m_____\033[0m \033[1;44m__|__\033[0m   \033[1;44m_\033[0m   \n\n");

    if(info == true)
    {
        printf("CASTLE CAT, un lugar donde la fantasía y la aventura se abren camino en el interior de las mazmorras,\n"); 
        printf("donde solo los mejores héroes son capaces de sobrevivir. Sino eres el más fuerte entonces mueres.\n");   
        printf("Basado en los RPG's de los (70's) creado por Angel Roig, Pau Cremades y José Fernando Pérez.\n\n");
    }
    
}

/* Sale del Juego */
void salirJuego()
{
    limpiarPantalla();
    exit(0); // Cerrar el programa
}

/* Controles del Juego */
void controlesJuego()
{
    limpiarPantalla();

    printf("\033[1;34m╔═════════════════╗\n");
    printf("║    CONTROLES    ║\n");
    printf("╚═════════════════╝\033[0m\n");

   printf("\033[1mObjetivo:\033[0m\n");
    printf("- Derrotar al 'Shadow Meow' y rescatar a tu amada.\n\n");

    printf("\033[1mMecánicas:\033[0m\n");
    printf("- Usa ataques según tu clase y estadísticas:\n");
    printf("  \033[36mFuerza:\033[0m Daño físico. \n  \033[36mInteligencia:\033[0m Daño mágico.\n");
    printf("  \033[36mAgilidad:\033[0m Daño en ataques sorpresa.\n\n");

    printf("\033[1mMapa:\033[0m\n");
    printf("- El 'Castle Cat' tiene 3 plantas de 1, 3 y 5 etapas sucesivamente.\n");
    printf("- Cada planta termina en un jefe.\n");
    printf("- ¡Equipate Usando el \033[35mInventario\033[0m!\n\n");

    printf("\033[1mHabitaciones:\033[0m\n");
    printf("- \033[31mEnemigos [E]\033[0m  \033[33mTesoros [T]\033[0m  Bosses [S]\n\n");

    printf("\033[1mAdvertencia:\033[0m\n");
    printf("- \033[31mSi tu vida llega a 0, la partida acaba. ♥\033[0m \n");

    enterContinuar();
}

/* Creditos del Juego */
void creditosJuego()
{
    limpiarPantalla();

    printf("\033[1;35m╔════════════════╗\n");
    printf("║    CREDITOS    ║\n");
    printf("╚════════════════╝\033[0m\n");
    printf("\033[1mCreado y programado por:\n\033[0m");
    printP("- \033[1;33mETERNODEV\033[0m\n");
    printP("- \033[1;36mBLUELLAMA\033[0m\n\n");
    
    printf("\033[1mAgradecimientos:\n\033[0m");
    printf("- José Fernando Pérez\n");
    printf("- ChatGPT y \033[1;34mAntigravity\033[0m\n\n");

    printf("\033[1mLenguaje utilizado:\033[0m\n");
    printf("- C\n\n");

    printf("\033[1mIdioma del Juego:\033[0m\n");
    printf("- Español\n\n");

    printf("\033[1mPlataformas:\033[0m\n");
    printf("- Windows\n");
    printf("- Linux\n\n");

    printf("\033[1mCreado:\033[0m 12/2024\n");
    printf("Alicante (España)\n");

    printf("\033[1mCastleCat (C)\n");

    enterContinuar();
}

/* Menu de Opciones */
void menuOpciones()
{
    bool enMenu = true;
    static int volumenGlobal = 50;
    static int volumenSFX = 50;
    static int filtroRetro = 0;
    static int filtroAnimado = 0;
    int opcion = 0; // 0 = Musica, 1 = SFX, 2 = Filtro Retro, 3 = Lineas Animadas, 4 = Guardar y Salir

    #ifdef __EMSCRIPTEN__
    // Sincronizar con el estado web al entrar
    int curBgm = EM_ASM_INT({
        var audio = document.getElementById('bgm');
        if (audio) {
            if (audio.muted) return 0;
            return Math.round(audio.volume * 100);
        }
        return 50;
    });
    int curSfx = EM_ASM_INT({
        if (typeof window !== 'undefined' && typeof window.sfxVolume === 'number') {
            if (window.sfxMuted) return 0;
            return Math.round(window.sfxVolume * 100);
        }
        return 50;
    });
    int curRetro = EM_ASM_INT({
        return (typeof isRetroFilterEnabled === 'function' && isRetroFilterEnabled()) ? 1 : 0;
    });
    int curAnim = EM_ASM_INT({
        return (typeof isRetroAnimationEnabled === 'function' && isRetroAnimationEnabled()) ? 1 : 0;
    });
    volumenGlobal = (curBgm / 10) * 10;
    volumenSFX = (curSfx / 10) * 10;
    filtroRetro = curRetro;
    filtroAnimado = curAnim;
    #endif

    while (enMenu)
    {
        limpiarPantalla();
        printf("\033[1;36m╔═════════════════════╗\n");
        printf("║      OPCIONES       ║\n");
        printf("╚═════════════════════╝\033[0m\n\n");
        
        // 0: Volumen Música
        if (opcion == 0) {
            printf("\033[1;37m> \033[1;31mVolumen Música:\033[0m     [");
        } else {
            printf("  \033[1;37mVolumen Música:\033[0m     [");
        }
        for (int i = 0; i < 10; i++) {
            if (i < volumenGlobal / 10) {
                printf("\033[1;32m|\033[0m");
            } else {
                printf("\033[1;30m|\033[0m");
            }
        }
        printf("] %d%%\n\n", volumenGlobal);

        // 1: Volumen Efectos
        if (opcion == 1) {
            printf("\033[1;37m> \033[1;31mVolumen Efectos:\033[0m    [");
        } else {
            printf("  \033[1;37mVolumen Efectos:\033[0m    [");
        }
        for (int i = 0; i < 10; i++) {
            if (i < volumenSFX / 10) {
                printf("\033[1;32m|\033[0m");
            } else {
                printf("\033[1;30m|\033[0m");
            }
        }
        printf("] %d%%\n\n", volumenSFX);

        // 2: Filtro Retro CRT
        if (opcion == 2) {
            printf("\033[1;37m> \033[1;31mFiltro Retro (CRT):\033[0m [");
        } else {
            printf("  \033[1;37mFiltro Retro (CRT):\033[0m [");
        }
        if (filtroRetro) {
            printf("\033[1;32m ACTIVADO \033[0m]\n\n");
        } else {
            printf("\033[1;30mDESACTIVADO\033[0m]\n\n");
        }

        // 3: Líneas Animadas
        if (opcion == 3) {
            printf("\033[1;37m> \033[1;31mLíneas Animadas:\033[0m    [");
        } else {
            printf("  \033[1;37mLíneas Animadas:\033[0m    [");
        }
        if (filtroAnimado && filtroRetro) {
            printf("\033[1;32m ACTIVADO \033[0m]\n\n");
        } else {
            printf("\033[1;30mDESACTIVADO\033[0m]\n\n");
        }

        // 4: Guardar y Salir
        if (opcion == 4) {
            printf("\033[1;37m> \033[1;31mGuardar y Volver\033[0m\n\n");
        } else {
            printf("  \033[1;37mGuardar y Volver\033[0m\n\n");
        }
        
        printf("\033[1mDetalles:\033[0m\n");
        printf(" Pista 8-bits retro creada por \033[1;36mBLUELLAMA\033[0m.\n");
        printf(" Efectos de sonido creados por \033[1;33mETERNODEV\033[0m.\n");
        printf(" Filtro visual CRT animado inspirado en monitores arcade retro.\n");
        printP("\nUsa \033[40m← / →\033[0;1;37m para regular o cambiar. Pulsa \033[40mENTER\033[0;1;37m o \033[40mESC\033[0;1;37m para salir.\n");

        int tecla = getch();

        if (tecla == 224) 
        {
            tecla = getch();
            if (tecla == 72) { // Up
                if (opcion > 0) { opcion--; reproducirSonido("next_option"); }
            } else if (tecla == 80) { // Down
                if (opcion < 4) { opcion++; reproducirSonido("next_option"); }
            } else if (tecla == 77) { // Right
                if (opcion == 0) {
                    if (volumenGlobal < 100) volumenGlobal += 10;
                    reproducirSonido("volume");
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setWebVolume === 'function') setWebVolume($0 / 100.0); }, volumenGlobal);
                    #endif
                } else if (opcion == 1) {
                    if (volumenSFX < 100) volumenSFX += 10;
                    reproducirSonido("volume");
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof window !== 'undefined') window.sfxVolume = $0 / 100.0; }, volumenSFX);
                    #endif
                } else if (opcion == 2) {
                    filtroRetro = !filtroRetro;
                    reproducirSonido("confirm");
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter($0); }, filtroRetro);
                    #endif
                } else if (opcion == 3) {
                    filtroAnimado = !filtroAnimado;
                    if (filtroAnimado && !filtroRetro) {
                        filtroRetro = 1;
                        #ifdef __EMSCRIPTEN__
                        EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter(1); });
                        #endif
                    }
                    reproducirSonido("confirm");
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setRetroAnimation === 'function') setRetroAnimation($0); }, filtroAnimado);
                    #endif
                }
            } else if (tecla == 75) { // Left
                if (opcion == 0) {
                    if (volumenGlobal > 0) volumenGlobal -= 10;
                    reproducirSonido("volume");
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setWebVolume === 'function') setWebVolume($0 / 100.0); }, volumenGlobal);
                    #endif
                } else if (opcion == 1) {
                    if (volumenSFX > 0) volumenSFX -= 10;
                    reproducirSonido("volume");
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof window !== 'undefined') window.sfxVolume = $0 / 100.0; }, volumenSFX);
                    #endif
                } else if (opcion == 2) {
                    filtroRetro = !filtroRetro;
                    reproducirSonido("confirm");
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter($0); }, filtroRetro);
                    #endif
                } else if (opcion == 3) {
                    filtroAnimado = !filtroAnimado;
                    if (filtroAnimado && !filtroRetro) {
                        filtroRetro = 1;
                        #ifdef __EMSCRIPTEN__
                        EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter(1); });
                        #endif
                    }
                    reproducirSonido("confirm");
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setRetroAnimation === 'function') setRetroAnimation($0); }, filtroAnimado);
                    #endif
                }
            }
        }
        else if (tecla == 'w' || tecla == 'W') 
        {
            if (opcion > 0) { opcion--; reproducirSonido("next_option"); }
        }
        else if (tecla == 's' || tecla == 'S') 
        {
            if (opcion < 4) { opcion++; reproducirSonido("next_option"); }
        }
        else if (tecla == 'd' || tecla == 'D') 
        {
            if (opcion == 0) {
                if (volumenGlobal < 100) volumenGlobal += 10;
                reproducirSonido("volume");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setWebVolume === 'function') setWebVolume($0 / 100.0); }, volumenGlobal);
                #endif
            } else if (opcion == 1) {
                if (volumenSFX < 100) volumenSFX += 10;
                reproducirSonido("volume");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof window !== 'undefined') window.sfxVolume = $0 / 100.0; }, volumenSFX);
                #endif
            } else if (opcion == 2) {
                filtroRetro = !filtroRetro;
                reproducirSonido("confirm");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter($0); }, filtroRetro);
                #endif
            } else if (opcion == 3) {
                filtroAnimado = !filtroAnimado;
                if (filtroAnimado && !filtroRetro) {
                    filtroRetro = 1;
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter(1); });
                    #endif
                }
                reproducirSonido("confirm");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setRetroAnimation === 'function') setRetroAnimation($0); }, filtroAnimado);
                #endif
            }
        }
        else if (tecla == 'a' || tecla == 'A') 
        {
            if (opcion == 0) {
                if (volumenGlobal > 0) volumenGlobal -= 10;
                reproducirSonido("volume");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setWebVolume === 'function') setWebVolume($0 / 100.0); }, volumenGlobal);
                #endif
            } else if (opcion == 1) {
                if (volumenSFX > 0) volumenSFX -= 10;
                reproducirSonido("volume");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof window !== 'undefined') window.sfxVolume = $0 / 100.0; }, volumenSFX);
                #endif
            } else if (opcion == 2) {
                filtroRetro = !filtroRetro;
                reproducirSonido("confirm");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter($0); }, filtroRetro);
                #endif
            } else if (opcion == 3) {
                filtroAnimado = !filtroAnimado;
                if (filtroAnimado && !filtroRetro) {
                    filtroRetro = 1;
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter(1); });
                    #endif
                }
                reproducirSonido("confirm");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setRetroAnimation === 'function') setRetroAnimation($0); }, filtroAnimado);
                #endif
            }
        }
        else if (tecla == ' ')
        {
            if (opcion == 2) {
                filtroRetro = !filtroRetro;
                reproducirSonido("confirm");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter($0); }, filtroRetro);
                #endif
            } else if (opcion == 3) {
                filtroAnimado = !filtroAnimado;
                if (filtroAnimado && !filtroRetro) {
                    filtroRetro = 1;
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter(1); });
                    #endif
                }
                reproducirSonido("confirm");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setRetroAnimation === 'function') setRetroAnimation($0); }, filtroAnimado);
                #endif
            }
        }
        else if (tecla == 13 || tecla == 10) 
        {
            if (opcion == 2) {
                filtroRetro = !filtroRetro;
                reproducirSonido("confirm");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter($0); }, filtroRetro);
                #endif
            } else if (opcion == 3) {
                filtroAnimado = !filtroAnimado;
                if (filtroAnimado && !filtroRetro) {
                    filtroRetro = 1;
                    #ifdef __EMSCRIPTEN__
                    EM_ASM({ if (typeof setRetroFilter === 'function') setRetroFilter(1); });
                    #endif
                }
                reproducirSonido("confirm");
                #ifdef __EMSCRIPTEN__
                EM_ASM({ if (typeof setRetroAnimation === 'function') setRetroAnimation($0); }, filtroAnimado);
                #endif
            } else {
                reproducirSonido("confirm");
                enMenu = false;
            }
        }
        else if (tecla == 9 || tecla == 27) 
        {
            reproducirSonido("confirm");
            enMenu = false;
        }
    }
}

void menuMusica()
{
    menuOpciones();
}

/* Menu del Juego */
int menuIntro()
{
    int opcion = 0;

    while (1)
    {
        int totalOpciones;
        const char *opciones[6];

        if (g_hayPartida) {
            opciones[0] = "CONTINUAR";
            opciones[1] = "NUEVA PARTIDA";
            opciones[2] = "CONTROLES";
            opciones[3] = "RÉCORDS";
            opciones[4] = "CREDITOS";
            opciones[5] = "OPCIONES";
            totalOpciones = 6;
        } else {
            opciones[0] = "JUGAR";
            opciones[1] = "CONTROLES";
            opciones[2] = "RÉCORDS";
            opciones[3] = "CREDITOS";
            opciones[4] = "OPCIONES";
            totalOpciones = 5;
        }

        if (opcion >= totalOpciones) opcion = 0;

        limpiarPantalla();
        tituloJuego(true);

        // Dibujar opciones
        for (int i = 0; i < totalOpciones; i++)
        {
            if (i == opcion)
            {
                // Opción resaltada en rojo
                printf(" > \033[1;31m%s\033[0m\n", opciones[i]);
            }
            else
            {
                printf("   %s\n", opciones[i]);
            }
        }

        // Leer tecla
        int tecla = getch();

        if (tecla == 224) // Flechas en Windows envían 224 primero
        {
            tecla = getch();
            if (tecla == 72) // Flecha arriba
            {
                opcion = (opcion - 1 + totalOpciones) % totalOpciones;
                reproducirSonido("next_option");
            }
            else if (tecla == 80) // Flecha abajo
            {
                opcion = (opcion + 1) % totalOpciones;
                reproducirSonido("next_option");
            }
        }
        else if (tecla == 'w' || tecla == 'W') // W para subir
        {
            opcion = (opcion - 1 + totalOpciones) % totalOpciones;
            reproducirSonido("next_option");
        }
        else if (tecla == 's' || tecla == 'S') // S para bajar
        {
            opcion = (opcion + 1) % totalOpciones;
            reproducirSonido("next_option");
        }
        else if (tecla == 13 || tecla == 10) // Enter
        {
            reproducirSonido("confirm");
            limpiarPantalla();

            if (g_hayPartida) {
                if (opcion == 0) {
                    // CONTINUAR
                    printP("\033[1m\033[32mReanudando Partida...\033[0m\n");
                    #ifdef __EMSCRIPTEN__
                    emscripten_sleep(400);
                    #elif defined(_WIN32)
                    Sleep(400);
                    #endif
                    limpiarPantalla();
                    return 1;
                } else if (opcion == 1) {
                    // NUEVA PARTIDA
                    printP("\033[1m\033[31mIniciando Nueva Partida...\033[0m\n");
                    return 2;
                } else if (opcion == 2) {
                    printP("\033[1m\033[31mCargando...\033[0m\n");
                    controlesJuego();
                } else if (opcion == 3) {
                    printP("\033[1m\033[31mCargando Récords...\033[0m\n");
                    mostrarRecords();
                } else if (opcion == 4) {
                    printP("\033[1m\033[31mCargando...\033[0m\n");
                    creditosJuego();
                } else if (opcion == 5) {
                    printP("\033[1m\033[31mCargando Opciones...\033[0m\n");
                    menuOpciones();
                }
            } else {
                if (opcion == 0) {
                    // JUGAR
                    printP("\033[1m\033[31mCargando Juego...\033[0m\n");
                    return 2;
                } else if (opcion == 1) {
                    printP("\033[1m\033[31mCargando...\033[0m\n");
                    controlesJuego();
                } else if (opcion == 2) {
                    printP("\033[1m\033[31mCargando Récords...\033[0m\n");
                    mostrarRecords();
                } else if (opcion == 3) {
                    printP("\033[1m\033[31mCargando...\033[0m\n");
                    creditosJuego();
                } else if (opcion == 4) {
                    printP("\033[1m\033[31mCargando Opciones...\033[0m\n");
                    menuOpciones();
                }
            }
        }
    }
}

/* Dibujo Castillo Portada */
void dibujoCastillo()
{
    printf("                                       o         _ _ _ _ _\n");
    printf("                                  _----|         I-I-I-I-I\n");
    printf("               _ _ _ _ _ _      o  ----|     o   \\~~`~'~~/\n");
    printf("               ]-I-I-I-I-[ _----|      |_----|    |.    |\n");
    printf("               \\~`\\~~~/'~/  ----|     / \\----|    |  /^\\|\n");
    printf("                [*] ' __|       ^    / ^ \\   ^    |_ |*||\n");
    printf("                |__    ,|      / \\  /    `\\ / \\   |  ===|\n");
    printf("              __|  ___ ,|__   /    /=_=_=_=\\   \\  |,  __|\n");
    printf("              I_I__I_I__I_I  (====(_________)___|_|_____|___\n");
    printf("              \\-\\--|-|--/-/  |'    I~~[ ]~~I I_I__|IIII|_I_l\n");
    printf("               | [ ]    '|   | [~] |_`_~_ _[  \\-\\--|-|--/-/\n");
    printf("               |.   | |' |___|____`I_I_|_I_I___|---------|\n");
    printf("               / \\| [] ~ .|_|-|_|-|-|_|-|_|-|_|-| []   [] |\n");
    printf("              <===>  |  ~.|-=-=-=-=-=-=-=-=-=-=-|~  |  ~ / \\\n");
    printf("              | []|`   []~||.|.|.|.|.|.|.|.|.||-~   ~   <===>\n");
    printf("              | []| ` |   |/////////I\\\\\\\\\\\\||__.  ~|    |[*]I\n");
    printf("              <===> ~   ' ||||| |   |   | ||||.||  []  ~<===>\n");
    printf("               \\T/  |~|-- ||||| | O | O | ||||.|| . |'~  \\T/\n");
    printf("                |     ~.~_||||| |~~~|~~~| ||||.|| | ~   | |\n");
    printf("               /|' v . | .|||||/____|____\\|||| /|. . | . .|\\\n\n"); 
}

/* Se introduce el Nombre del Jugador */
void nombreGatoJugador(char *nombreJugador)
{
    tituloJuego(false); // Título del Juego
    
    printf("\033[1mIntroduce el nombre\033[0m de tu \033[1m\033[31mgato\033[0m:\n");
    int i = 0;
    int c;

    printf("- ");
    fflush(stdout);

    while (1)
    {
        c = getch();

        if (c == 13) // Enter
        {
            if (i > 0) // Al menos un caracter
            {
                nombreJugador[i] = '\0';
                reproducirSonido("confirm");
                break;
            }
        }
        else if (c == 8 || c == 127) // Backspace (8) o Delete (127)
        {
            if (i > 0)
            {
                i--;
                #ifdef __EMSCRIPTEN__
                // Borrar visualmente con ANSI (Cursor Atrás, Espacio, Cursor Atrás) - Emscripten specific or general
                printf("\b \b"); 
                #else
                printf("\b \b");
                #endif
                fflush(stdout);
            }
        }
        else if (c == 224) // Teclas especiales
        {
            getch(); // Ignorar
        }
        else if (i < 20 && c >= 32 && c <= 126) // Caracteres imprimibles
        {
            nombreJugador[i] = c;
            i++;
            printf("%c", c);
            fflush(stdout);
        }
    }
    printf("\n");
    printf("\nDebug: Nombre capturado: '%s'\n", nombreJugador);
}

/* Estadísticas y Clases */
void claseJugador(int *jugadorClase, char *nombreJugador)
{
    int opcion = 0;                  // índice actual (0 = Guerrero, 1 = Mago, 2 = Asesino)
    bool claseCorrecta = false;
    const char *clases[] = {
        "Guerrero",
        "Mago",
        "Asesino"
    };
    int totalClases = 3;

    while (!claseCorrecta)
    {
        limpiarPantalla();
        tituloJuego(false);
        
        printf("Nombre: \033[1m\033[31m'%s'\033[0m\n", nombreJugador);

        printf("\n\033[1mElige una Clase:\033[0m\n");
        

        for (int i = 0; i < totalClases; i++)
        {
            if (i == opcion)
            {
                // Resaltar clase actual en rojo
                if (i == 0) printf(" > \033[1m\033[35mGuerrero\033[0m \033[1m♥ Vida[13] \033[36m✦ Mana[3]  \033[31mψ Ataque [2] \033[34m★ Mágia [1] \033[32m➹ Agilidad [1]\033[0m\n");
                if (i == 1) printf(" > \033[1m\033[34mMago\033[0m     \033[1m♥ Vida[10] \033[36m✦ Mana[10] \033[31mψ Ataque [2] \033[34m★ Mágia [3] \033[32m➹ Agilidad [1]\033[0m\n");
                if (i == 2) printf(" > \033[1m\033[31mAsesino\033[0m  \033[1m♥ Vida[11] \033[36m✦ Mana[5]  \033[31mψ Ataque [2] \033[34m★ Mágia [1] \033[32m➹ Agilidad [3]\033[0m\n");
            }
            else
            {
                // Clases normales sin resaltar
                if (i == 0) printf("   \033[1;37mGuerrero\033[0m \033[1;37m♥ Vida[13] ✦ Mana[3] ψ Ataque [2] ★ Magia [1] ➹ Agilidad [1]\033[0m\n");
                if (i == 1) printf("   \033[1;37mMago\033[0m     \033[1;37m♥ Vida[10] ✦ Mana[10] ψ Ataque [2] ★ Magia [3] ➹ Agilidad [1]\033[0m\n");
                if (i == 2) printf("   \033[1;37mAsesino\033[0m  \033[1;37m♥ Vida[11] ✦ Mana[5] ψ Ataque [2] ★ Magia [1] ➹ Agilidad [3]\033[0m\n");

            }
        }

        // Leer tecla
        int tecla = getch();

        if (tecla == 224) // Flechas en Windows envían 224 primero
        {
            tecla = getch();
            if (tecla == 72) // Flecha arriba
            {
                opcion = (opcion - 1 + totalClases) % totalClases;
                reproducirSonido("next_option");
            }
            else if (tecla == 80) // Flecha abajo
            {
                opcion = (opcion + 1) % totalClases;
                reproducirSonido("next_option");
            }
        }
        else if (tecla == 'w' || tecla == 'W') // W para subir
        {
            opcion = (opcion - 1 + totalClases) % totalClases;
            reproducirSonido("next_option");
        }
        else if (tecla == 's' || tecla == 'S') // S para bajar
        {
            opcion = (opcion + 1) % totalClases;
            reproducirSonido("next_option");
        }
        else if (tecla == 13) // Enter
        {
            reproducirSonido("confirm");
            switch (opcion)
            {
                case 0:
                    printf("\nEres un \033[1m\033[35mGuerrero\033[0m\n");
                    *jugadorClase = 0;
                    claseCorrecta = true;
                    break;

                case 1:
                    printf("\nEres un \033[1m\033[34mMago\033[0m\n");
                    *jugadorClase = 1;
                    claseCorrecta = true;
                    break;

                case 2:
                    printf("\nEres un \033[1m\033[31mAsesino\033[0m\n");
                    *jugadorClase = 2;
                    claseCorrecta = true;
                    break;
            }
            // waitForEnter(); // Removed redundant wait
            enterContinuar();
        }
    }
}

/* Recoge toda la introducción del juego */
void introHistoriaJuego(char *nombreJugador, int *jugadorClase)
{  
    /* Limpia la Consola */
    limpiarPantalla();
    
    /* Se introduce el nombre del Jugador */
    nombreGatoJugador(nombreJugador);
    
    /* Se introduce la clase Jugador */
    claseJugador(jugadorClase, nombreJugador);
    
    tituloJuego(false);

    /* Se Narra la Historia Inicial */
    /*printR("\n\033[1m- En el reino de \033[34m'Nekovania'\033[0m, algunos ciudadanos desaparecen sin dejar rastro.\033[0m\n");
    printR("Habla la leyenda de un\033[33m dragón colosal\033[0m, \033[1mel \033[35m'Shadow Meow'\033[0m\033[1m, que ha vencido grandes héroes.\n");
    printR("Desde su castillo, el\033[33m Castle Cat\033[0m, secuestra a los inocentes.\n\n");

    printR("\033[1mEn los \033[34msuburbios\033[0m, un joven\033[1m\033[34m felino\033[0m, llamado ");
    
    char name_buffer[256];
    sprintf(name_buffer, "\033[1m\033[31m'%s'\033[0m, ", nombreJugador);
    printR(name_buffer);
    
    printR("decide enfrentar la mazmorra.\n");
    printR("\033[1mCon el único objetivo de \033[33msalvar a su amada\033[0m del \033[35mtemible dragón.\033[0m\n\n");

    printP("\033[1m¿Podrá sobrevivir en el castillo?\033[0m\n\n");*/

    /* Se Dibuja el Castillo */
    dibujoCastillo();

    printP("\033[1m¡\033[31mLa aventura comienza ahora\033[0m\033[1m!\033[0m\n");

    
    /* Se Pulsa Enter para Comezar la Aventura */
    enterContinuar();


}

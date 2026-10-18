#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "ComandosBasicos.c"
#include "Intro.c"
#include "FinDelJuego.c"
#include "Mapa.c"
#include "Habilidades.c"
#include "Combate.c"
#include "Infor.c"
#include "ObjetosyTesoros.c"
#include "Enemigos.c"

/* Struct Estadisticas Jugador */
typedef struct
{
    int hp;
    int hpMax;

    int mp;
    int mpMax;
    
    int fueJugador;
    int intJugador;
    int agiJugador;
    int defJugador;

    int armaInicialJugador;
}TJugador;

/* Inicializa Estadisticas Jugador */
void inicializaJugador(TJugador statsJugador[])
{
    
    /*Stats Guerrero Inicio*/
    //Vida
    statsJugador[0].hpMax = 13;
    statsJugador[0].hp = statsJugador[0].hpMax;

    statsJugador[0].mpMax = 3;
    statsJugador[0].mp = statsJugador[0].hpMax;
    
    //Estadisticas Básicas
    statsJugador[0].fueJugador = 2;
    statsJugador[0].intJugador = 1;
    statsJugador[0].agiJugador = 1;
    statsJugador[0].defJugador = 2;

    statsJugador[0].armaInicialJugador = 5;
    
    
    
    /*Stats Mago Inicia*/
    //Vida
    statsJugador[1].hpMax = 10;
    statsJugador[1].hp = statsJugador[1].hpMax;

    statsJugador[1].mpMax = 10;
    statsJugador[1].mp = statsJugador[0].hpMax;
    
    //Estadisticas Básicas
    statsJugador[1].fueJugador = 2;
    statsJugador[1].intJugador = 3;
    statsJugador[1].agiJugador = 1;
    statsJugador[1].defJugador = 1;


    statsJugador[1].armaInicialJugador = 6;
    
    
    /*Stats Asesino Inicio*/
    //Vida
    statsJugador[2].hpMax = 11;
    statsJugador[2].hp = statsJugador[2].hpMax;

    statsJugador[2].mpMax = 5;
    statsJugador[2].mp = statsJugador[0].hpMax;
    
    //Estadisticas Básicas
    statsJugador[2].fueJugador = 2;
    statsJugador[2].intJugador = 1;
    statsJugador[2].agiJugador = 3;  
    statsJugador[2].defJugador = 1;

    statsJugador[2].armaInicialJugador = 7; 
}

int main()
{
    //Estadisticas Objetos Español
    int i, plantaCastillo = 1, entradaPlanta = 1, itemUsado;
    int itemHp, itemHpMax, itemFue, itemInt, itemAgi;

    
    //Idioma Español
    //Idioma Español
    setlocale(LC_ALL, "es_ES.UTF-8");
    
    // Disable buffering for Emscripten
    setvbuf(stdout, NULL, _IONBF, 0);

    // Initialize input system (for Emscripten)
    init_input();

    //NombreJugador (21 Letras)
    char nomJugador[21] = "";
    
    //Clase: Guerrero = 0, Mago = 1, Asesino = 2
    int claseJugador = 0; 
    
    //Inizializa Jugador según su Clase e Items del Juego
    TJugador statsJugador[3];
    TItem statsItem[26];
    definirItems(statsItem);
    inicializaJugador(statsJugador);

    //Random
    srand(time(NULL));

    //Estadisticas del Jugador
    int hpEne, hpMaxEne, hp, hpMax, mp, mpMax, ataqueEne; 
    int atkIn = statsJugador[claseJugador].fueJugador;
    int atkMagIn = statsJugador[claseJugador].intJugador;
    int agiIn = statsJugador[claseJugador].agiJugador;
    int defIn = statsJugador[claseJugador].defJugador;

    int atk = 0;
    int atkMag = 0;
    int agi= 0;
    int def = 0;

    hpMax = statsJugador[claseJugador].hpMax;
    hp = hpMax;

    mpMax = statsJugador[claseJugador].mpMax;
    mp = mpMax;

    //Enemigos
    char enemigoImagen[2000], enemigoNombre[100];

    //Habitaciones y Mapa
    int tipoHabitacion = 3, finEvento = 0, ok = 0;
    int fase = 1, cambioPlanta = 1;

    int map[7][7] = {
        {6,6,6,6,6,6,6},
        {6,0,0,0,0,0,6},
        {6,0,0,0,0,0,6},
        {6,0,0,0,0,0,6},
        {6,0,0,0,0,0,6},
        {6,0,0,0,0,0,6},
        {6,6,6,6,6,6,6}
    };

    int x, y;

    int posicion[7][7] = {
        {0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };

    int stat[4] = {atkIn, atkMagIn, agiIn, defIn};
    int statIn[4] = {atk, atkMag, agi, def};
    int enemigosFase = 1;


    char arma1[50], arma2[50];
    int skill[3] = {0,0,0};
    int turno = 0;
    
    /* BUCLE PRINCIPAL DEL JUEGO CON MENÚ Y GUARDADO */
    while (1)
    {
        setModoJuego(0);
        int accion = menuIntro();

        if (accion == 2) // JUGAR o NUEVA PARTIDA
        {
            // Resetear estado completo
            definirItems(statsItem);
            inicializaJugador(statsJugador);

            plantaCastillo = 1;
            entradaPlanta = 1;
            fase = 1;
            cambioPlanta = 1;
            ok = 0;
            finEvento = 0;
            turno = 0;
            g_solicitarMenu = 0;

            arma1[0] = '\0';
            arma2[0] = '\0';
            skill[0] = 0; skill[1] = 0; skill[2] = 0;
            g_enemigosDerrotados = 0;
            g_tesorosAbiertos = 0;

            // Reiniciar mapa base
            for (int r = 0; r < 7; r++) {
                for (int c = 0; c < 7; c++) {
                    if (r == 0 || r == 6 || c == 0 || c == 6) map[r][c] = 6;
                    else map[r][c] = 0;
                    posicion[r][c] = 0;
                }
            }
            posicion[1][1] = 1;

            // Intro del juego y creación de personaje
            introHistoriaJuego(nomJugador, &claseJugador);

            // Cargar estadísticas iniciales según clase
            atkIn = statsJugador[claseJugador].fueJugador;
            atkMagIn = statsJugador[claseJugador].intJugador;
            agiIn = statsJugador[claseJugador].agiJugador;
            defIn = statsJugador[claseJugador].defJugador;

            atk = 0;
            atkMag = 0;
            agi = 0;
            def = 0;

            hpMax = statsJugador[claseJugador].hpMax;
            hp = hpMax;

            mpMax = statsJugador[claseJugador].mpMax;
            mp = mpMax;

            stat[0] = atkIn; stat[1] = atkMagIn; stat[2] = agiIn; stat[3] = defIn;
            statIn[0] = atk; statIn[1] = atkMag; statIn[2] = agi; statIn[3] = def;

            g_hayPartida = 1;
        }
        else if (accion == 1) // CONTINUAR
        {
            g_solicitarMenu = 0;
            limpiarPantalla();
            // No reseteamos nada, se reanuda la partida con el estado actual
        }

        // Bucle de juego de la partida activa
        setModoJuego(1);
        setModoMenuTab(0);
        while (ok == 0 && g_solicitarMenu == 0)
        {
            if(plantaCastillo == 1)
            {
                if(entradaPlanta == 1)
                    tituloPlantaDungeon(1, &entradaPlanta);
                fase = 1;
            }

            if(plantaCastillo > 1 && plantaCastillo < 5)
            {
                if(entradaPlanta == 0)
                    tituloPlantaDungeon(2, &entradaPlanta);
                fase = 2;
            }

            if(plantaCastillo > 4)
            {
                if(entradaPlanta == 1)
                    tituloPlantaDungeon(3, &entradaPlanta);
                fase = 3;
            }

            // Generador de Habitaciones Aleatorias
            if(cambioPlanta == 1)
            {
                for(x = 1; x < 6; x++)
                {
                    for(y = 1; y < 6; y++)
                    {
                        map[x][y] = 0;
                    }
                }
                generarHabitaciones(map);

                posicion[5][5] = 0;
                posicion[1][1] = 1;
                cambioPlanta = 0;
            }
            
            // Movimiento en el Mapa (solo si no estamos en medio de un evento)
            if (finEvento == 0)
            {
                limpiarPantalla();
                do
                {
                    stat[0] = atkIn;
                    stat[1] = atkMagIn;
                    stat[2] = agiIn;
                    stat[3] = defIn;
                    actualizarStatsEquipo(&atkIn, &atkMagIn, &agiIn, &defIn, statsItem, skill, arma1, arma2, &atk, &atkMag, &agi, &def);
                    statIn[0] = atk;
                    statIn[1] = atkMag;
                    statIn[2] = agi;
                    statIn[3] = def;

                    mostrarMapa(map, posicion, &tipoHabitacion);
                    
                    if (g_solicitarMenu) {
                        break;
                    }

                    if (tipoHabitacion == 0) {
                        limpiarPantalla();
                    }
                } while (tipoHabitacion == 0);

                if (g_solicitarMenu) {
                    g_hayPartida = 1;
                    break;
                }

                // Se encuentra un Evento (Enemigo o Tesoro)
                finEvento = 1;
                evento();
                turno = 0;
            }

            // Se resuelve el Evento (Combate o Tesoro)
            while (finEvento == 1 && g_solicitarMenu == 0)
            {
                // Se encuentra un Enemigo
                if (tipoHabitacion == 1)
                {
                    if(turno == 0)
                    {
                        if(fase == 1) enemigosFase = 1;
                        if(fase == 2) enemigosFase = 4;
                        if(fase == 3) enemigosFase = 7;

                        escogerEnemigo(enemigoImagen, enemigoNombre, rand() % 3 + enemigosFase, &hpMaxEne, &ataqueEne);
                        hpEne = hpMaxEne;
                    }

                    combate(&hp, &hpEne, &hpMaxEne, &hpMax, &mp, &mpMax, ataqueEne, atk, atkMag, agi, def, skill, stat, enemigoImagen, enemigoNombre, claseJugador, nomJugador);
                    if (g_solicitarMenu) break;
                    turno++;

                    if (hpEne <= 0)
                    {
                        hpEne = 0;
                        finEvento = 0;
                        vaciarHabitacion(map, posicion);
                        turno = 0;
                        g_enemigosDerrotados++;
                    }
                    if (hp <= 0) {
                        hp = 0;
                        ok = 1;
                        finEvento = 0;
                        g_hayPartida = 0;
                        vaciarHabitacion(map, posicion);
                        muerteJugador(nomJugador, claseJugador, plantaCastillo);
                        break;
                    }
                }

                // Se encuentra un Tesoro
                if (tipoHabitacion == 2)
                {
                    habitacionTesoro(statsItem, fase);
                    vaciarHabitacion(map, posicion);
                    finEvento = 0;
                }

                // Se encuentra un Boss
                if (tipoHabitacion == 3)
                {
                    if(turno == 0)
                    {
                        escogerJefe(enemigoImagen, enemigoNombre, plantaCastillo, &hpMaxEne, &ataqueEne);
                        hpEne = hpMaxEne;
                    }

                    combate(&hp, &hpEne, &hpMaxEne, &hpMax, &mp, &mpMax, ataqueEne, atk, atkMag, agi, def, skill, stat, enemigoImagen, enemigoNombre, claseJugador, nomJugador);
                    if (g_solicitarMenu) break;
                    turno++;

                    if (hpEne <= 0)
                    {
                        hpEne = 0;
                        finEvento = 0;
                        vaciarHabitacion(map, posicion);
                        cambioPlanta = 1;
                        plantaCastillo = plantaCastillo + 1;
                        turno = 0;
                        g_enemigosDerrotados++;

                        if(plantaCastillo == 9)
                        {
                            faseFinalSadowLord();
                        }
                        else if (plantaCastillo > 9)
                        {
                            hp = 0;
                            ok = 1;
                            finEvento = 0;
                            g_hayPartida = 0;
                            vaciarHabitacion(map, posicion);
                            finDelJuego(nomJugador, claseJugador, plantaCastillo, hp);
                            break;
                        }
                    }

                    if (hp <= 0) {
                        hp = 0;
                        ok = 1;
                        finEvento = 0;
                        g_hayPartida = 0;
                        vaciarHabitacion(map, posicion);
                        muerteJugador(nomJugador, claseJugador, plantaCastillo);
                        break;
                    }
                }
            }

            if (g_solicitarMenu) {
                setModoMenuTab(0);
                g_hayPartida = 1;
                break;
            }

            if (ok == 0) {
                setModoMenuTab(0);
                inventarioJugador(statsItem, &hp, &hpMax, &atkIn, &atkMagIn, &agiIn, &defIn, nomJugador);
                setModoMenuTab(0);
                limpiarPantalla();
            }
        }
    }

    return 0;
}
void muerteJugador(char nombreJugador[], int claseJugador, int plantaCastillo)
{
    reproducirSonido("death");
    temblorPantallaMuerte();
    setModoJuego(0);
    setModoNarrativa(1);
    printP("\033[31m!  H A S   M U E R T O  !\033[0m\n\n");
    
    char bufferMuerte[512];
    sprintf(bufferMuerte, "En ese preciso momento \033[1m'%s'\033[0m cayó al suelo, derrotado. Sus fuerzas se desvanecieron mientras la oscuridad lo envolvía.\n\n", nombreJugador);
    printP(bufferMuerte);
    printP("\033[31m\"¿Por qué fui tan débil?\", pensó, sintiendo el peso de sus errores.\033[0m\n");
    printP("El rostro de su amada cruzó por su mente una última vez, y una lágrima silenciosa recorrió su mejilla.\n");

    printP("\033[1m\"Lo siento... No pude salvarte.\"\033[0m\n\n");
    setModoNarrativa(0);

    printP("Pulsa \033[40mENTER\033[0;1;37m para continuar...\n");
    fflush(stdout);
    waitForEnter();
    limpiarPantalla();

    int puntos = calcularPuntuacion(plantaCastillo, 0);
    int puesto = comprobarYGuardarRecord(nombreJugador, claseJugador, plantaCastillo, puntos);

    printf("  \033[1;36m╔═══════════════════════════════════════════╗\033[0m\n");
    printf("  \033[1;36m║           RESUMEN DE LA PARTIDA           ║\033[0m\n");
    printf("  \033[1;36m╚═══════════════════════════════════════════╝\033[0m\n");
    printf("    Planta alcanzada:       \033[1;33m%d\033[0m\n", plantaCastillo);
    printf("    Enemigos derrotados:    \033[1;31m%d\033[0m\n", g_enemigosDerrotados);
    printf("    Tesoros abiertos:       \033[1;32m%d\033[0m\n", g_tesorosAbiertos);
    printf("    ─────────────────────────────────────────\n");
    printf("    \033[1mPUNTUACIÓN TOTAL:\033[0m       \033[1;32m%d pts\033[0m\n", puntos);
    if (puesto > 0) {
        printf("    \033[1;33m★ ¡NUEVO RÉCORD! Entraste al Top %d (#%d) ★\033[0m\n", MAX_RECORDS, puesto);
    }
    printf("  \033[1;36m═══════════════════════════════════════════\033[0m\n");

    printP("\nPulsa \033[40mENTER\033[0;1;37m para volver al menú principal...\n");
    fflush(stdout);
    waitForEnter();

    g_hayPartida = 0;
    g_solicitarMenu = 0;
    limpiarPantalla();
}

void animacionFinal(int *frameAnimacion)
{
    switch(*frameAnimacion)
    {
        case 1:
            printf("\n            *     ,MMM8&&&.            *\n");
            printf("                  MMMM88&&&&&    .\n");
            printf("                 MMMM88&&&&&&&\n");
            printf("     *           MMM88&&&&&&&&\n");
            printf("                 MMM88&&&&&&&&\n");
            printf("                 'MMM88&&&&&&'\n");
            printf("                   'MMM8&&&'      *    \n");
            printf("          |\\___/|     /\\___/\\\n");
            printf("          )     (     )    ~( .              '\n");
            printf("         =\\     /=   =\\~    /=\n");
            printf("           )===(       ) ~ (\n");
            printf("          /     \\     /     \\\n");
            printf("          |     |     ) ~   (\n");
            printf("         /       \\   /     ~ \\\n");
            printf("         \\       /   \\~     ~/ \n");
            printf("  ___/\\_/\\__  _/_/\\_/\\__~__/_/\\_/\\_/\\_/\\_/\\_\n");
            printf("  |  |  |  |( (  |  |  | ))  |  |  |  |  |  |\n");
            printf("  |  |  |  | ) ) |  |  |//|  |  |  |  |  |  |\n");
            printf("  |  |  |  |(_(  |  |  (( |  |  |  |  |  |  |\n");
            printf("  |  |  |  |  |  |  |  |\\)|  |  |  |  |  |  |\n");
            printf("  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n");
        *frameAnimacion = 2;
        break;

        case 2:
            printf("\n            *     ,MMM8&&&.            *\n");
            printf("                  MMMM88&&&&&    .\n");
            printf("                 MMMM88&&&&&&&\n");
            printf("     *           MMM88&&&&&&&&\n");
            printf("                 MMM88&&&&&&&&\n");
            printf("                 'MMM88&&&&&&'\n");
            printf("                   'MMM8&&&'      *\n");
            printf("           /\\/|_      __/\\\\\n");
            printf("          /    -\\    /-   ~\\  .              '\n");
            printf("          \\    = Y =T_ =   /\n");
            printf("           )==*(\\`     `) ~ \\\n");
            printf("          /     \\     /     \\\n");
            printf("          |     |     ) ~   (\n");
            printf("         /       \\   /     ~ \\\n");
            printf("         \\       /   \\~     ~/ \n");
            printf("  ___/\\_/\\__  _/_/\\_/\\__~__/_/\\_/\\_/\\_/\\_/\\_\n");
            printf("  |  |  |  | ) ) |  |  | ((  |  |  |  |  |  |\n");
            printf("  |  |  |  |( (  |  |  |  \\\\ |  |  |  |  |  |\n");
            printf("  |  |  |  | )_) |  |  |  |))|  |  |  |  |  |\n");
            printf("  |  |  |  |  |  |  |  |  (/ |  |  |  |  |  |\n");
            printf("  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n");
        *frameAnimacion=3;
        break;

        case 3:
            printf("\n            *     ,MMM8&&&.            *\n");
            printf("                  MMMM88&&&&&    .\n");
            printf("                 MMMM88&&&&&&&\n");
            printf("     *           MMM88&&&&&&&&\n");
            printf("                 MMM88&&&&&&&&\n");
            printf("                 'MMM88&&&&&&'\n");
            printf("                   'MMM8&&&'      *\n");
            printf("  __ _       \n");
            printf(" / _(_)                      *\n");
            printf("| |_ _ _ __         *\n");
            printf("|  _| | '_ \\  \n");
            printf("| | | | | | |                       *\n");
            printf("|_| |_|_| |_|     *\n\n");

            printP("\033[1m\033[31mGracias por Jugar...\033[0m\n");
            *frameAnimacion = 4;
        break;
    }
}

void finDelJuego(char nombreJugador[], int claseJugador, int plantaCastillo, int hpRestante)
{
    int frameAnimacion = 1, i;

    setModoJuego(0);
    setModoNarrativa(1);
    char bufferFinal[512];
    sprintf(bufferFinal, "\033[1mCon un último golpe certero, \033[34m'%s'\033[0m atravesó el corazón del \033[35m'Shadow Lord'\033[0m.\033[0m\n", nombreJugador);
    printP(bufferFinal);
    printP("El dragón lanzó un rugido desgarrador antes de desplomarse, cubriendo la sala con un silencio sepulcral.\n\n");
    
    printP("Entre los escombros, \033[1muna figura conocida emergió era su amada.\033[0m\n");
    sprintf(bufferFinal, "Ella corrió hacia él, lágrimas en los ojos, mientras \033[34m'%s'\033[0m caía de rodillas, exhausto.\n\n", nombreJugador);
    printP(bufferFinal);
    
    printP("\033[33mLa maldición del 'Castle Cat' había terminado.\033[0m\n");
    printP("Juntos regresaron a \033[31m'Nekovania'\033[0m, donde el pueblo los recibió como héroes.\n\n");
    setModoNarrativa(0);

    for(i = 1; i <= 3; i++)
    {     
        printP("\033[1m\nPresiona \033[33mENTER ♥\033[0m\n");
        waitForEnter();
        // Limpiar la Pantalla
        limpiarPantalla();

        animacionFinal(&frameAnimacion);
    }

    printP("\nPulsa \033[40mENTER\033[0;1;37m para ver el resumen...\n");
    fflush(stdout);
    waitForEnter();
    limpiarPantalla();

    int puntos = calcularPuntuacion(plantaCastillo, hpRestante) + 5000;
    int puesto = comprobarYGuardarRecord(nombreJugador, claseJugador, plantaCastillo, puntos);

    printf("  \033[1;33m╔═══════════════════════════════════════════╗\033[0m\n");
    printf("  \033[1;33m║          ¡VICTORIA COMPLETADA!            ║\033[0m\n");
    printf("  \033[1;33m╚═══════════════════════════════════════════╝\033[0m\n");
    printf("    Enemigos derrotados:    \033[1;31m%d\033[0m\n", g_enemigosDerrotados);
    printf("    Tesoros abiertos:       \033[1;32m%d\033[0m\n", g_tesorosAbiertos);
    printf("    Bonus de Victoria:      \033[1;35m+5000 pts\033[0m\n");
    printf("    ─────────────────────────────────────────\n");
    printf("    \033[1mPUNTUACIÓN FINAL:\033[0m       \033[1;32m%d pts\033[0m\n", puntos);
    if (puesto > 0) {
        printf("    \033[1;33m★ ¡NUEVO RÉCORD! Entraste al Top %d (#%d) ★\033[0m\n", MAX_RECORDS, puesto);
    }
    printf("  \033[1;33m═══════════════════════════════════════════\033[0m\n");

    printP("\nPulsa \033[40mENTER\033[0;1;37m para volver al menú principal...\n");
    fflush(stdout);
    waitForEnter();

    g_hayPartida = 0;
    g_solicitarMenu = 0;
    limpiarPantalla();
}
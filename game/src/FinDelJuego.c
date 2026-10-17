void muerteJugador(char nombreJugador[])
{
    #ifdef __EMSCRIPTEN__
    EM_ASM({
        if (typeof window.playSound === 'function') {
            window.playSound('death');
        }
    });
    #endif
    printP("\033[31m!  H A S   M U E R T O  !\033[0m\n\n");
    printP("En ese preciso momento ");
    printf("\033[1m'%s'\033[0m", nombreJugador);
    printP(" cayó al suelo, derrotado. Sus fuerzas se desvanecieron mientras la oscuridad lo envolvía.\n\n");
    printP("\033[31m\"¿Por qué fui tan débil?\", pensó, sintiendo el peso de sus errores.\033[0m\n");
    printP("El rostro de su amada cruzó por su mente una última vez, y una lágrima silenciosa recorrió su mejilla.\n");

    printP("\033[1m\"Lo siento... No pude salvarte.\"\033[0m\n\n");

    printf("                              _____  _____\n");
    printf("                             <     `/     |\n");
    printf("                              >          (\n");
    printf("                             |   _     _  |\n");
    printf("                             |  |_) | |_) |\n");
    printf("                             |  | \\ | |   |\n");
    printf("                             |            |\n");
    printf("              _______.______ _|            |__________  _____\n");
    printf("            _/                                       \\|     |\n");
    printf("           |               H A S   M U E R T O              <\n");
    printf("           |_____.-._________              ____/|___________|\n");
    printf("                             |            |\n");
    printf("                             |            |\n");
    printf("                             |            |\n");
    printf("                             |            |\n");
    printf("                             |   _        <\n");
    printf("                             |__/         |\n");
    printf("                              / `--.      |\n");
    printf("                             |            |\n");
    printf("                        |/. |          -< o\n");
    printf("                        `\\ `0|     v      |O00\n");
    printf("                         .o0o|     |       OooO\n");
    printf("                       _.oO0oOo  _/ \\____o0oO0oOo\n");

    printP("\nPulsa \033[40mENTER\033[0;1;37m para volver al menú principal...\n");
    fflush(stdout);
    waitForEnter();

    #ifdef __EMSCRIPTEN__
    EM_ASM({
        window.location.reload();
    });
    #else
    exit(0);
    #endif
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

            printP("\033[1m\033[31mGracias por Jugar...\033[0m");
            exit(0);
        break;
    }
}

void finDelJuego(char nombreJugador[])
{
    int frameAnimacion = 1, i;
    char enter;

    printP("\033[1mCon un último golpe certero, ");
    printf("\033[34m'%s'\033[0m", nombreJugador);
    printP(" atravesó el corazón del \033[35m'Shadow Lord'\033[0m.\033[0m\n");
    printP("El dragón lanzó un rugido desgarrador antes de desplomarse, cubriendo la sala con un silencio sepulcral.\n\n");
    
    printP("Entre los escombros, \033[1muna figura conocida emergió era su amada.\033[0m\n");
    printP("Ella corrió hacia él, lágrimas en los ojos, mientras ");
    printf("\033[34m'%s'\033[0m", nombreJugador);
    printP(" caía de rodillas, exhausto.\n\n");
    
    printP("\033[33mLa maldición del 'Castle Cat' había terminado.\033[0m\n");
    printP("Juntos regresaron a \033[31m'Nekovania'\033[0m, donde el pueblo los recibió como héroes.\n\n");

    for(i = 0; i <= 3; i++)
    {     
        printP("\033[1m\nPresiona \033[33mENTER ♥\033[0m\n");
        waitForEnter();
        // Limpiar la Pantalla
        limpiarPantalla();

        animacionFinal(&frameAnimacion);
    }
}
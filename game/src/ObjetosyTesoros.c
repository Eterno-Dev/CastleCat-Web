#define NUM_TOTAL_ITEMS 27

/* Struct de los Objetos */
typedef struct
{
    char *nombreObjeto;
    bool itemConsumible;
    int otorgarVida;
    int otorgarExtraVidaMax;

    int fueArmaExtra;
    int intArmaExtra;
    int agiArmaExtra;

    //Número de Items en el Inventario del Jugador
    int numItemsInventario;

    //ID del Ataque
    int idAtaque;
}TItem;

// Se definen las dos funciones
void calidadAleatoria(TItem statsItem[], int habitacionTesoro);
int inventarioJugador(TItem statsItem[], int *hp, int *hpMax, int *atk, int *mag, int *agi, int *def, char nomJugador[]);

/* Define las Estadisticas de los Items */
void definirItems(TItem statsItem[])
{
    // Consumibles
    statsItem[0].nombreObjeto = "Poción de Vida";
    statsItem[0].itemConsumible = true;
    statsItem[0].otorgarVida = 5;
    statsItem[0].otorgarExtraVidaMax = 0;
    statsItem[0].fueArmaExtra = 0;
    statsItem[0].intArmaExtra = 0;
    statsItem[0].agiArmaExtra = 0;
    statsItem[0].numItemsInventario = 0;
    statsItem[0].idAtaque = -1;

    statsItem[1].nombreObjeto = "Poción de Vida Máxima";
    statsItem[1].itemConsumible = true;
    statsItem[1].otorgarVida = 3;
    statsItem[1].otorgarExtraVidaMax = 3;
    statsItem[1].fueArmaExtra = 0;
    statsItem[1].intArmaExtra = 0;
    statsItem[1].agiArmaExtra = 0;
    statsItem[1].numItemsInventario = 0;
    statsItem[1].idAtaque = -1;

    statsItem[2].nombreObjeto = "Poción de Fuerza";
    statsItem[2].itemConsumible = true;
    statsItem[2].otorgarVida = 0;
    statsItem[2].otorgarExtraVidaMax = 0;
    statsItem[2].fueArmaExtra = 1;
    statsItem[2].intArmaExtra = 0;
    statsItem[2].agiArmaExtra = 0;
    statsItem[2].numItemsInventario = 0;
    statsItem[2].idAtaque = -1;

    statsItem[3].nombreObjeto = "Poción de Inteligencia";
    statsItem[3].itemConsumible = true;
    statsItem[3].otorgarVida = 0;
    statsItem[3].otorgarExtraVidaMax = 0;
    statsItem[3].fueArmaExtra = 0;
    statsItem[3].intArmaExtra = 1;
    statsItem[3].agiArmaExtra = 0;
    statsItem[3].numItemsInventario = 0;
    statsItem[3].idAtaque = -1;

    statsItem[4].nombreObjeto = "Poción de Agilidad";
    statsItem[4].itemConsumible = true;
    statsItem[4].otorgarVida = 0;
    statsItem[4].otorgarExtraVidaMax = 0;
    statsItem[4].fueArmaExtra = 0;
    statsItem[4].intArmaExtra = 0;
    statsItem[4].agiArmaExtra = 1;
    statsItem[4].numItemsInventario = 0;
    statsItem[4].idAtaque = -1;

    // Consumible Especial: Plátano (Posición 5)
    statsItem[5].nombreObjeto = "Plátano";
    statsItem[5].itemConsumible = true;
    statsItem[5].otorgarVida = 10;
    statsItem[5].otorgarExtraVidaMax = 0;
    statsItem[5].fueArmaExtra = 5;
    statsItem[5].intArmaExtra = 5;
    statsItem[5].agiArmaExtra = 5;
    statsItem[5].numItemsInventario = 0;
    statsItem[5].idAtaque = -1;

    // Armas Normales (Posiciones 6 - 14)
    statsItem[6].nombreObjeto = "Espada Fina";
    statsItem[6].itemConsumible = false;
    statsItem[6].otorgarVida = 0;
    statsItem[6].otorgarExtraVidaMax = 0;
    statsItem[6].fueArmaExtra = 3;
    statsItem[6].intArmaExtra = 0;
    statsItem[6].agiArmaExtra = 0;
    statsItem[6].numItemsInventario = 0;
    statsItem[6].idAtaque = 1;

    statsItem[7].nombreObjeto = "Cetro de Roble Místico";
    statsItem[7].itemConsumible = false;
    statsItem[7].otorgarVida = 0;
    statsItem[7].otorgarExtraVidaMax = 0;
    statsItem[7].fueArmaExtra = 0;
    statsItem[7].intArmaExtra = 3;
    statsItem[7].agiArmaExtra = 0;
    statsItem[7].numItemsInventario = 0;
    statsItem[7].idAtaque = 2;

    statsItem[8].nombreObjeto = "Daga de Sombra Rápida";
    statsItem[8].itemConsumible = false;
    statsItem[8].otorgarVida = 0;
    statsItem[8].otorgarExtraVidaMax = 0;
    statsItem[8].fueArmaExtra = 0;
    statsItem[8].intArmaExtra = 0;
    statsItem[8].agiArmaExtra = 3;
    statsItem[8].numItemsInventario = 0;
    statsItem[8].idAtaque = 3;

    statsItem[9].nombreObjeto = "Espadón de Bronce";
    statsItem[9].itemConsumible = false;
    statsItem[9].otorgarVida = 0;
    statsItem[9].otorgarExtraVidaMax = 0;
    statsItem[9].fueArmaExtra = 4;
    statsItem[9].intArmaExtra = 0;
    statsItem[9].agiArmaExtra = 0;
    statsItem[9].numItemsInventario = 0;
    statsItem[9].idAtaque = 4;

    statsItem[10].nombreObjeto = "Varita de Luz";
    statsItem[10].itemConsumible = false;
    statsItem[10].otorgarVida = 0;
    statsItem[10].otorgarExtraVidaMax = 0;
    statsItem[10].fueArmaExtra = 0;
    statsItem[10].intArmaExtra = 4;
    statsItem[10].agiArmaExtra = 0;
    statsItem[10].numItemsInventario = 0;
    statsItem[10].idAtaque = 5;

    statsItem[11].nombreObjeto = "Cuchilla de Viento";
    statsItem[11].itemConsumible = false;
    statsItem[11].otorgarVida = 0;
    statsItem[11].otorgarExtraVidaMax = 0;
    statsItem[11].fueArmaExtra = 0;
    statsItem[11].intArmaExtra = 0;
    statsItem[11].agiArmaExtra = 4;
    statsItem[11].numItemsInventario = 0;
    statsItem[11].idAtaque = 6;

    statsItem[12].nombreObjeto = "Mazo Rúnico";
    statsItem[12].itemConsumible = false;
    statsItem[12].otorgarVida = 0;
    statsItem[12].otorgarExtraVidaMax = 0;
    statsItem[12].fueArmaExtra = 5;
    statsItem[12].intArmaExtra = 0;
    statsItem[12].agiArmaExtra = 0;
    statsItem[12].numItemsInventario = 0;
    statsItem[12].idAtaque = 7;

    statsItem[13].nombreObjeto = "Libro de Hechizos Elementales";
    statsItem[13].itemConsumible = false;
    statsItem[13].otorgarVida = 0;
    statsItem[13].otorgarExtraVidaMax = 0;
    statsItem[13].fueArmaExtra = 0;
    statsItem[13].intArmaExtra = 5;
    statsItem[13].agiArmaExtra = 0;
    statsItem[13].numItemsInventario = 0;
    statsItem[13].idAtaque = 8;

    statsItem[14].nombreObjeto = "Dardos Envenenados";
    statsItem[14].itemConsumible = false;
    statsItem[14].otorgarVida = 0;
    statsItem[14].otorgarExtraVidaMax = 0;
    statsItem[14].fueArmaExtra = 0;
    statsItem[14].intArmaExtra = 0;
    statsItem[14].agiArmaExtra = 5;
    statsItem[14].numItemsInventario = 0;
    statsItem[14].idAtaque = 9;

    // Armas Raras (Posiciones 15 - 20)
    statsItem[15].nombreObjeto = "Espada de la Sombra Creciente";
    statsItem[15].itemConsumible = false;
    statsItem[15].otorgarVida = 0;
    statsItem[15].otorgarExtraVidaMax = 0;
    statsItem[15].fueArmaExtra = 8;
    statsItem[15].intArmaExtra = 0;
    statsItem[15].agiArmaExtra = 0;
    statsItem[15].numItemsInventario = 0;
    statsItem[15].idAtaque = 10;

    statsItem[16].nombreObjeto = "Cetro de las Mareas";
    statsItem[16].itemConsumible = false;
    statsItem[16].otorgarVida = 0;
    statsItem[16].otorgarExtraVidaMax = 0;
    statsItem[16].fueArmaExtra = 0;
    statsItem[16].intArmaExtra = 8;
    statsItem[16].agiArmaExtra = 0;
    statsItem[16].numItemsInventario = 0;
    statsItem[16].idAtaque = 11;

    statsItem[17].nombreObjeto = "Cuchilla del Asesino Perdido";
    statsItem[17].itemConsumible = false;
    statsItem[17].otorgarVida = 0;
    statsItem[17].otorgarExtraVidaMax = 0;
    statsItem[17].fueArmaExtra = 0;
    statsItem[17].intArmaExtra = 0;
    statsItem[17].agiArmaExtra = 8;
    statsItem[17].numItemsInventario = 0;
    statsItem[17].idAtaque = 12;

    statsItem[18].nombreObjeto = "Martillo del Rompemundos";
    statsItem[18].itemConsumible = false;
    statsItem[18].otorgarVida = 0;
    statsItem[18].otorgarExtraVidaMax = 0;
    statsItem[18].fueArmaExtra = 10;
    statsItem[18].intArmaExtra = 0;
    statsItem[18].agiArmaExtra = 0;
    statsItem[18].numItemsInventario = 0;
    statsItem[18].idAtaque = 13;

    statsItem[19].nombreObjeto = "Varita de las Almas Perdidas";
    statsItem[19].itemConsumible = false;
    statsItem[19].otorgarVida = 0;
    statsItem[19].otorgarExtraVidaMax = 0;
    statsItem[19].fueArmaExtra = 0;
    statsItem[19].intArmaExtra = 10;
    statsItem[19].agiArmaExtra = 0;
    statsItem[19].numItemsInventario = 0;
    statsItem[19].idAtaque = 14;

    statsItem[20].nombreObjeto = "Dardos del Silencio Eterno";
    statsItem[20].itemConsumible = false;
    statsItem[20].otorgarVida = 0;
    statsItem[20].otorgarExtraVidaMax = 0;
    statsItem[20].fueArmaExtra = 0;
    statsItem[20].intArmaExtra = 0;
    statsItem[20].agiArmaExtra = 10;
    statsItem[20].numItemsInventario = 0;
    statsItem[20].idAtaque = 15;

    // Armas Míticas (Posiciones 21 - 23)
    statsItem[21].nombreObjeto = "Espada Ígnea del Dragón";
    statsItem[21].itemConsumible = false;
    statsItem[21].otorgarVida = 0;
    statsItem[21].otorgarExtraVidaMax = 0;
    statsItem[21].fueArmaExtra = 15;
    statsItem[21].intArmaExtra = 0;
    statsItem[21].agiArmaExtra = 0;
    statsItem[21].numItemsInventario = 0;
    statsItem[21].idAtaque = 16;

    statsItem[22].nombreObjeto = "Cetro del Archimago Supremo";
    statsItem[22].itemConsumible = false;
    statsItem[22].otorgarVida = 0;
    statsItem[22].otorgarExtraVidaMax = 0;
    statsItem[22].fueArmaExtra = 0;
    statsItem[22].intArmaExtra = 15;
    statsItem[22].agiArmaExtra = 0;
    statsItem[22].numItemsInventario = 0;
    statsItem[22].idAtaque = 17;

    statsItem[23].nombreObjeto = "Daga de la Tormenta Nocturna";
    statsItem[23].itemConsumible = false;
    statsItem[23].otorgarVida = 0;
    statsItem[23].otorgarExtraVidaMax = 0;
    statsItem[23].fueArmaExtra = 0;
    statsItem[23].intArmaExtra = 0;
    statsItem[23].agiArmaExtra = 15;
    statsItem[23].numItemsInventario = 0;
    statsItem[23].idAtaque = 18;

    // Armas Legendarias (Posiciones 24 - 26)
    statsItem[24].nombreObjeto = "Espada de las Llamas Eternas";
    statsItem[24].itemConsumible = false;
    statsItem[24].otorgarVida = 0;
    statsItem[24].otorgarExtraVidaMax = 0;
    statsItem[24].fueArmaExtra = 25;
    statsItem[24].intArmaExtra = 0;
    statsItem[24].agiArmaExtra = 0;
    statsItem[24].numItemsInventario = 0;
    statsItem[24].idAtaque = 19;

    statsItem[25].nombreObjeto = "Cetro de la Eternidad Arcana";
    statsItem[25].itemConsumible = false;
    statsItem[25].otorgarVida = 0;
    statsItem[25].otorgarExtraVidaMax = 0;
    statsItem[25].fueArmaExtra = 0;
    statsItem[25].intArmaExtra = 25;
    statsItem[25].agiArmaExtra = 0;
    statsItem[25].numItemsInventario = 0;
    statsItem[25].idAtaque = 20;

    statsItem[26].nombreObjeto = "Daga de la Velocidad Divina";
    statsItem[26].itemConsumible = false;
    statsItem[26].otorgarVida = 0;
    statsItem[26].otorgarExtraVidaMax = 0;
    statsItem[26].fueArmaExtra = 0;
    statsItem[26].intArmaExtra = 0;
    statsItem[26].agiArmaExtra = 25;
    statsItem[26].numItemsInventario = 0;
    statsItem[26].idAtaque = 21;
}

/* Título Cambiar de Planta */
void tituloPlantaDungeon(int plantaDungeon, int *entradaPlanta)
{
    switch(plantaDungeon)
    {
    
    case 1:
        printf("  ___   _        _     _  _   _____     _       _ \n");
        printf(" | _ \\ | |      /_\\   | \\| | |_   _|   /_\\     / |\n");
        printf(" |  _/ | |__   / _ \\  | .` |   | |    / _ \\    | |\n");
        printf(" |_|   |____| /_/ \\_\\ |_|\\_|   |_|   /_/ \\_\\   |_|\n\n");
        
        printP("\033[1m\033[1;33m!Has Entrado en la Planta 1!\033[0m\n");

        printP("\n\033[1;35m[Shadow Lord]\033[0m ");
        printP("\033[1;37m¡Otra hormiga osa adentrarse en mi castillo!\033[0m\n");
        pasarDePlanta();

        *entradaPlanta = 0;
        break;
    
    case 2:
        printf(" ___   _        _     _  _   _____     _       ___ \n");
        printf("| _ \\ | |      /_\\   | \\| | |_   _|   /_\\     |_  )\n");
        printf("|  _/ | |__   / _ \\  | .` |   | |    / _ \\     / / \n");
        printf("|_|   |____| /_/ \\_\\ |_|\\_|   |_|   /_/ \\_\\   /___|\n\n");
        printP("\033[1m\033[1;33m!Has Entrado en la Planta 2!\033[0m\n");

        printP("\n\033[1;35m[Shadow Lord]\033[0m ");
        printP("\033[1;37m¡No está mal para un perdedor como tú!\033[0m\n");
        pasarDePlanta();

        *entradaPlanta = 1;
        break;

    case 3:
        printf("  ___   _        _     _  _   _____     _       ____\n");
        printf(" | _ \\ | |      /_\\   | \\| | |_   _|   /_\\     |__ /\n");
        printf(" |  _/ | |__   / _ \\  | .` |   | |    / _ \\     |_ \\\n");
        printf(" |_|   |____| /_/ \\_\\ |_|\\_|   |_|   /_/ \\_\\   |___/\n\n");
        printP("\033[1m\033[1;33m!Has Entrado en la Planta 3!\033[0m\n");

        printP("\n\033[1;35m[Shadow Lord]\033[0m ");
        printP("\033[1;37m¡De verdad me sorprendes!\033[0m\n");

        printP("\n\033[1;35m[Shadow Lord]\033[0m ");
        printP("\033[1;37m¡Ahora te queda la parte difícil!\033[0m\n");
        pasarDePlanta();
        
        *entradaPlanta = 0;
        break;

    case 4:
        printf("  ____   ____   _____ _____    ______ _____ _   _          _      \n");
        printf(" |  _ \\ / __ \\ / ____/ ____|  |  ____|_   _| \\ | |   /\\   | |     \n");
        printf(" | |_) | |  | | (___| (___    | |__    | | |  \\| |  /  \\  | |     \n");
        printf(" |  _ <| |  | |\\___ \\___  \\   |  __|   | | | . ` | / /\\ \\ | |     \n");
        printf(" | |_) | |__| |____) |___) |  | |     _| |_| |\\  |/ ____ \\| |____ \n");
        printf(" |____/ \\____/|_____/_____/   |_|    |_____|_| \\_/_/    \\_\\______| \n\n");
        printP("\033[1m\033[1;33m!Has Entrado en la Sala del \033[1;35mShadow Lord\033[1;33m!\033[0m\n");

        printP("\n\033[1;35m[Shadow Lord]\033[0m ");
        printP("\033[1;37mHacía siglos que nadie llegaba a esta habitación...\033[0m\n");

        printP("\n\033[1;35m[Shadow Lord]\033[0m ");
        printP("\033[1;37m¡Lástima que vayas a morir!\033[0m\n");
        pasarDePlanta();
        
        break; 
    
    }
}

/* Dibujo Cofres */
void dibujoCofreTesoro()
{
    printf("             ___=..\n");
    printf("     ,-\"_,=\"\"      `\"=.\n");
    printf("     \"=._o`\"-._        `\"=._\n");
    printf("         `\"=._o`\"=._.  .-=\"'\"=._\n");
    printf("             _:==._o.\"·,-\"\"\"-._ \".\n");
    printf("       __.--\" , ,  `\"-._\"-._   \".\n");
    printf("  ._\"  ,. .` ` .\". ,  \"-._\"-._; ;\n");
    printf("  |o`\"=._` , \" ` '`.\" ` . \"-._ /\n");
    printf("  | ;`-.o`\"=.__``  '` \" ,__.--o;\n");
    printf("  |o;   \033[1m\033[1;33m(X)\033[0m .o `\"=.__.--\"_o.-; ;\n");
    printf("  | ;    \"    `\".o|o_.--\"    ;o;\n");
    printf("  |o;._         ; | ;        ; ;\n");
    printf("    =._o--._    ;o|o;     _._;o;\n");
    printf("        \"=._o-._; | ;_.--\"o.--\"\n");
    printf("             \"\"=.o|o_.--\"\"\n\n");
}

/* Jugador Entra en una Habitación con Tesoro */
void habitacionTesoro(TItem statsItem[], int habitacionTesoro)
{
    char tesoroElegido;
    bool opcionTesoroCorrecta = false;

    printf("\033[1m\033[1;33m¡Has entrado en una habitación con tesoro!\033[0m\n\n");
    dibujoCofreTesoro();

    printP("Pulsa \033[40mENTER\033[0;1;37m para abrir el tesoro.\n");
    fflush(stdout);
    waitForEnter();
    
    reproducirSonido("chest");
    g_tesorosAbiertos++;
    
    limpiarPantalla();

    // printf("\033[1;33m============================\033[0m\n");
    // printP("\033[1m\033[31m   Cargando Recompensa...\033[0m\n");
    // printf("\033[1;33m============================\033[0m\n\n");
    calidadAleatoria(statsItem, habitacionTesoro);
}

/* Recompensas Normales Random */
void recompensaNormal(TItem statsItem[])
{
    //Número de Items
    srand(time(NULL));
    int itemsAleatorios, itemConsumible, itemArmaNormal;
    itemsAleatorios = rand() % 3 + 1;

    switch(itemsAleatorios)
    {
        case 1:
        printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[0].nombreObjeto);
        statsItem[0].numItemsInventario++;
        break;

        case 2:
        printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[0].nombreObjeto);
        statsItem[0].numItemsInventario++;

        itemConsumible = rand() % 4 + 1;
        printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemConsumible].nombreObjeto);
        statsItem[itemConsumible].numItemsInventario++;
        break;

        case 3:

            itemConsumible = rand() % 4 + 1;
            printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemConsumible].nombreObjeto);
            statsItem[itemConsumible].numItemsInventario++;

            itemArmaNormal = rand() % 9 + 6;
            printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemArmaNormal].nombreObjeto);

            if(statsItem[itemArmaNormal].numItemsInventario >= 0)
            {
                statsItem[itemArmaNormal].numItemsInventario++;
            }

        break;

        default:
        break;
    }

}

/* Recompensas Raras Random */
void recompensaRara(TItem statsItem[])
{
    //Número de Items
    srand(time(NULL));
    int itemsAleatorios, itemConsumible, itemArmaRara, i;
    itemsAleatorios = rand() % 3 + 1;

    switch(itemsAleatorios)
    {
        case 1:
        printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[0].nombreObjeto);
        statsItem[0].numItemsInventario++;

            for (i = 1; i <= 2; i++)
            {
                itemConsumible = rand() % 4 + 1;
                printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemConsumible].nombreObjeto);
                statsItem[itemConsumible].numItemsInventario++;
            }

        break;

        case 2:
            itemArmaRara = rand() % 6 + 15;
            printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemArmaRara].nombreObjeto);

            if(statsItem[itemArmaRara].numItemsInventario >= 0)
            {
                statsItem[itemArmaRara].numItemsInventario++; 
            }

            
            printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[0].nombreObjeto);
            statsItem[0].numItemsInventario++;

            itemConsumible = rand() % 4 + 1;
            printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemConsumible].nombreObjeto);
            statsItem[itemConsumible].numItemsInventario++;

        break;

        case 3:

            for (i = 1; i <= 2; i++)
            {
                itemArmaRara = rand() % 6 + 15;
                printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemArmaRara].nombreObjeto);

                if(statsItem[itemArmaRara].numItemsInventario >= 0)
                {
                    statsItem[itemArmaRara].numItemsInventario++;
                }
                
            }
            
            itemConsumible = rand() % 4 + 1;
            printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemConsumible].nombreObjeto);
            statsItem[itemConsumible].numItemsInventario++;

        break;

        default:
        break;
    }

}

/* Recompensas Legendarias Random */
void recompensaLegendaria(TItem statsItem[])
{
    //Número de Items
    srand(time(NULL));
    int itemsAleatorios, itemConsumible, itemArmaLegendaria, i;
    itemsAleatorios = rand() % 3 + 1;

    switch(itemsAleatorios)
    {
        case 1:
        printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[0].nombreObjeto);
        statsItem[0].numItemsInventario++;

            for (i = 1; i <= 3; i++)
            {
                itemConsumible = rand() % 4 + 1;
                printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemConsumible].nombreObjeto);
                statsItem[itemConsumible].numItemsInventario++;
            }

        printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[0].nombreObjeto);
        statsItem[0].numItemsInventario++;

        break;

        case 2:

            for (i = 1; i <= 2; i++)
            {
                itemArmaLegendaria = rand() % 6 + 21;
                printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemArmaLegendaria].nombreObjeto);
                    
                    if(statsItem[itemArmaLegendaria].numItemsInventario >= 0)
                    {
                        statsItem[itemArmaLegendaria].numItemsInventario++;
                    }
            }
            
            printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[0].nombreObjeto);
            statsItem[0].numItemsInventario++;

            for (i = 1; i <= 3; i++)
            {
                itemConsumible = rand() % 4 + 1;
                printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemConsumible].nombreObjeto);
                statsItem[itemConsumible].numItemsInventario++;
            }

        break;

        case 3:

            for (i = 1; i <= 3; i++)
            {
                itemArmaLegendaria = rand() % 6 + 21;
                printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemArmaLegendaria].nombreObjeto);
                    
                    if(statsItem[itemArmaLegendaria].numItemsInventario >= 0)
                    {
                        statsItem[itemArmaLegendaria].numItemsInventario++;
                    }
            }
                
                itemConsumible = rand() % 4 + 1;
                printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[itemConsumible].nombreObjeto);
                statsItem[itemConsumible].numItemsInventario++;
            
        break;

        default:
        break;
    }

    // Probabilidad de encontrar el mítico Plátano en cofre legendario (15%)
    if ((rand() % 100) < 15)
    {
        printf("\033[38;5;208m¡Has encontrado un objeto secreto!\033[0m\n");
        printf("\033[1m\033[1;33m+1:\033[0m %s\n", statsItem[5].nombreObjeto);
        statsItem[5].numItemsInventario++;
    }

}

/* Calidad del Cofre */
void calidadAleatoria(TItem statsItem[], int habitacionTesoro)
{
    int tipoCofre;
    srand(time(NULL));
    tipoCofre = rand() % 2 + 1;

    printf("\n\033[1;37m════════════════════════════\033[0m\n");

    switch (habitacionTesoro)
    {
        // Un consumibe, dos consumibles o una arma (normal) y un objeto
        case 1:
                printf("La recompensa es: \033[1m\033[34mNormal\033[0m\n");
                recompensaNormal(statsItem);
        break;

        // Tres consumibes, una armas y dos consumibles o Dos armas una (rara) y un consumible
        case 2:

            if(tipoCofre == 2)
            {
                printf("La recompensa es: \033[1m\033[31mRara\033[0m\n");
                recompensaRara(statsItem);
            }

            else
            {
                printf("La recompensa es: \033[1m\033[34mNormal\033[0m\n");
                recompensaNormal(statsItem); 
            }
        break;

        // 5 consumibes, 2 armas y 4 consumibles o 3 arma una (Legendaria) y 4 consumibles
        case 3:

            if(tipoCofre == 2)
            {
                printf("La recompensa es: \033[1m\033[33mLegendaria\033[0m\n");
                recompensaLegendaria(statsItem);
            }

            else
            {
                printf("La recompensa es: \033[1m\033[31mRara\033[0m\n");
                recompensaRara(statsItem);
            }
        break;

        default:
        break;
    }
    
    printf("\033[1;37m════════════════════════════\033[0m\n");
    enterContinuar();
}

/* Información del Item del Inventario */
void informacionItemInventario(TItem statsItem[], int accederObj)
{
    bool esPlatano = (accederObj == 5) || 
                     (statsItem[accederObj].nombreObjeto != NULL && 
                      (strstr(statsItem[accederObj].nombreObjeto, "Plátano") != NULL ||
                       strstr(statsItem[accederObj].nombreObjeto, "Platano") != NULL ||
                       strstr(statsItem[accederObj].nombreObjeto, "banana") != NULL ||
                       strstr(statsItem[accederObj].nombreObjeto, "Banana") != NULL));

    printf("\n\033[1m\033[1;31mINFORMACIÓN:\033[0m\n");
    printf("\033[1m\033[1;31m═════════════\033[0m\n");

    printf("Nombre del objeto: \033[0;1m%s\033[0m\n", statsItem[accederObj].nombreObjeto);
    printf("Tipo: \033[0;1m%s\033[0m\n", statsItem[accederObj].itemConsumible ? "Consumible" : "Equipable");
    
    int tieneStats = 0;
    if (statsItem[accederObj].otorgarVida > 0) {
        printf("Recuperación de Vida: \033[0;1;32m+%d\033[0m\n", statsItem[accederObj].otorgarVida);
        tieneStats++;
    }
    if (statsItem[accederObj].otorgarExtraVidaMax > 0) {
        printf("Aumento de Vida Máxima: \033[0;1;32m+%d\033[0m\n", statsItem[accederObj].otorgarExtraVidaMax);
        tieneStats++;
    }
    if (statsItem[accederObj].fueArmaExtra > 0) {
        printf("Aumento de Fuerza: \033[0;1;31m+%d\033[0m\n", statsItem[accederObj].fueArmaExtra);
        tieneStats++;
    }
    if (statsItem[accederObj].intArmaExtra > 0) {
        printf("Aumento de Inteligencia: \033[0;1;34m+%d\033[0m\n", statsItem[accederObj].intArmaExtra);
        tieneStats++;
    }
    if (statsItem[accederObj].agiArmaExtra > 0) {
        printf("Aumento de Agilidad: \033[0;1;33m+%d\033[0m\n", statsItem[accederObj].agiArmaExtra);
        tieneStats++;
    }
    if (esPlatano) {
        printf("Aumento de Defensa: \033[0;1;36m+10\033[0m\n");
        tieneStats++;
    }
    if (!tieneStats) {
        printf("Efecto: \033[0;1;30mSin atributos adicionales\033[0m\n");
    }
}

/* Usar Item del Inventario */
void usarItemInventario(TItem statsItem[], int accederObj, int *hp, int *hpMax, int *atk, int *mag, int *agi, int *def, char nomJugador[])
{
    bool esPlatano = (accederObj == 5) || 
                     (statsItem[accederObj].nombreObjeto != NULL && 
                      (strstr(statsItem[accederObj].nombreObjeto, "Plátano") != NULL ||
                       strstr(statsItem[accederObj].nombreObjeto, "Platano") != NULL ||
                       strstr(statsItem[accederObj].nombreObjeto, "banana") != NULL ||
                       strstr(statsItem[accederObj].nombreObjeto, "Banana") != NULL));

    if(statsItem[accederObj].itemConsumible == true)
    {
        if (esPlatano) {
            reproducirSonido("platano");
        } else {
            reproducirSonido("potion");
        }
        printf("\nHas Gastado x1: \033[0;1m%s\033[0m\n", statsItem[accederObj].nombreObjeto);
        statsItem[accederObj].numItemsInventario--;
        *hpMax = *hpMax + statsItem[accederObj].otorgarExtraVidaMax;
        *hp = *hp + statsItem[accederObj].otorgarVida;
        if (*hp > *hpMax) *hp = *hpMax;
        *def = *def + (statsItem[accederObj].otorgarExtraVidaMax/2);
        if (esPlatano) {
            *def = *def + 10;
        }
        *atk = *atk + statsItem[accederObj].fueArmaExtra;
        *mag = *mag + statsItem[accederObj].intArmaExtra;
        *agi = *agi + statsItem[accederObj].agiArmaExtra;
    }
    else
    {
        printf("\nHas Equipado x1: \033[0;1m%s\033[0m\n", statsItem[accederObj].nombreObjeto);
        statsItem[accederObj].numItemsInventario = -1;
    }
    
    int tieneStats = 0;
    printf("\n\033[1m\033[1;33m════════════ INFORMACIÓN ════════════\033[0m\n");
    if (statsItem[accederObj].otorgarVida > 0) {
        printf("Vida recuperada: \033[0;1;32m+%d\033[0m\n", statsItem[accederObj].otorgarVida);
        tieneStats++;
    }
    if (statsItem[accederObj].otorgarExtraVidaMax > 0) {
        printf("Aumento de Vida: \033[0;1;32m+%d\033[0m\n", statsItem[accederObj].otorgarExtraVidaMax);
        tieneStats++;
    }
    if (statsItem[accederObj].fueArmaExtra > 0) {
        printf("Aumento de Fuerza: \033[0;1;31m+%d\033[0m\n", statsItem[accederObj].fueArmaExtra);
        tieneStats++;
    }
    if (statsItem[accederObj].intArmaExtra > 0) {
        printf("Aumento de Inteligencia: \033[0;1;34m+%d\033[0m\n", statsItem[accederObj].intArmaExtra);
        tieneStats++;
    }
    if (statsItem[accederObj].agiArmaExtra > 0) {
        printf("Aumento de Agilidad: \033[0;1;33m+%d\033[0m\n", statsItem[accederObj].agiArmaExtra);
        tieneStats++;
    }
    if (esPlatano) {
        printf("Aumento de Defensa: \033[0;1;36m+10\033[0m\n");
        tieneStats++;
    }
    if (!tieneStats) {
        printf("\033[0;1;30mSin atributos adicionales\033[0m\n");
    }
}

/* Desequipar Arma del Inventario Jugador */
void desequiparItemInventario(TItem statsItem[], int accederObj)
{
    printf("\nTe has Desequipado: \033[0;1m%s\033[0m\n", statsItem[accederObj].nombreObjeto);
    statsItem[accederObj].numItemsInventario = 1;
}

/* Muestra una fila compacta con las estadisticas del jugador en el inventario */
void mostrarStatsInventario(TItem statsItem[], int *atk, int *mag, int *agi, int *def)
{
    int bAtk = 0, bMag = 0, bAgi = 0, bDef = 0;
    for (int i = 0; i < NUM_TOTAL_ITEMS; i++) {
        if (statsItem[i].numItemsInventario == -1) {
            bAtk += statsItem[i].fueArmaExtra;
            bMag += statsItem[i].intArmaExtra;
            bAgi += statsItem[i].agiArmaExtra;
            bDef += (statsItem[i].fueArmaExtra / 2);
        }
    }
    int totAtk = *atk + bAtk;
    int totMag = *mag + bMag;
    int totAgi = *agi + bAgi;
    int totDef = *def + bDef;

    printf("\n\033[1;31mψ ATK:\033[0;1m %d\033[0m", totAtk);
    if (bAtk > 0) printf(" \033[1;32m(+%d)\033[0m", bAtk);
    printf("  \033[1;34m★ MAG:\033[0;1m %d\033[0m", totMag);
    if (bMag > 0) printf(" \033[1;32m(+%d)\033[0m", bMag);
    printf("  \033[1;33m➹ AGI:\033[0;1m %d\033[0m", totAgi);
    if (bAgi > 0) printf(" \033[1;32m(+%d)\033[0m", bAgi);
    printf("  \033[1;35m♢ DEF:\033[0;1m %d\033[0m", totDef);
    if (bDef > 0) printf(" \033[1;32m(+%d)\033[0m", bDef);
    printf("\n");
}

/* Opciones Inventario Jugador (Interactive) */
void opcionesInventarioJugador(TItem statsItem[], int accederObjeto, int *atk, int *mag, int *agi, int *def, int *hp, int *hpMax, char nomJugador[])
{
    int opcionActiva = 0;
    bool salir = false;
    int numOpciones = 3;
    bool mostrarInfo = false;

    while (!salir)
    {
        limpiarPantalla();
        printf("\033[1m[%s]\033[0;1m  ", nomJugador);
        barraDeVida(hp, hpMax);
        mostrarStatsInventario(statsItem, atk, mag, agi, def);

        printf("\n\033[1m\033[1;33m╔═══════════════════╗\033[0m\n");
        printf("\033[1m\033[1;33m║      OBJETO:      ║\033[0m\n");
        printf("\033[1m\033[1;33m╚═══════════════════╝\033[0m\n");
        printf("\033[0;1m%s\033[0m\n\n", statsItem[accederObjeto].nombreObjeto);

        if (mostrarInfo) {
            informacionItemInventario(statsItem, accederObjeto);
            printf("\n\033[1m\033[2;3mPulsa ENTER para continuar...\033[0m\n");
            waitForEnter();
            mostrarInfo = false;
            continue;
        }

        printf("Usa \033[1;35mW\033[0m/\033[1;35mS\033[0m o \033[1;35mFlechas\033[0m para elegir opción:\n\n");

        if (opcionActiva == 0) printf("\033[1;31m > \033[0m"); else printf("   ");
        if (statsItem[accederObjeto].numItemsInventario == -1) printf("\033[0;1mDesequipar\033[0m\n");
        else if (statsItem[accederObjeto].itemConsumible) printf("\033[0;1mUsar\033[0m\n");
        else printf("\033[0;1mEquipar\033[0m\n");

        if (opcionActiva == 1) printf("\033[1;31m > \033[0m"); else printf("   ");
        printf("\033[0;1mInformación\033[0m\n");

        if (opcionActiva == 2) printf("\033[1;31m > \033[0m"); else printf("   ");
        printf("\033[0;1mVolver\033[0m\n");

        int key = getch();
        if (key == 224) {
            key = getch();
            if (key == 72) {
                opcionActiva = (opcionActiva - 1 + numOpciones) % numOpciones; // Up
                reproducirSonido("next_option");
            } else if (key == 80) {
                opcionActiva = (opcionActiva + 1) % numOpciones; // Down
                reproducirSonido("next_option");
            }
        } else if (key == 'w' || key == 'W') {
            opcionActiva = (opcionActiva - 1 + numOpciones) % numOpciones;
            reproducirSonido("next_option");
        } else if (key == 's' || key == 'S') {
            opcionActiva = (opcionActiva + 1) % numOpciones;
            reproducirSonido("next_option");
        } else if (key == 9 || key == 27) { // TAB o ESC: volver
            salir = true;
        } else if (key == 13 || key == 10) { // Enter
            reproducirSonido("confirm");
            if (opcionActiva == 0) {
                if (statsItem[accederObjeto].numItemsInventario == -1) {
                    desequiparItemInventario(statsItem, accederObjeto);
                    enterContinuar();
                    salir = true;
                } else {
                    if (statsItem[accederObjeto].itemConsumible == true) {
                        usarItemInventario(statsItem, accederObjeto, hp, hpMax, atk, mag, agi, def, nomJugador);
                        enterContinuar();
                        salir = true;
                    } else {
                        int numeroItemsEquipados = 0;
                        for(int i = 0; i < NUM_TOTAL_ITEMS; i++) {
                            if (statsItem[i].numItemsInventario == -1) numeroItemsEquipados++;
                        }
                        if(numeroItemsEquipados >= 2) {
                            printf("\n\033[1;31mYa tienes Dos Items Equipados.\033[0m\n");
                            enterContinuar();
                        } else {
                            usarItemInventario(statsItem, accederObjeto, hp, hpMax, atk, mag, agi, def, nomJugador);
                            enterContinuar();
                            salir = true;
                        }
                    }
                }
            } else if (opcionActiva == 1) { // Info
                mostrarInfo = true;
            } else if (opcionActiva == 2) { // Volver
                salir = true;
            }
        }
    }
}

/* Inventario Jugador (Interactive) */
int inventarioJugador(TItem statsItem[], int *hp, int *hpMax, int *atk, int *mag, int *agi, int *def, char nomJugador[])
{
    int opcionActiva = 0;
    bool salir = false;

    while (!salir)
    {
        int availableIds[NUM_TOTAL_ITEMS];
        int numAvailable = 0;

        for (int i = 0; i < NUM_TOTAL_ITEMS; i++) {
            if (statsItem[i].numItemsInventario > 0 || statsItem[i].numItemsInventario == -1) {
                availableIds[numAvailable] = i;
                numAvailable++;
            }
        }

        int numOpciones = numAvailable + 1; // +1 for "Volver"
        if (opcionActiva >= numOpciones) opcionActiva = numOpciones - 1;

        limpiarPantalla();
        printf("\033[1m[%s]\033[0;1m  ", nomJugador);
        barraDeVida(hp, hpMax);
        mostrarStatsInventario(statsItem, atk, mag, agi, def);

        printf("\033[1m\033[1;33m╔═══════════════════╗\033[0m\n");
        printf("\033[1m\033[1;33m║    INVENTARIO:    ║\033[0m\n");
        printf("\033[1m\033[1;33m╚═══════════════════╝\033[0m\n");

        if (numAvailable == 0) {
            printf("\033[31m\033[1m'No Hay Items en el Inventario'\033[0m\n");
        } else {
            for (int i = 0; i < numAvailable; i++) {
                int id = availableIds[i];
                if (i == opcionActiva) printf("\033[1;31m > \033[0m");
                else printf("   ");

                bool esPlatano = (id == 5) || 
                                 (statsItem[id].nombreObjeto != NULL && 
                                  (strstr(statsItem[id].nombreObjeto, "Plátano") != NULL ||
                                   strstr(statsItem[id].nombreObjeto, "Platano") != NULL ||
                                   strstr(statsItem[id].nombreObjeto, "banana") != NULL ||
                                   strstr(statsItem[id].nombreObjeto, "Banana") != NULL));

                if (statsItem[id].itemConsumible == true) {
                    if (esPlatano) {
                        // Plátano: indicador de cantidad en color naranja
                        printf("\033[0;1m%s \033[1m\033[38;5;208m[%i]\033[0m\n", statsItem[id].nombreObjeto, statsItem[id].numItemsInventario);
                    } else {
                        // Consumibles: indicador en rojo como siempre
                        printf("\033[0;1m%s \033[1m\033[31m[%i]\033[0m\n", statsItem[id].nombreObjeto, statsItem[id].numItemsInventario);
                    }
                } else if (statsItem[id].numItemsInventario > 0) {
                    // Equipables: indicador en morado como siempre
                    printf("\033[0;1m%s \033[1m\033[35m[%i]\033[0m\n", statsItem[id].nombreObjeto, 1);
                } else if (statsItem[id].numItemsInventario == -1) {
                    // Equipado: indicador en morado como siempre
                    printf("\033[0;1m%s \033[1m\033[35m[Equipado]\033[0m\n", statsItem[id].nombreObjeto);
                }
            }
        }

        if (opcionActiva == numAvailable) printf("\033[1;31m > \033[0m");
        else printf("   ");
        printf("\033[1;34m[Volver]\033[0m\n");

        int key = getch();
        if (key == 224) {
            key = getch();
            if (key == 72) {
                opcionActiva = (opcionActiva - 1 + numOpciones) % numOpciones; // Up
                reproducirSonido("next_option");
            } else if (key == 80) {
                opcionActiva = (opcionActiva + 1) % numOpciones; // Down
                reproducirSonido("next_option");
            }
        } else if (key == 'w' || key == 'W') {
            opcionActiva = (opcionActiva - 1 + numOpciones) % numOpciones;
            reproducirSonido("next_option");
        } else if (key == 's' || key == 'S') {
            opcionActiva = (opcionActiva + 1) % numOpciones;
            reproducirSonido("next_option");
        } else if (key == 9 || key == 27) { // TAB o ESC: volver
            salir = true;
        } else if (key == 13 || key == 10) { // Enter
            reproducirSonido("confirm");
            if (opcionActiva == numAvailable) {
                salir = true;
            } else {
                int id = availableIds[opcionActiva];
                opcionesInventarioJugador(statsItem, id, atk, mag, agi, def, hp, hpMax, nomJugador);
            }
        }
    }
    return 0;
}

/* Actualiza las Estadisticas del Equipo */
void actualizarStatsEquipo(int *atkIn, int *magIn, int *agiIn, int *defIn, TItem statsItem[], int skill[3], char arma1[50], char arma2[50],int *atk, int *mag, int *agi, int *def)
{

    int atkInc = 0, magInc = 0, agiInc = 0, defInc = 0, count = 1,i;


    for(i = 0; i < NUM_TOTAL_ITEMS; i++)
    {
        if (statsItem[i].numItemsInventario == -1)
        {
            atkInc = atkInc + statsItem[i].fueArmaExtra;
            magInc = magInc + statsItem[i].intArmaExtra;
            agiInc = agiInc + statsItem[i].agiArmaExtra;
            defInc = defInc + (statsItem[i].fueArmaExtra/2);
            skill[count] = statsItem[i].idAtaque;
            if(count == 0)
            {
                strcpy(arma1, statsItem[i].nombreObjeto);
            }
            if(count == 1)
            {
                strcpy(arma2, statsItem[i].nombreObjeto);
            }
            
            count++;
        }    
    }
    *atk = *atkIn + atkInc;
    *mag = *magIn + magInc;
    *agi = *agiIn + agiInc;
    *def = *defIn + defInc;
}




void mostrarInformacion(int* hpEne, int* hpMaxEne, int* hp, int* hpMax, int* mp, int* mpMax, int stat[4], char enemigoImagen[300], char enemigoNombre[100], int claseJugador, char nomJugador[21]);

//Todo el sistema de combate
void combate(int* hp, int* hpEne, int* hpMaxEne, int* hpMax, int* mana, int* mpMax, int atkEne, int atk, int mag, int agi, int def, int id[3], int stat[4], char* enemigoImagen, char* enemigoNombre, int claseJugador, char* nomJugador)
{
	int resp = 0, tipox = 0, coste = 0, ok = 0, dano = 0;
	float mult;
	char nombre[100], descrip[100];
    int opcionActiva = 0;

	while (ok == 0) {
        limpiarPantalla();
        mostrarInformacion(hpEne, hpMaxEne, hp, hpMax, mana, mpMax, stat, enemigoImagen, enemigoNombre, claseJugador, nomJugador);
        habilidades(id, opcionActiva, claseJugador);

        fflush(stdout);

        int key = getch();
        if (key == 224) {
            key = getch();
            if (key == 72) {
                opcionActiva = (opcionActiva - 1 + 3) % 3; // Up
                reproducirSonido("next_option");
            } else if (key == 80) {
                opcionActiva = (opcionActiva + 1) % 3; // Down
                reproducirSonido("next_option");
            }
        } else if (key == 'w' || key == 'W') {
            opcionActiva = (opcionActiva - 1 + 3) % 3;
            reproducirSonido("next_option");
        } else if (key == 's' || key == 'S') {
            opcionActiva = (opcionActiva + 1) % 3;
            reproducirSonido("next_option");
        } else if (key == 9) { // Solo TAB: volver al menú y guardar
            g_solicitarMenu = 1;
            return;
        }
        
        if (key == 13 || key == 10) { // Enter
            resp = opcionActiva;
            if (id[resp] == 0 && resp > 0) {
                reproducirSonido("confirm");
                printf("\n\033[1;31mTe falta equipar el arma para poder realizar el ataque.\033[0m\n");
                enterContinuar();
            } else if (asignarHabilidades(id[resp], nombre, descrip, &tipox, &mult, &coste, claseJugador)) {
                if (coste > *mana) {
                    reproducirSonido("confirm");
                    printf("\n\033[1;31mNo tienes suficiente mana para usar esta habilidad (%i/%i).\033[0m\n", *mana, coste);
                    enterContinuar();
                } else {
                    ok = 1;
                }
            } else {
                 reproducirSonido("confirm");
                 printf("\n\033[1;31mHabilidad no disponible.\033[0m\n");
                 enterContinuar();
            }
        }
	}

    if (tipox == 1) {
        reproducirSonido("atk_str");
    } else if (tipox == 2) {
        reproducirSonido("atk_mag");
    } else if (tipox == 3) {
        reproducirSonido("atk_agi");
    } else {
        reproducirSonido("atk_basic");
    }

	switch (tipox) {
	case 1:
		printf("\033[1;3;31m %i ψ x %.1f \n", atk, mult);
		printf("\033[1;37m Daño resultante: \033[1;3;31m %.0f \033[0m", atk * mult);
		dano = atk * mult;
		break;
	case 2:
		printf("\033[1;3;34m %i ★ x %.1f \n", mag, mult);
		printf("\033[1;37m Daño resultante: \033[1;3;31m %.0f \033[0m", mag * mult);
		dano = mag * mult;
		break;
	case 3:
		printf("\033[1;3;32m %i ➹ x %.1f \n", agi, mult);
		printf("\033[1;37m Daño resultante: \033[1;3;31m %.0f \033[0m", agi * mult);
		dano = agi * mult;
		break;
	default:
		printf(" - ");
		break;
	}
    if (coste < 0) {
        printf("\033[3;36m ✦ + %i \033[0m ", -coste);
    } else {
        printf("\033[3;36m ✦ - %i \033[0m ", coste);
    }
	printf("\n");
	*hpEne = *hpEne - dano;
	*mana -= coste; // Reducir mana después de usar la habilidad

	printf("\n");
	printP("\033[0;1;2;31m¡El enemigo te ataca!\033[0;1;30m\n");
	if (atkEne - def > 0)
	{
	    *hp -= atkEne - def;
	    printf("\033[0m%i - \033[1;3;35m ♢ %i \033[0;1m = %i\n", atkEne, def, atkEne - def);
	    
	    printf("Recibes %i puntos de daño.\n", atkEne - def);
        reproducirSonido("hit");
        temblorPantalla();
	}
	else
	{
	    printf("\033[0;1mNo recibes daños.\n");
	}
	
    printP("\nPulsa \033[40mENTER\033[0;1;37m para terminar el turno.\n");
    fflush(stdout);
	waitForEnter();
	
	limpiarPantalla();
}
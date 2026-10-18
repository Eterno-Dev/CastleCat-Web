//Estructura de las habilidades
struct Skills {
	char nombreSkill[100];
	int tipo;
	int mult;
	int coste;
	char desripSkill[300];
};

//Asigna las habilidades segun el id
int asignarHabilidades(int id, char nombre[100], char descrip[100], int* tipo, float* multi, int* coste, int claseJugador)
{
	// Asignamos atributos según el id
	switch (id) {
	case 0:
		strcpy(nombre, "\033[1;3mGolpe Normal\033[0m /");
		strcpy(descrip, "Golpea con tu arma. /");
		*multi = 1;
		if (claseJugador == 1) { // Mago
			*tipo = 2; // Mágico (Inteligencia)
			*coste = -5; // Recupera 5 de maná
		} else if (claseJugador == 2) { // Asesino
			*tipo = 3; // Agilidad
			*coste = -4; // Recupera 4 de maná
		} else { // Guerrero u otros
			*tipo = 1; // Físico (Fuerza)
			*coste = -3; // Recupera 3 de maná
		}
		break;
	case 1:
		strcpy(nombre, "\033[1;3;31mCorte Fino\033[0m /");
		strcpy(descrip, "Un fuerte corte con el filo de la espada. /");
		*tipo = 1;
		*multi = 1.5;
		*coste = 1;
		break;
	case 2:
		strcpy(nombre, "\033[1;3;34mInvocación de Raices Antiguas\033[0m /");
		strcpy(descrip, "Raices salen del suelo para atacar a tus enemigos /");
		*tipo = 2;
		*multi = 1.5;
		*coste = 2;
		break;
	case 3:
		strcpy(nombre, "\033[1;3;32mPuñalada Sombría\033[0m /");
		strcpy(descrip, "Un veloz golpe que se enconde entre las sombras. /");
		*tipo = 3;
		*multi = 1.5;
		*coste = 1;
		break;
	case 4:
		strcpy(nombre, "\033[1;3;31mGolpe Resonante\033[0m /");
		strcpy(descrip, "Un golpe que emite una onda de choque al impactar. /");
		*tipo = 1;
		*multi = 2;
		*coste = 1;
		break;
	case 5:
		strcpy(nombre, "\033[1;3;34mProyectil Lumínico\033[0m /");
		strcpy(descrip, "Un rayo de luz que surge de tu arma. /");
		*tipo = 2;
		*multi = 2;
		*coste = 2;
		break;
	case 6:
		strcpy(nombre, "\033[1;3;32mCorte Aereo\033[0m /");
		strcpy(descrip, "Un corte que emite aire que corta a tu enemigo. /");
		*tipo = 3;
		*multi = 2;
		*coste = 1;
		break;
	case 7:
		strcpy(nombre, "\033[1;3;31mGolpe Ancestral\033[0m /");
		strcpy(descrip, "Un golpe letal debido a las runas en el arma. /");
		*tipo = 1;
		*multi = 2.5;
		*coste = 1;
		break;
	case 8:
		strcpy(nombre, "\033[1;3;34mReacción Elemental\033[0m /");
		strcpy(descrip, "Desencadena el poder de los elementos. /");
		*tipo = 2;
		*multi = 2.5;
		*coste = 2;
		break;
	case 9:
		strcpy(nombre, "\033[1;3;32mProyectil Letal\033[0m /");
		strcpy(descrip, "Hiere al enemigo con un letal veneno. /");
		*tipo = 3;
		*multi = 2.5;
		*coste = 1;
		break;
	case 10:
		strcpy(nombre, "\033[1;3;31mTajo Cortasombras\033[0m /");
		strcpy(descrip, "Un corte capaz de cortar la sombra de tus enemigos. /");
		*tipo = 1;
		*multi = 3;
		*coste = 1;
		break;
	case 11:
		strcpy(nombre, "\033[1;3;34mGran Ola\033[0m /");
		strcpy(descrip, "Invoca una ola furiosa proviniente de los oceanos mas fieros. /");
		*tipo = 2;
		*multi = 3;
		*coste = 2;
		break;
	case 12:
		strcpy(nombre, "\033[1;3;32mPuñalada Ambigua\033[0m /");
		strcpy(descrip, "Una puñalada muy veloz, tan veloz que no es visible. /");
		*tipo = 3;
		*multi = 3;
		*coste = 1;
		break;
	case 13:
		strcpy(nombre, "\033[1;3;31mGolpe Quebrado\033[0m /");
		strcpy(descrip, "Un golpe capaz de romper todo muro que se ponga frente a él. /");
		*tipo = 1;
		*multi = 3.5;
		*coste = 1;
		break;
	case 14:
		strcpy(nombre, "\033[1;3;34mInvocación de Almas\033[0m /");
		strcpy(descrip, "Utiliza almas atrapadas para atacar a tus enemigos. /");
		*tipo = 2;
		*multi = 3.5;
		*coste = 2;
		break;
	case 15:
		strcpy(nombre, "\033[1;3;32mAtaque Silencioso\033[0m /");
		strcpy(descrip, "Un ataque, tan silencioso como letal. /");
		*tipo = 3;
		*multi = 3.5;
		*coste = 1;
		break;
	case 16:
		strcpy(nombre, "\033[1;3;31mColmillo Flamígero\033[0m /");
		strcpy(descrip, "Tu arma se cubre en llamas y arremetes contra tu enemigo. /");
		*tipo = 1;
		*multi = 4.5;
		*coste = 1;
		break;
	case 17:
		strcpy(nombre, "\033[1;3;34mConocimiento Antiguo\033[0m /");
		strcpy(descrip, "Utiliza los conocimientos arcanos, desencadenando hechizos poderosos. /");
		*tipo = 2;
		*multi = 4.5;
		*coste = 2;
		break;
	case 18:
		strcpy(nombre, "\033[1;3;32mMil Cortes de la Noche\033[0m /");
		strcpy(descrip, "Corta mil veces a tu enemigo. /");
		*tipo = 3;
		*multi = 4.5;
		*coste = 1;
		break;
	case 19:
		strcpy(nombre, "\033[1;3;31mQue madura eterna\033[0m /");
		strcpy(descrip, "Produce quemaduras incurables a tu enemigo. /");
		*tipo = 1;
		*multi = 6;
		*coste = 1;
		break;
	case 20:
		strcpy(nombre, "\033[1;3;34mInfinidad Arcana\033[0m /");
		strcpy(descrip, "Un simple proyectil que desencadena toda la verdad del universo. /");
		*tipo = 2;
		*multi = 6;
		*coste = 2;
		break;
	case 21:
		strcpy(nombre, "\033[1;3;32mCorte Atemporal\033[0m /");
		strcpy(descrip, "Un corte tan veloz que quizá corte el pasado. /");
		*tipo = 3;
		*multi = 6;
		*coste = 1;
		break;
		
	default:
	return 0;
	}

	return 1;
}

//Muestra las Habilidades
void habilidades(int hueco[3], int opcionActiva, int claseJugador)
{
	printf("\033[1;2;3;4;37m\nHABILIDADES DISPONIBLES\033[0m\n");

	int id, tipoS, coste, i;
	float multi;
	char nombre[100];
	char descrip[300];

	for (i = 0; i < 3; i++) {
		id = hueco[i];

        if (id == 0 && i > 0) {
            if (i == opcionActiva) printf("\033[1;31m > \033[0m");
            else printf("   ");
            printf("\033[1mEquipa \033[1;35mArma %i\033[0m\n", i);
        } else if (asignarHabilidades(id, nombre, descrip, &tipoS, &multi, &coste, claseJugador)) {
            if (i == opcionActiva) printf("\033[1;31m > \033[0m");
            else printf("   ");
			printf("\033[0m");
			printf("%s", nombre);
			printf("%s", descrip);

			// Mostrar el tipo y multiplicador de habilidad
			switch (tipoS) {
			case 1:
				printf("\033[3;31m ψ A x %.1f \033[0m /", multi);

				break;
			case 2:
				printf("\033[3;34m ★ M x %.1f \033[0m /", multi);
				break;
			case 3:
				printf("\033[3;32m ➹ A x %.1f \033[0m /", multi);
				break;
			default:
				printf(" - ");
				break;
			}
            if (coste < 0) {
                printf("\033[3;36m ✦ Recupera: %i \033[0m ", -coste);
            } else if (coste > 0) {
                printf("\033[3;36m ✦ Coste: %i \033[0m ", coste);
            }
		    printf("\n");

		} else {
            if (i == opcionActiva) printf("\033[1;31m > \033[0m");
            else printf("   ");
			printf("\033[1mHabilidad no disponible\033[0m\n");
		}
	}
	printf("\033[1;37m───────────────────────\033[0m\n");
}
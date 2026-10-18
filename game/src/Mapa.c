//Genera las habitaciones
void generarHabitaciones(int r[7][7])
{

	int i, j, camino;

	camino = rand() % 3;
	r[1][1] = -1; //Entrada
	r[5][5] = -2; //Salida

	switch (camino) //Camino
	{
	case 0:
		r[2][1] = 1;
		r[3][1] = 1;
		r[4][1] = 1;
		r[5][1] = 1;
		r[5][2] = 1;
		r[5][3] = 1;
		r[5][4] = 1;
		break;
	case 1:
		r[1][2] = 1;
		r[1][3] = 1;
		r[1][4] = 1;
		r[1][5] = 1;
		r[2][5] = 1;
		r[3][5] = 1;
		r[4][5] = 1;
		break;
	case 2:
		r[1][2] = 1;
		r[2][2] = 1;
		r[3][2] = 1;
		r[3][3] = 1;
		r[4][3] = 1;
		r[4][4] = 1;
		r[4][5] = 1;
		break;
	}
	for(j = 1; j < 6; j++)
	{
		for(i = 1; i < 6; i++)
		{
			if (r[j - 1][i] == 1 || r[j][i - 1] == 1 ||r[j + 1][i] == 1 || r[j][i + 1] == 1)
			{
				if (r[j][i] == 0)
				{
					r[j][i] = rand() % 2;
				}
			}
		}
	}
	for(j = 1; j < 6; j++)
	{
		for(i = 1; i < 6; i++)
		{
			if (r[j][i] == 1)
			{
				r[j][i] = rand() % 5 + 1;
			}
		}
	}
}

void moverseMapa(int map[7][7], int pos[7][7], int x, int y)
{
    int direcciones[4] = {0,0,0,0};
    int tecla = 0;

    printf("\033[1;2m(Usa W/A/S/D o flechas para moverte)\n");

    // Detectar posibles movimientos
    if ((map[y][x + 1] < 6 && map[y][x + 1] > 0) || map[y][x + 1] < 0) {
        printf("\033[0;1m[D] Mover derecha\033[0m\n");
        direcciones[0] = 1;
    }
    if ((map[y][x - 1] < 6 && map[y][x - 1] > 0) || map[y][x - 1] < 0) {
        printf("\033[0;1m[A] Mover izquierda\033[0m\n");
        direcciones[1] = 1;
    }
    if ((map[y + 1][x] < 6 && map[y + 1][x] > 0) || map[y + 1][x] < 0) {
        printf("\033[0;1m[S] Mover abajo\033[0m\n");
        direcciones[2] = 1;
    }
    if ((map[y - 1][x] < 6 && map[y - 1][x] > 0) || map[y - 1][x] < 0) {
        printf("\033[0;1m[W] Mover arriba\033[0m\n");
        direcciones[3] = 1;
    }

    // Esperar tecla válida
    do {
        tecla = getch();

        // Detectar flechas en Windows
        if (tecla == 224) {
            tecla = getch();
            switch(tecla) {
                case 72: tecla = 'w'; break; // Flecha arriba
                case 80: tecla = 's'; break; // Flecha abajo
                case 75: tecla = 'a'; break; // Flecha izquierda
                case 77: tecla = 'd'; break; // Flecha derecha
            }
        }

        if (tecla == 9) { // Solo TAB: volver al menú y guardar
            g_solicitarMenu = 1;
            return;
        }

    } while (tecla != 'w' && tecla != 'a' && tecla != 's' && tecla != 'd' &&
             tecla != 'W' && tecla != 'A' && tecla != 'S' && tecla != 'D');

    // Aplicar movimiento
    switch(tecla) {
        case 'a': case 'A':
            if (direcciones[1]) { pos[y][x] = 0; pos[y][x-1] = 1; }
            break;
        case 'd': case 'D':
            if (direcciones[0]) { pos[y][x] = 0; pos[y][x+1] = 1; }
            break;
        case 'w': case 'W':
            if (direcciones[3]) { pos[y][x] = 0; pos[y-1][x] = 1; }
            break;
        case 's': case 'S':
            if (direcciones[2]) { pos[y][x] = 0; pos[y+1][x] = 1; }
            break;
    }
}

//Vacía la habitación
void vaciarHabitacion(int r[7][7], int pos[7][7])
{
	int j, i;
	for(j = 0; j < 7; j++)
	{
		for(i = 0; i < 7; i++)
		{
			if(pos[j][i] == 1)
			{
				r[j][i] = 1;
			}
		}
	}
}

//Muestra el mapa
void mostrarMapa(int r[7][7],int pos[7][7], int *id)
{
	int i, j, x, y;
	printf("\n");
	printf("\033[1;3;4;37m        MAPA         \033[0m\n");
	for(j = 0; j < 7; j++)
	{
		for(i = 0; i < 7; i++)
		{

			switch(r[j][i])
			{
			case 1:
				//Sala sin nada
				if (pos[j][i]==1)
				{
					printf("\033[1;34;47m[@]\033[1;0m");
					x = i;
					y = j;
					*id = 0;
				}
				else
				{
					printf("\033[1;30;47m[ ]\033[1;0m");

				}
				break;
			case 2:
				//Sala con enemigo
				if (pos[j][i]==1)
				{
					printf("\033[1;37;47m[\033[1;31;47mE\033[1;37;47m]\033[1;0m");
					x = i;
					y = j;
					*id = 1;
				}
				else
				{
					printf("\033[1;30;47m[\033[1;31;47mE\033[1;30;47m]\033[1;0m");

				}
				break;
			case 3:
			case 4:
				//Sala con tesoro
				if (pos[j][i]==1)
				{
					printf("\033[1;37;47m[\033[1;33;47mT\033[1;37;47m]\033[1;0m");
					x = i;
					y = j;
					*id = 2;
				}
				else
				{
					printf("\033[1;30;47m[\033[1;33;47mT\033[1;30;47m]\033[1;0m");
				}
				break;
			case -1:
				//Entrada
				if (pos[j][i]==1)
				{
					printf("\033[1;34;47m[@]\033[1;0m");
					x = i;
					y = j;
					*id = 0;
				}
				else
				{
					printf("\033[1;30;47m[E]\033[1;0m");
				}
				break;
			case -2:
				//Salida
				if (pos[j][i]==1)
				{
					printf("\033[1;34;47m[@]\033[1;0m");
					x = i;
					y = j;
					*id = 3;
				}
				else
				{
					printf("\033[1;30;47m[S]\033[1;0m");
				}
				break;
			case 0:
			case 6:
				printf("\033[1;37;40m   \033[1;0m");
				break;
			default:
				//Sala normal
				if (pos[j][i]==1)
				{
					printf("\033[1;34;47m[@]\033[1;0m");
					x = i;
					y = j;
					*id = 0;
				}
				else
				{
					printf("\033[1;30;47m[ ]\033[1;0m");

				}
				break;

			}

		}
		printf("\n");
	}
	if(*id == 0)
	{
		moverseMapa(r, pos, x, y);
	}
}


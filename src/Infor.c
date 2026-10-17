void espacio()
{
	int spc = 10;
	for (int i = 0; i  < spc; i++)
	{
		printf(" ");
	}
}

void barraDeVida(int *vida, int *vidaMax)
{
	printf("\033[3;31m♥ \033[1;37;0m|\033[1;37;41m");
	int i;
	if (*vida > *vidaMax)
	{
	    *vida = *vidaMax;
	}
	for(i = 1; i <= *vida; i++)
	{
		printf(" ");
	}
	for(i = 1; i <= *vidaMax - *vida; i++)
	{
		printf("\033[1;37;40m ");
	}
	printf("\033[1;37;0m| [%i/%i]   ", *vida, *vidaMax);
}

void barraDeMana(int *mana, int *manaMax)
{
	printf("\033[3;36m✦ \033[1;37;0m|\033[1;37;46m");
	int i;
	if (*mana > *manaMax)
	{
	    *mana = *manaMax;
	}
	for(i = 1; i <= *mana; i++)
	{
		printf(" ");
	}
	for(i = 1; i <= *manaMax - *mana; i++)
	{
		printf("\033[1;37;40m ");
	}
	printf("\033[1;37;0m| [%i/%i]\n", *mana, *manaMax);


}

void infoJugador(int claseJugador, char nombreJugador[])
{
	printf(" \033[1;33m'%s'\033[0;1m ", nombreJugador);
	fflush(stdout);

	switch(claseJugador)
	{
		case 0:
		printf("\033[1m\033[35m[Guerrero]\033[0m\n");
		break;

		case 1:
		printf("\033[1m\033[34m[Mago]\033[0m\n");
		break;

		case 2:
		printf("\033[1m\033[31m[Asesino]\033[0m\n");
		break;
	}
}

void mostrarStats(int stats[4], int id)
{
	switch (id)
	{
	case 0:
	case 5:
		printf("------------------------------------------------------------------------------\n");
		break;
	case 1:
		printf("\033[1;3;31m ψ ATAQUE [\033[1;37;0m%i\033[1;3;31m]\033[1;37;0m   ", stats[0]);
		break;
	case 2:
		printf("\033[1;3;34m ★ MÁGIA [\033[1;37;0m%i\033[1;3;34m]\033[1;37;0m   ", stats[1]);
		break;
	case 3:
		printf("\033[1;3;32m ➹ AGILIDAD [\033[1;37;0m%i\033[1;3;32m]\033[1;37;0m   ", stats[2]);
		break;
	case 4:
		printf("\033[1;3;35m ♢ DEFENSA [\033[1;37;0m%i\033[1;3;35m]\033[1;37;0m\n", stats[3]);
		break;
	default:
	break;	
	}
}

void barraDeVidaEnemigo(int *vida, int *vidaMax)
{
	printf("\033[2;31m♥ \033[1;37;0m|\033[2;37;41m");
	int i;
	for(i = 1; i <= *vida; i++)
	{
		printf(" ");
	}

	for(i = 1; i <= *vidaMax-*vida; i++)
	{
		printf("\033[2;37;40m ");
	}
	printf("\033[1;37;0m| [%i/%i]\n\n", *vida, *vidaMax);
}


void mostrarInformacion(int *vidaEne, int *vidaMaxEne, int *vida, int *vidaMax, int *mana, int *manaMax,int stat[4], char eneImg[300], char eneNom[100], int claseJugador, char nomJugador[])
{
	int i, j;

	printf("%s", eneImg);
	printf("%s: ", eneNom);

	barraDeVidaEnemigo(vidaEne, vidaMaxEne);

	infoJugador(claseJugador, nomJugador);

	barraDeVida(vida, vidaMax);
	for(j = 0; j < 10; j++)
	{
		switch (j)
		{
		case 0:
			barraDeMana(mana, manaMax);
			break;
		default:
			mostrarStats(stat, j - 1);
			break;
		}

	}
}


struct Enemigos {
	char imgEnemigo[2000]; // Cadena con capacidad para varias líneas
	char nombreEnemigo[100]; // Otra cadena
	int vida; // Número entero
	int ataque;
	int xp;
};

void faseFinalSadowLord()
{
	tituloPlantaDungeon(4, 0);
}

void escogerEnemigo(char img[2000], char nom[100], int id, int* vidaMax, int* atak)
{
	struct Enemigos asignar;

	switch (id)
	{
	case 1:
		asignar.imgEnemigo[0] = '\0';
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "              `-`)                \n");
		strcat(asignar.imgEnemigo, "             ( \033[1;31moº\033[0m>\n");
		strcat(asignar.imgEnemigo, "             _) (                 \n");
		strcat(asignar.imgEnemigo, "            /    )                \n");
		strcat(asignar.imgEnemigo, "           /_,'  /                \n");
		strcat(asignar.imgEnemigo, "            \\  /                 \n");
		strcat(asignar.imgEnemigo, "         ===m\"\"m===             \n");

		strcpy(asignar.nombreEnemigo, "Pájaro");


		asignar.vida = 6;

		asignar.ataque = 3;
		break;

	case 2:
		asignar.imgEnemigo[0] = '\0';
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "              .---.\n");
		strcat(asignar.imgEnemigo, "         (\\./)     \\.......-\n");
		strcat(asignar.imgEnemigo, "         >\033[1m\033[31mo o\033[0m<  (__.'\"\"\"\"\n");
		strcat(asignar.imgEnemigo, "         \" ` \" \"\n");

		strcpy(asignar.nombreEnemigo, "Rata");

		asignar.vida = 5;

		asignar.ataque = 2;
		break;

	case 3:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t\\\\\n");
		strcat(asignar.imgEnemigo, "\t \\\\_\n");
		strcat(asignar.imgEnemigo, "\t ( \033[1m\033[31mo\033[0m\\\n");
		strcat(asignar.imgEnemigo, "\t / \\\\__\n");
		strcat(asignar.imgEnemigo, "\t/ _/`\"\"\n");
		strcat(asignar.imgEnemigo, "\t{\\  )_\n");
		strcat(asignar.imgEnemigo, "\t`\"\"\"`\n");

		strcpy(asignar.nombreEnemigo, "Conejo");

		asignar.vida = 6;

		asignar.ataque = 2;
		break;

	case 4:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t ____\n");
		strcat(asignar.imgEnemigo, "\t;----\"\"\033[1m\033[31m(#)\033[0m\n");
		strcat(asignar.imgEnemigo, "\t '--|-|'|'\n");
		strcat(asignar.imgEnemigo, "\t   /  |  \\\n");

		strcpy(asignar.nombreEnemigo, "Mosca");

		asignar.vida = 12;
		
		asignar.ataque = 6;
		break;

	case 5:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t    _  _\n");
		strcat(asignar.imgEnemigo, "\t   | )/ )\n");
		strcat(asignar.imgEnemigo, "\t\\\\ |//,' __\n");
		strcat(asignar.imgEnemigo, "\t(\033[1m\033[31mº\033[0m)(_)-\"()))=-\n");
		strcat(asignar.imgEnemigo, "\t   (\\\\\n");

		strcpy(asignar.nombreEnemigo, "Abeja");

		asignar.vida = 13;
		
		asignar.ataque = 7;
		break;

	case 6:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t         _\n");
		strcat(asignar.imgEnemigo, "\t.\"\"\"\"\"\">\033[1m\033[31m(8)\033[0m_\n");
		strcat(asignar.imgEnemigo, "\t `(/_|_\\)   \\\n");
		strcat(asignar.imgEnemigo, "\t  /  |  \\     \"\n");

		strcpy(asignar.nombreEnemigo, "Mosquito");

		asignar.vida = 10;
		
		asignar.ataque = 9;
		break;

	case 7:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t    _   ,_,   _\n");
		strcat(asignar.imgEnemigo, "\t   / `'=) (='` \\\n");
		strcat(asignar.imgEnemigo, "\t  /.-.-.\\ /.-.-.\\\n");
		strcat(asignar.imgEnemigo, "\t  `      \"      `\n");

		strcpy(asignar.nombreEnemigo, "Murciélago");

		asignar.vida = 30;
		
		asignar.ataque = 20;
		break;

	case 8:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");	
		strcat(asignar.imgEnemigo, "\t  / _ \\\n");
		strcat(asignar.imgEnemigo, "\t\\_\\(_)/_\\\n");
		strcat(asignar.imgEnemigo, "\t _//\"\\\\_\n");
		strcat(asignar.imgEnemigo, "\t  /   \\\n");

		strcpy(asignar.nombreEnemigo, "Araña");

		asignar.vida = 33;
		
		asignar.ataque = 23;
		break;

	case 9:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");	
		strcat(asignar.imgEnemigo, "\t      __         7`-. \n");
		strcat(asignar.imgEnemigo, "\t   ,;- `.7_7_;_, _ ))\n");
		strcat(asignar.imgEnemigo, "\t   .._, ( _ _ _,--''\n");
		strcat(asignar.imgEnemigo, "\t    `-'';'_;_; '\n");

		strcpy(asignar.nombreEnemigo, "Escorpión");

		asignar.vida = 30;
		
		asignar.ataque = 20;
		break;


	}

	*vidaMax = asignar.vida;
	*atak = asignar.ataque;
	strcpy(img, asignar.imgEnemigo);
	strcpy(nom, asignar.nombreEnemigo);
}

void escogerJefe(char img[2000], char nom[100], int id, int* vidaMax, int* atak)
{
	struct Enemigos asignar;

	switch (id)
	{
	case 1:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t///,        ////\n");
		strcat(asignar.imgEnemigo, "\t\\  /,      /  >.\n");
		strcat(asignar.imgEnemigo, "\t \\  /,   _/  /.\n");
		strcat(asignar.imgEnemigo, "\t  \\_  /_/   /.\n");
		strcat(asignar.imgEnemigo, "\t   \\__/_   < \n");
		strcat(asignar.imgEnemigo, "\t   /<<< \\\\_\\\n");
		strcat(asignar.imgEnemigo, "\t  /\033[1m\033[31mo\033[0m)^>>_._ \\\n");
		strcat(asignar.imgEnemigo, "\t  (/   \\\\ /\\\\\\\n");
		strcat(asignar.imgEnemigo, "\t       // //```\n");
		strcat(asignar.imgEnemigo, "\t======((`((====\n");

		strcpy(asignar.nombreEnemigo, "\033[1mÁguila\033[0m");


		asignar.vida = 12;

		asignar.ataque = 4;
		
		break;
	case 2:
		asignar.imgEnemigo[0] = '\0';
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t    .----.   \033[1m\033[31mO\033[0m   \033[1m\033[31mO\033[0m\n");
		strcat(asignar.imgEnemigo, "\t   / .-\"-.`.  \\\\ /\n");
		strcat(asignar.imgEnemigo, "\t   | | '\\\\ \\\\/ )\n");
		strcat(asignar.imgEnemigo, "\t ,-\\ `-.' /.'  /\n");
		strcat(asignar.imgEnemigo, "\t'---`----'----'\n");

		strcpy(asignar.nombreEnemigo, "Caracol");

		asignar.vida = 20;
		
		asignar.ataque = 8;
		break;
		
	case 3:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t (`-''-/`).___..--''`-._\n");
		strcat(asignar.imgEnemigo, "\t  `\033[1m\033[31mo\033[0m \033[1m\033[31mo\033[0m  )   `-.  (     ).`-.__.`)\n");
		strcat(asignar.imgEnemigo, "\t  (_Y_.)'  ._   )  `._ `. ``-..-'\n");
		strcat(asignar.imgEnemigo, "\t _..`--'_..-_/  /--'_.' ,'\n");
		strcat(asignar.imgEnemigo, "\t(il),-''  (li),'  ((!.-'\n");

		strcpy(asignar.nombreEnemigo, "Pantera");

		asignar.vida = 22;
		
		asignar.ataque = 12;
		break;

	case 4:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t                     .\n");
		strcat(asignar.imgEnemigo, "\t                    / V\\\n");
		strcat(asignar.imgEnemigo, "\t                  / \033[1;31mo\033[0m  /\n");
		strcat(asignar.imgEnemigo, "\t                 <<   |\n");
		strcat(asignar.imgEnemigo, "\t                 /    |\n");
		strcat(asignar.imgEnemigo, "\t               /      |\n");
		strcat(asignar.imgEnemigo, "\t             /        |\n");
		strcat(asignar.imgEnemigo, "\t           /    \\  \\ /\n");
		strcat(asignar.imgEnemigo, "\t          (      ) | |\n");
		strcat(asignar.imgEnemigo, "\t  ________|   _/_  | |\n");
		strcat(asignar.imgEnemigo, "\t<__________\\______)\\__)\n");

		strcpy(asignar.nombreEnemigo, "Lobo");

		asignar.vida = 26;
		
		asignar.ataque =19;
		break;

	case 5:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t ___     ___________\n");
		strcat(asignar.imgEnemigo, "\t(__\033[1;31m@\033[0m\\   (__<>___<>__ \\\\    _\033[1m\033[31moo\033[0m_\n");
		strcat(asignar.imgEnemigo, "\t   \\\\_(__<>___<>__)\\@\\_/@___/\n");
		strcat(asignar.imgEnemigo, "\t    \\\\@__<>___<>___<>)\\___/\n");

		strcpy(asignar.nombreEnemigo, "Reina Serpiente");

		asignar.vida = 40;
		
		asignar.ataque = 22;
		break;

	case 6:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\t ___    ___\n");
		strcat(asignar.imgEnemigo, "\t( _<    >_ )\n");
		strcat(asignar.imgEnemigo, "\t//        \\\n");
		strcat(asignar.imgEnemigo, "\t\\\\___..___//\n");
		strcat(asignar.imgEnemigo, "\t `-(    )-'\n");
		strcat(asignar.imgEnemigo, "\t   _|__|_\n");
		strcat(asignar.imgEnemigo, "\t  /_|__|_\\\n");
		strcat(asignar.imgEnemigo, "\t  /_\\__/_\\\n");
		strcat(asignar.imgEnemigo, "\t   \\ || /  _)\n");
		strcat(asignar.imgEnemigo, "\t     ||   ( )\n");
		strcat(asignar.imgEnemigo, "\t     \\\\___//\n");
		strcat(asignar.imgEnemigo, "\t      `---'\n");

		strcpy(asignar.nombreEnemigo, "Rey Escorpión");

		asignar.vida = 45;
		
		asignar.ataque = 27;
		break;

	case 7:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t     (()__(()\n");
		strcat(asignar.imgEnemigo, "\t     /       \\\n");
		strcat(asignar.imgEnemigo, "\t     \\\033[1;31m0  0\033[0m    |\n");
		strcat(asignar.imgEnemigo, "\t     (_()_)__/ \\ \n");
		strcat(asignar.imgEnemigo, "\t    / _,  .____ \\\n");
		strcat(asignar.imgEnemigo, "\t   (   |  |      )\n");
		strcat(asignar.imgEnemigo, "\t   /\\_.|  |'-.__/\\_\n");
		strcat(asignar.imgEnemigo, "\t  / (        /     \\ \n");
		strcat(asignar.imgEnemigo, "\t  \\  \\      (      /\n");
		strcat(asignar.imgEnemigo, "\t   )  '._____)    / \n");
		strcat(asignar.imgEnemigo, "\t(((____.--(((____/\n");

		strcpy(asignar.nombreEnemigo, "Oso");

		asignar.vida = 50;
		
		asignar.ataque = 34;
		break;

	case 8:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "\n");
		strcat(asignar.imgEnemigo, "\t        /\\  .-----.  /\\\n");
		strcat(asignar.imgEnemigo, "\t       //\\\\/  ,,,  \\//\\\n");
		strcat(asignar.imgEnemigo, "\t       |/\\| ,;;;;;, |/\\|\n");
		strcat(asignar.imgEnemigo, "\t       //\\\\;-   -;///\\\n");
		strcat(asignar.imgEnemigo, "\t      //  \\/   .   \\/  \\\n");
		strcat(asignar.imgEnemigo, "\t     (| ,-_| \\ | / |_-, |)\n");
		strcat(asignar.imgEnemigo, "\t       //`__\\.-.-./__`\\\n");
		strcat(asignar.imgEnemigo, "\t      // /.-(\033[1;31m() ()\033[0m)-.\\ \\\\\n");
		strcat(asignar.imgEnemigo, "\t     (\\ |)   '---'   (| /)\n");
		strcat(asignar.imgEnemigo, "\t      ` (|           |) `\n");
		strcat(asignar.imgEnemigo, "\t        \\)           (/\n");

		strcpy(asignar.nombreEnemigo, "Araña Gigante");

		asignar.vida = 60;
		
		asignar.ataque = 40;
		break;

	case 9:
		asignar.imgEnemigo[0] = '\0';

		strcat(asignar.imgEnemigo, "                              ______________                               \n");
		strcat(asignar.imgEnemigo, "                        ,===:'.,            `-._                           \n");
		strcat(asignar.imgEnemigo, "                             `:.`---.__         `-._                       \n");
		strcat(asignar.imgEnemigo, "                               `:.     `--.         `.                     \n");
		strcat(asignar.imgEnemigo, "                                 \\.        `.         `.                   \n");
		strcat(asignar.imgEnemigo, "                         (,,(,    \\.         `.   ____,-`.,                \n");
		strcat(asignar.imgEnemigo, "                      (,'     `/   \\.   ,--.___`.'                         \n");
		strcat(asignar.imgEnemigo, "                  ,  ,'  ,--.  `,   \\.;'         `                         \n");
		strcat(asignar.imgEnemigo, "                   `{\033[1;35mD\033[0m, {    \\  :    \\;                                     \n");
		strcat(asignar.imgEnemigo, "                     V,,'    /  /    //                                     \n");
		strcat(asignar.imgEnemigo, "                     j;;    /  ,' ,-//.    ,---.      ,                    \n");
		strcat(asignar.imgEnemigo, "                     \\\\;'   /  ,' /  _  \\  /  _  \\\\   ,'\\/                    \n");
		strcat(asignar.imgEnemigo, "                           \\   `'  / \\  `'  / \\  `.' /                     \n");
		strcat(asignar.imgEnemigo, "                            `.___,'   `.__,'   `.__,' \n");

		strcpy(asignar.nombreEnemigo, "Shadow Lord");

		asignar.vida = 200;
		
		asignar.ataque = 170;
		break;

	}

	*vidaMax = asignar.vida;
	*atak = asignar.ataque;
	strcpy(img, asignar.imgEnemigo);
	strcpy(nom, asignar.nombreEnemigo);
}


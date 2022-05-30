void menu(int x, int y, int &opc){
	char tecla='\0'; //' '
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){	//Flecha arriba
				y--;
				opc--;
			}
			if(opc<7&&tecla==80){	//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c", 16);
		}
	}while(tecla!=13); //13 --> enter
}

void menu_1(int x, int y, int &opc){
	char tecla='\0'; //' '
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){	//Flecha arriba
				y--;
				opc--;
			}
			if(opc<3&&tecla==80){	//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c", 16);
		}
	}while(tecla!=13); //13 --> enter
}

void menu_2(int x, int y, int &opc){
	char tecla='\0'; //' '
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){	//Flecha arriba
				y--;
				opc--;
			}
			if(opc<2&&tecla==80){	//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c", 16);
		}
	}while(tecla!=13); //13 --> enter
}

void menu_3(int x, int y, int &opc){
	char tecla='\0'; //' '
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){	//Flecha arriba
				y--;
				opc--;
			}
			if(opc<4&&tecla==80){	//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c", 16);
		}
	}while(tecla!=13); //13 --> enter
}

void menu_4(int x, int y, int &opc){
	char tecla='\0'; //' '
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){	//Flecha arriba
				y--;
				opc--;
			}
			if(opc<2&&tecla==80){	//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c", 16);
		}
	}while(tecla!=13); //13 --> enter
}

void menu_5(int x, int y, int &opc){
	char tecla='\0'; //' '
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){	//Flecha arriba
				y--;
				opc--;
			}
			if(opc<2&&tecla==80){	//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c", 16);
		}
	}while(tecla!=13); //13 --> enter
}

void menu_6(int x, int y, int &opc){
	char tecla='\0'; //' '
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){	//Flecha arriba
				y--;
				opc--;
			}
			if(opc<6&&tecla==80){	//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c", 16);
		}
	}while(tecla!=13); //13 --> enter
}

void menu1(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int continuar = 0;
	
	while (opc != 3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Consulta General\n");
		gotoxy(x,++y);
		printf("2. Consulta por Codigo\n");
		gotoxy(x,++y);
		printf("3. Regresar\n");
		gotoxy(x,++y);
		menu_1(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				printf("Consulta General***\n\n\n");
				imprimirEsctrucutura();
				printf("\n\n");
				leer_archivo();
				getch();
				break;
			case OPC2:
				do{
					system("cls");
					printf("Buscar por Codigo***\n\n\n");
					buscarCodigo_archivo();
					continuar = validaEntero("\nDeseas realizar otra busqueda? 1 para si, otro para no: ");
				}while(continuar == 1);
				//getch();
				break;
			case OPC3:
				//getch();
				break;
		}
	}
	
	//getch();
}

void menu2(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int continuar = 0;
	
	while (opc != 2){
		system("color 02");
		x = 25;
		y = 5;
		bool bandera = false;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Agregar un registro\n");
		gotoxy(x,++y);
		printf("2. Regresar\n");
		gotoxy(x,++y);
		menu_2(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				do{
					system("cls");
					printf("Agrega Registro***\n\n\n");
					leer_archivo();
					agregarRegisAnalisis();
					system("cls");
					leer_archivo();
					continuar = validaEntero("Deseas realizar otro registro? 1 para si, otro para no: ");
				}while(continuar == 1);
				break;
			case OPC2:
				//getch();
				break;
		}
	}
	
	//getch();
}

void menu3(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int continuar = 0;
	
	while (opc != 4){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Modificar precios\n");
		gotoxy(x,++y);
		printf("2. Modificar condiciones\n");
		gotoxy(x,++y);
		printf("3. Modifica Registro (Precios y condiciones)\n");
		gotoxy(x,++y);
		printf("4. Regresar\n");
		gotoxy(x,++y);
		menu_3(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				do{
					system("cls");
					printf("Modificar Precios***\n\n\n");
					leer_archivo();
					printf("\n\n");
					modificaPrecio();
					fflush(stdin);
					getch();
					system("cls");
					leer_archivo();
					//getch();
					continuar = validaEntero("Deseas realizar otra modificacion? 1 para si, otro para no: ");
				}while(continuar == 1);
				break;
			case OPC2:
				do{
					system("cls");
					printf("Modificar Condiciones***\n\n\n");
					leer_archivo();
					printf("\n\n");
					modificaCondicion();
					fflush(stdin);
					getch();
					system("cls");
					leer_archivo();
					//getch();
					continuar = validaEntero("Deseas realizar otra modificacion? 1 para si, otro para no: ");
				}while(continuar == 1);
				break;
			case OPC3:
				do{
					system("cls");
					printf("Modifica Registro (Precios y condiciones)***\n\n\n");
					leer_archivo();
					printf("\n\n");
					modifRegisAnalisis();
					fflush(stdin);
					getch();
					system("cls");
					leer_archivo();
					//getch();
					continuar = validaEntero("Deseas realizar otra modificacion? 1 para si, otro para no: ");
				}while(continuar == 1);
				break;
			case OPC4:
				//getch();
				break;
		}
	}
	
	//getch();
}

void menu4(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int continuar = 0;
	
	while (opc != 2){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Registro de pruebas\n");
		gotoxy(x,++y);
		printf("2. Regresar\n");
		gotoxy(x,++y);
		menu_4(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
					printf("Registro de pruebas***\n\n\n");
					agregarDinamico();
				break;
			case OPC2:
				//getch();
				break;
		}
	}
	
	//getch();
}

void menu5(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int continuar = 0;
	
	while (opc != 2){
		system("color 02");
		x = 25;
		y = 5;
		bool bandera = false;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Modificar estado de la prueba\n");
		gotoxy(x,++y);
		printf("2. Regresar\n");
		gotoxy(x,++y);
		menu_5(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				do{
					system("cls");
					leerEncabezado();
					modificaPrueba();
					continuar = validaEntero("\nDeseas realizar otra modificacion? 1 para si, otro para no: ");
				}while(continuar == 1);
				break;
			case OPC2:
				//getch();
				break;
		}
	}
	
	//getch();
}

void menu6(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int continuar = 0;
	
	while (opc != 6){
		system("color 02");
		x = 25;
		y = 4;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("Consultar por:\n");
		gotoxy(x,++y);
		printf("1. Pruebas Activas\n");
		gotoxy(x,++y);
		printf("2. Pruebas Realizadas\n");
		gotoxy(x,++y);
		printf("3. Pruebas Enviadas\n");
		gotoxy(x,++y);
		printf("4. Pruebas Canceladas\n");
		gotoxy(x,++y);
		printf("5. Numero de Prueba\n");
		gotoxy(x,++y);
		printf("6. Regresar\n");
		gotoxy(x,++y);
		menu_6(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				ConsultaActivo();
				getch();
				break;
			case OPC2:
				ConsultaRealizado();
				getch();
				break;
			case OPC3:
				ConsultaEnviado();
				getch();
				break;
			case OPC4:
				ConsultaCancelado();
				getch();
				break;
			case OPC5:
				do{
					system("cls");
					ConsultaPrueba();
					continuar = validaEntero("\nDeseas realizar otra consulta? 1 para si, otro para no: ");
				}while(continuar == 1);
				break;
			case OPC6:
				break;
		}
	}
	//getch();
}

void menuProyecto(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int continuar = 0;
	
	while (opc != 7){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(x,y);
		printf("1. Listado de precios y consulta de condiciones\n");
		gotoxy(x,++y);
		printf("2. Agregar un nuevo registro\n");
		gotoxy(x,++y);
		printf("3. Actualizar datos(precio y condiciones)\n");
		gotoxy(x,++y);
		printf("4. Registro de pruebas\n");
		gotoxy(x,++y);
		printf("5. Modificar estado de la prueba\n");
		gotoxy(x,++y);
		printf("6. Consulta de prueba\n");
		gotoxy(x,++y);
		printf("7. Salir del sistema\n");
		/*printf("\nDame la opción: ");
		scanf("%d", &opc);*/
		menu(22,5,opc);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				menu1();
				//getch();
				break;
			case OPC2:
				menu2();
				break;
			case OPC3:
				menu3();
				break;
			case OPC4:
				menu4();
				break;
			case OPC5:
				menu5();
				break;
			case OPC6:
				menu6();
				break;
			case OPC7:
				system("color 60");
				printf("Adiós :(");
				exit(0);
		/*	default:
				printf("No existe la opción\n");
				getch();
				break;	*/
		}
	}
	
	getch();
}


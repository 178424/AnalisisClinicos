float validaFlotante(const char mensaje[]){
	int continuar=0;
	float flotante=0;
	//float num = 0;
	
	do{
		//system("cls");
		//system("color 0C");
		printf("%s", mensaje);
		continuar = scanf("%f", &flotante);
		//continuar = scanf("%f", &num);
		fflush(stdin);	
	}while (continuar != 1);
	
	return flotante;
	//return num;
}

int validaEntero(const char mensaje[]){
	int continuar=0;
	int entero=0;
	//float num = 0;
	
	do{
		//system("cls");
		//system("color 03");
		printf("%s", mensaje);
		continuar = scanf("%i", &entero);
		//continuar = scanf("%f", &num);
		fflush(stdin);	
	}while (continuar != 1);
	
	//system("cls");
	return entero;
}

void validaCadena(const char mensaje[], char cadena[]){
	//setlocale(LC_TYPE, "Spanish");
	SetConsoleCP(1252); //STDIN codificación de windows 1252
	SetConsoleOutputCP(1252); //STDOUT
	bool bandera = true;
	
	do{
		//system("cls");
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena) == 0){
			bandera=true;
		}else{
			if((cadena[0] == ' ') || (cadena[0] == '\0')){
				bandera=true;
			}else{
				for(int i = 0; i<strlen(cadena); i++){
					if(isalpha(cadena[i]) || cadena [i]==' '){
						if (i== (strlen(cadena)-1)){
							bandera=false;
						}
					}else{
						break;
					}
				}
			}
		}
	}while(bandera==true);
}

void validaCadYNum(const char mensaje[], char cadena[]){
	//setlocale(LC_TYPE, "Spanish");
	SetConsoleCP(1252); //STDIN codificación de windows 1252
	SetConsoleOutputCP(1252); //STDOUT
	bool bandera = true;
	
	do{
		//system("cls");
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena) == 0){
			bandera=true;
		}else{
			if((cadena[0] == ' ') || (cadena[0] == '\0')){
				bandera=true;
			}else{
				for(int i = 0; i<strlen(cadena); i++){
					if(isalpha(cadena[i]) || cadena [i]==' ' || isdigit(cadena[i])){
						if (i== (strlen(cadena)-1)){
							bandera=false;
						}
					}else{
						break;
					}
				}
			}
		}
	}while(bandera==true);
}

void validaCorreo(const char mensaje[], char cadena[]){
	//setlocale(LC_TYPE, "Spanish");
	SetConsoleCP(1252); //STDIN codificación de windows 1252
	SetConsoleOutputCP(1252); //STDOUT
	bool bandera = true;
	
	do{
		//system("cls");
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena) == 0){
			bandera=true;
		}else{
			if((cadena[0] == ' ') || (cadena[0] == '\0')){
				bandera=true;
			}else{
				for(int i = 0; i<strlen(cadena); i++){
					if(isalpha(cadena[i]) || cadena [i]==' ' || isdigit(cadena[i]) || cadena [i]=='.' || cadena [i]=='@' || cadena [i]=='_'){
						if (i== (strlen(cadena)-1)){
							bandera=false;
						}
					}else{
						break;
					}
				}
			}
		}
	}while(bandera==true);
}

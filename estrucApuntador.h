analisis_clinicos buscaCodigo(int codigo){
	setlocale(LC_CTYPE, "Spanish");
	bool bandera = false;
	analisis_clinicos dato;
	
	if(!(arch = fopen("Analisis_clinicos.xls", "r"))){
		printf("Error al intentar leer archivo");
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch,"%d\t", &dato.codigo);
		fscanf(arch,"%[^\t]\t", dato.nombre);
		fscanf(arch,"%f\t", &dato.precio);
		fscanf(arch,"%[^\n]\n", dato.condiciones);
	
		if(dato.codigo == codigo){
			printf("|%d|\t", dato.codigo);
			printf("|%s|\t", dato.nombre);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			printf("|%.2f|\t", dato.precio);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("|%s|\n", dato.condiciones);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			fclose(arch);
			return dato;
		}
	}
	if(bandera==false){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			printf("NO se encuentra el analisis");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		}
	//if(bandera==false) printf("NO se encuentra el analisis");
	fclose(arch);
	return dato;
}
// valida que no se repita idPrueba en el archivo
int valida_idPrueba(){
	int prueba = 0;
	bool bandera_buscar = false;
	analisis_clinicos dato;
	
	srand(time(NULL));
	do{
		prueba = rand()%99999+1;
		
		if(!(arch = fopen("encabezado.xls", "r"))){
			//printf("Error al intentar leer archivo");
			//exit(1);
			return prueba;
		}
		
		bandera_buscar=false;
		while(!feof(arch)){
			fscanf(arch, "%d\t",&regis->idPrueba);
			fscanf(arch, "%[^\t]\t",regis->estado);
			fscanf(arch, "%d\t",&regis->paciente.idPaciente);
			fscanf(arch, "%[^\t]\t",regis->paciente.nombre);
			fscanf(arch, "%d\t",&regis->paciente.edad);
			fscanf(arch, "%[^\t]\t",regis->paciente.tel);
			fscanf(arch, "%[^\t]\t",regis->paciente.correo);
			fscanf(arch, "%[^\n]\n",regis->paciente.fecha_hora);
			if(regis->idPrueba == prueba){
				bandera_buscar=true;
			}
		}
		fclose(arch);
	}while(bandera_buscar==true);
	
	return prueba;
}

void agregarDinamico(){
	setlocale(LC_CTYPE,"Spanish");
	analisis_clinicos dato = {};
	int continuar = 0;
	
	//regis->idPrueba = validaEntero("Id Prueba: ");
	//regis->idPrueba = rand()%99999+1;
	regis->idPrueba = valida_idPrueba();
	//validaCadena("Estado: ", regis->estado);
	strcpy(regis->estado,"Activo");
	printf("\n", regis->estado);
	
	//regis->paciente.idPaciente = validaEntero("Id Paciente: ");
	regis->paciente.idPaciente =rand()%999+1;
	strcpy(regis->paciente.nombre," ");
	strcpy(regis->paciente.tel," ");
	strcpy(regis->paciente.correo," ");
	strcpy(regis->paciente.fecha_hora," ");
	validaCadena("Nombre: ", regis->paciente.nombre);
	regis->paciente.edad = validaEntero("Edad: ");
	validaCadYNum("Telefono: ", regis->paciente.tel);
	validaCorreo("Correo: ", regis->paciente.correo);
	/*printf("Correo: ");
	scanf("%[^\n]", regis->paciente.correo);*/
	fflush(stdin);
	validaCadYNum("Fecha y hora: ", regis->paciente.fecha_hora);
	
	if(!(arch = fopen("encabezado.xls", "a+"))){
		printf("Error al intentar crear archivo");
		exit(1);
	}
	
	fprintf(arch, "%d\t",regis->idPrueba);
	fprintf(arch, "%s\t",regis->estado);
	fprintf(arch, "%d\t",regis->paciente.idPaciente);
	fprintf(arch, "%s\t",regis->paciente.nombre);
	fprintf(arch, "%d\t",regis->paciente.edad);
	fprintf(arch, "%s\t",regis->paciente.tel);
	fprintf(arch, "%s\t",regis->paciente.correo);
	fprintf(arch, "%s\n",regis->paciente.fecha_hora);
	fclose(arch);
	
	do{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
		printf("|%s|\t", regis->estado);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("|%s|\t", regis->paciente.nombre);
		printf("|%d|\t", regis->paciente.edad);
		printf("|%s|\t", regis->paciente.tel);
		printf("|%s|\t", regis->paciente.correo);
		printf("|%s|\n\n", regis->paciente.fecha_hora);
			
		leer_archivo();
		printf("\n\n");
		regis->detalle.idDetalle = validaCodigo();// <- esta funcion esta en estructura.h para que el codigo escogido sea uno existente en el archivo
		
		dato = buscaCodigo(regis->detalle.idDetalle); //funcion buscaCodigo
		
		regis->detalle.idPrueba = regis->idPrueba;
		regis->detalle.Analisis.codigo = dato.codigo;
		strcpy(regis->detalle.Analisis.nombre, dato.nombre);
		regis->detalle.Analisis.precio = dato.precio;
		strcpy(regis->detalle.Analisis.condiciones,dato.condiciones);
		
		if(!(arch = fopen("detalle.xls", "a+"))){
			printf("Error al intentar crear archivo");
			exit(1);
		}
		
		fprintf(arch, "%d\t",regis->detalle.idPrueba);
		fprintf(arch, "%d\t",regis->detalle.idDetalle);
		fprintf(arch, "%d\t",regis->detalle.Analisis.codigo);
		fprintf(arch, "%s\t",regis->detalle.Analisis.nombre);
		fprintf(arch, "%.2f\t",regis->detalle.Analisis.precio);
		fprintf(arch, "%s\n",regis->detalle.Analisis.condiciones);
		fclose(arch);
	
		printf("\nRegistro agregado\n\n");
		continuar = validaEntero("Quieres agregar otro analisis a este paciente? 1 para si, otro para no: ");
	}while(continuar==1);
	
	system("cls");
	
	float subtotal;
	printf("Datos del paciente:\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	printf("|%s|\t", regis->estado);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	printf("|%s|\t", regis->paciente.nombre);
	printf("|%d|\t", regis->paciente.edad);
	printf("|%s|\t", regis->paciente.tel);
	printf("|%s|\t", regis->paciente.correo);
	printf("|%s|\n\n", regis->paciente.fecha_hora);
	
	printf("Analisis a realizar:\n");
	
	if(!(arch = fopen("detalle.xls", "r"))){
		printf("Error al intentar leer archivo");
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch, "%d\t",&regis->detalle.idPrueba);
		fscanf(arch, "%d\t",&regis->detalle.idDetalle);
		fscanf(arch, "%d\t",&regis->detalle.Analisis.codigo);
		fscanf(arch, "%[^\t]\t",regis->detalle.Analisis.nombre);
		fscanf(arch, "%f\t",&regis->detalle.Analisis.precio);
		fscanf(arch, "%[^\n]\n",regis->detalle.Analisis.condiciones);
		if(regis->idPrueba == regis->detalle.idPrueba){
			
			printf("|%d|\t",regis->detalle.Analisis.codigo);
			printf("|%s|\t",regis->detalle.Analisis.nombre);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			printf("|%.2f|\t",regis->detalle.Analisis.precio);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("|%s|\n",regis->detalle.Analisis.condiciones);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			subtotal+=regis->detalle.Analisis.precio;
		}
	}
	fclose(arch);
	printf("\nEl total de los analisis es de: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	printf("%.2f", subtotal);
	
	getch();
}

// punto 5 ***

void leerEncabezado(){
	setlocale(LC_CTYPE, "Spanish");
	if(!(arch=fopen("encabezado.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	printf("\n\n---------Registros en el Archivo-----------\n\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Prueba\tEstado\t\tNombre\tEdad\tFecha\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	
	while(!feof(arch)){
		fscanf(arch, "%d\t", &regis->idPrueba);
		fscanf(arch, "%[^\t]\t", regis->estado);
		fscanf(arch, "%d\t",&regis->paciente.idPaciente);
		fscanf(arch, "%[^\t]\t",regis->paciente.nombre);
		fscanf(arch, "%d\t",&regis->paciente.edad);
		fscanf(arch, "%[^\t]\t",regis->paciente.tel);
		fscanf(arch, "%[^\t]\t",regis->paciente.correo);
		fscanf(arch, "%[^\n]\n",regis->paciente.fecha_hora);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
		printf("|%d|\t", regis->idPrueba);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
		printf("|%s|\t", regis->estado);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("|%s|\t", regis->paciente.nombre);
		printf("|%d|\t", regis->paciente.edad);
		printf("|%s|\n", regis->paciente.fecha_hora);
	}
	fclose(arch);
	printf("\n");
}

void modificaPrueba(){
	setlocale(LC_CTYPE, "Spanish");
	FILE *arch2;
	int prueba, num_estado = 0, cont = 0;
	bool bandera=false;
	
	if(!(arch=fopen("encabezado.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	if(!(arch2=fopen("copiaEncabezado.xls", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	prueba = validaEntero("\nPrueba: ");
	//system("cls");
	while(!feof(arch)){
		fscanf(arch, "%d\t", &regis->idPrueba);
		fscanf(arch, "%[^\t]\t", regis->estado);
		fscanf(arch, "%d\t",&regis->paciente.idPaciente);
		fscanf(arch, "%[^\t]\t",regis->paciente.nombre);
		fscanf(arch, "%d\t",&regis->paciente.edad);
		fscanf(arch, "%[^\t]\t",regis->paciente.tel);
		fscanf(arch, "%[^\t]\t",regis->paciente.correo);
		fscanf(arch, "%[^\n]\n",regis->paciente.fecha_hora);
		if(regis->idPrueba == prueba){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			printf("\n\nPrueba\tEstado\tIdPaciente\tNombre\tEdad\tTelefono\tCorreo\t\tFecha\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
			printf("|%d|\t",regis->idPrueba);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			printf("|%s|\t",regis->estado);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			printf("|%d|\t",regis->paciente.idPaciente);
			printf("|%s|\t",regis->paciente.nombre);
			printf("|%d|\t",regis->paciente.edad);
			printf("|%s|\t",regis->paciente.tel);
			printf("|%s|\t",regis->paciente.correo);
			printf("|%s|\n",regis->paciente.fecha_hora);
			do{
				cont++;
				// Activo
				if(strcmp(regis->estado,"Activo") == 0){
					num_estado = validaEntero("\nActualmente el estado es Activo, a que estado lo deseas modificar?\n1. Realizado\nOtro. Cancelado\n");
					if (num_estado == 1){
						strcpy(regis->estado,"Realizado");
					}else{
						strcpy(regis->estado,"Cancelado");
					}
					printf("\nPrueba Actualizada\n\n");
				}else{
					//Cancelado
					if(strcmp(regis->estado,"Cancelado") == 0){
						num_estado = validaEntero("\nActualmente el estado es Cancelado, deseas modificarlo a Activo o mantenerlo igual?\n1. Activo\nOtro. Mantener en Cancelado\n");
						if (num_estado == 1){
							strcpy(regis->estado,"Activo");
							printf("\nPrueba Actualizada\n\n");
						}
					}else{
						//Realizado
						if(strcmp(regis->estado,"Realizado") == 0){
							num_estado = validaEntero("\nActualmente el estado es realizado, deseas modificarlo a Enviado o mantenerlo igual?\n1. Enviado\nOtro. Mantener en Realizado\n");
							if (num_estado == 1){
								strcpy(regis->estado,"Enviado");
								printf("\nPrueba Actualizada\n\n");
							}
						}else{
							if(strcmp(regis->estado,"Enviado") == 0){
								printf("\nEl estado actual es Enviado, por lo cual no se puede realizar ningun cambio");
								getch();
							}
						}
					}
				}
			}while(cont!=1);
			bandera = true;
		}
		fprintf(arch2, "%d\t",regis->idPrueba);
		fprintf(arch2, "%s\t",regis->estado);
		fprintf(arch2, "%d\t",regis->paciente.idPaciente);
		fprintf(arch2, "%s\t",regis->paciente.nombre);
		fprintf(arch2, "%d\t",regis->paciente.edad);
		fprintf(arch2, "%s\t",regis->paciente.tel);
		fprintf(arch2, "%s\t",regis->paciente.correo);
		fprintf(arch2, "%s\n",regis->paciente.fecha_hora);
	}
	if(bandera==false){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			printf("No se encuentra la prueba");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	}
	fclose(arch2);
	fclose(arch);
	remove("encabezado.xls");
	rename("copiaEncabezado.xls", "encabezado.xls");
}

// Punto 6 **

//Estado Activo
void ConsultaActivo(){
	setlocale(LC_CTYPE, "Spanish");
	printf("Pruebas activas:\n\n");
	bool bandera = false;
	
	if(!(arch=fopen("encabezado.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch, "%d\t", &regis->idPrueba);
		fscanf(arch, "%[^\t]\t", regis->estado);
		fscanf(arch, "%d\t",&regis->paciente.idPaciente);
		fscanf(arch, "%[^\t]\t",regis->paciente.nombre);
		fscanf(arch, "%d\t",&regis->paciente.edad);
		fscanf(arch, "%[^\t]\t",regis->paciente.tel);
		fscanf(arch, "%[^\t]\t",regis->paciente.correo);
		fscanf(arch, "%[^\n]\n",regis->paciente.fecha_hora);
		
		if(strcmp(regis->estado,"Activo") == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
			printf("|%d|\t",regis->idPrueba);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			printf("|%s|\t",regis->estado);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			printf("|%d|\t",regis->paciente.idPaciente);
			printf("|%s|\t",regis->paciente.nombre);
			printf("|%d|\t",regis->paciente.edad);
			printf("|%s|\t",regis->paciente.tel);
			printf("|%s|\t",regis->paciente.correo);
			printf("|%s|\n",regis->paciente.fecha_hora);
			bandera=true;
		}
	}
	fclose(arch);
	if(bandera==false){
		printf("No existen registros con estado Activo");
	}
}

//Estado Realizado
void ConsultaRealizado(){
	setlocale(LC_CTYPE, "Spanish");
	printf("Pruebas Realizadas:\n\n");
	bool bandera = false;
	
	if(!(arch=fopen("encabezado.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch, "%d\t", &regis->idPrueba);
		fscanf(arch, "%[^\t]\t", regis->estado);
		fscanf(arch, "%d\t",&regis->paciente.idPaciente);
		fscanf(arch, "%[^\t]\t",regis->paciente.nombre);
		fscanf(arch, "%d\t",&regis->paciente.edad);
		fscanf(arch, "%[^\t]\t",regis->paciente.tel);
		fscanf(arch, "%[^\t]\t",regis->paciente.correo);
		fscanf(arch, "%[^\n]\n",regis->paciente.fecha_hora);
		
		if(strcmp(regis->estado,"Realizado") == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
			printf("|%d|\t",regis->idPrueba);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			printf("|%s|\t",regis->estado);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			printf("|%d|\t",regis->paciente.idPaciente);
			printf("|%s|\t",regis->paciente.nombre);
			printf("|%d|\t",regis->paciente.edad);
			printf("|%s|\t",regis->paciente.tel);
			printf("|%s|\t",regis->paciente.correo);
			printf("|%s|\n",regis->paciente.fecha_hora);
			bandera=true;
		}
	}
	fclose(arch);
	if(bandera==false){
		printf("No existen registros con estado Realizado");
	}
}

//Estado Enviado
void ConsultaEnviado(){
	setlocale(LC_CTYPE, "Spanish");
	printf("Pruebas Enviadas:\n\n");
	bool bandera = false;
	
	if(!(arch=fopen("encabezado.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch, "%d\t", &regis->idPrueba);
		fscanf(arch, "%[^\t]\t", regis->estado);
		fscanf(arch, "%d\t",&regis->paciente.idPaciente);
		fscanf(arch, "%[^\t]\t",regis->paciente.nombre);
		fscanf(arch, "%d\t",&regis->paciente.edad);
		fscanf(arch, "%[^\t]\t",regis->paciente.tel);
		fscanf(arch, "%[^\t]\t",regis->paciente.correo);
		fscanf(arch, "%[^\n]\n",regis->paciente.fecha_hora);
		
		if(strcmp(regis->estado,"Enviado") == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
			printf("|%d|\t",regis->idPrueba);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			printf("|%s|\t",regis->estado);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			printf("|%d|\t",regis->paciente.idPaciente);
			printf("|%s|\t",regis->paciente.nombre);
			printf("|%d|\t",regis->paciente.edad);
			printf("|%s|\t",regis->paciente.tel);
			printf("|%s|\t",regis->paciente.correo);
			printf("|%s|\n",regis->paciente.fecha_hora);
			bandera=true;
		}
	}
	fclose(arch);
	if(bandera==false){
		printf("No existen registros con estado Enviado");
	}
}

//Estado Cancelado
void ConsultaCancelado(){
	setlocale(LC_CTYPE, "Spanish");
	printf("Pruebas Canceladas:\n\n");
	bool bandera = false;
	
	if(!(arch=fopen("encabezado.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch, "%d\t", &regis->idPrueba);
		fscanf(arch, "%[^\t]\t", regis->estado);
		fscanf(arch, "%d\t",&regis->paciente.idPaciente);
		fscanf(arch, "%[^\t]\t",regis->paciente.nombre);
		fscanf(arch, "%d\t",&regis->paciente.edad);
		fscanf(arch, "%[^\t]\t",regis->paciente.tel);
		fscanf(arch, "%[^\t]\t",regis->paciente.correo);
		fscanf(arch, "%[^\n]\n",regis->paciente.fecha_hora);
		
		if(strcmp(regis->estado,"Cancelado") == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
			printf("|%d|\t",regis->idPrueba);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
			printf("|%s|\t",regis->estado);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			printf("|%d|\t",regis->paciente.idPaciente);
			printf("|%s|\t",regis->paciente.nombre);
			printf("|%d|\t",regis->paciente.edad);
			printf("|%s|\t",regis->paciente.tel);
			printf("|%s|\t",regis->paciente.correo);
			printf("|%s|\n",regis->paciente.fecha_hora);
			bandera=true;
		}
	}
	fclose(arch);
	if(bandera==false){
		printf("No existen registros con estado Cancelado");
	}
}

// Consulta por valor de idPrueba
void ConsultaPrueba(){
	setlocale(LC_CTYPE, "Spanish");
	printf("Pruebas disponibles:\n\n");
	bool bandera = false;
	int prueba = 0;
	bool bandera_buscar = false;
	
	if(!(arch=fopen("encabezado.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch, "%d\t", &regis->idPrueba);
		fscanf(arch, "%[^\t]\t", regis->estado);
		fscanf(arch, "%d\t",&regis->paciente.idPaciente);
		fscanf(arch, "%[^\t]\t",regis->paciente.nombre);
		fscanf(arch, "%d\t",&regis->paciente.edad);
		fscanf(arch, "%[^\t]\t",regis->paciente.tel);
		fscanf(arch, "%[^\t]\t",regis->paciente.correo);
		fscanf(arch, "%[^\n]\n",regis->paciente.fecha_hora);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
		printf("\t|%d|\n",regis->idPrueba);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	}
	fclose(arch);
	printf("\n");
	
	do{
		prueba = validaEntero("Prueba a consultar: ");
		
		if(!(arch = fopen("encabezado.xls", "r"))){
			printf("Error al intentar leer archivo");
			exit(1);
		}
		
		bandera_buscar=false;
		while(!feof(arch)){
			fscanf(arch, "%d\t",&regis->idPrueba);
			fscanf(arch, "%[^\t]\t",regis->estado);
			fscanf(arch, "%d\t",&regis->paciente.idPaciente);
			fscanf(arch, "%[^\t]\t",regis->paciente.nombre);
			fscanf(arch, "%d\t",&regis->paciente.edad);
			fscanf(arch, "%[^\t]\t",regis->paciente.tel);
			fscanf(arch, "%[^\t]\t",regis->paciente.correo);
			fscanf(arch, "%[^\n]\n",regis->paciente.fecha_hora);
			if(regis->idPrueba == prueba){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
				printf("|%d|\t",regis->idPrueba);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
				printf("|%s|\t",regis->estado);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				printf("|%d|\t",regis->paciente.idPaciente);
				printf("|%s|\t",regis->paciente.nombre);
				printf("|%d|\t",regis->paciente.edad);
				printf("|%s|\t",regis->paciente.tel);
				printf("|%s|\t",regis->paciente.correo);
				printf("|%s|\n",regis->paciente.fecha_hora);
				bandera_buscar=true;
			}
		}
		fclose(arch);
		
		if(bandera_buscar == false){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			printf("Pruebas no existente, intente de nuevo\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		}
	}while(bandera_buscar==false);
}

void imprimirEsctrucutura(){
	setlocale(LC_CTYPE, "Spanish");
	int y;
	printf("\n\n---------Registros en la Estructura-----------\n\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Codigo\tAnalisis\tPrecio\t\tCondiciones\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	
	for(int i=0; i<10; i++){
		printf("|%d|\t", analisis[i].codigo);
		printf("|%s|\n", analisis[i].nombre);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\t\t\t|%.2f|\t", analisis[i].precio);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("|%s|\n", analisis[i].condiciones);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	}
}

void crear_archivo(){
	
	//if(!(arch=fopen("Analisis_clinicos.txt", "w"))){
	if(!(arch=fopen("Analisis_clinicos.xls", "w"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	for(int i=0; i<10; i++){
		fprintf(arch,"%d\t", analisis[i].codigo);
		fprintf(arch,"%s\t", analisis[i].nombre);
		fprintf(arch,"%f\t", analisis[i].precio);
		fprintf(arch,"%s\n", analisis[i].condiciones);
	}
	
	fclose(arch);
}

void leer_archivo(){
	setlocale(LC_CTYPE, "Spanish");
	analisis_clinicos dato;
	
	//if(!(arch=fopen("Analisis_clinicos.txt", "r"))){
	if(!(arch=fopen("Analisis_clinicos.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	printf("\n\n---------Registros en el Archivo-----------\n\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Codigo\tAnalisis\tPrecio\t\tCondiciones\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	
	while(!feof(arch)){
		fscanf(arch,"%d\t", &dato.codigo);
		fscanf(arch,"%[^\t]\t", dato.nombre);
		fscanf(arch,"%f\t", &dato.precio);
		fscanf(arch,"%[^\n]\n", dato.condiciones);
		//strcmp("131", dato.codigo) == 0;
		//if(dato.codigo[0] == 1 && dato.codigo[1] == 3)
		printf("|%d|\t", dato.codigo);
		printf("|%s|\n", dato.nombre);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\t\t\t|%.2f|\t", dato.precio);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("|%s|\n", dato.condiciones);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	}
	fclose(arch);
}
// funcion usada para la funcion *buscar condiciones por codigo*
void leer_archivo_0condiciones(){
	setlocale(LC_CTYPE, "Spanish");
	analisis_clinicos dato;
	
	//if(!(arch=fopen("Analisis_clinicos.txt", "r"))){
	if(!(arch=fopen("Analisis_clinicos.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	printf("\n\n---------Registros en el Archivo-----------\n\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Codigo\tAnalisis\tPrecio\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	
	while(!feof(arch)){
		fscanf(arch,"%d\t", &dato.codigo);
		fscanf(arch,"%[^\t]\t", dato.nombre);
		fscanf(arch,"%f\t", &dato.precio);
		fscanf(arch,"%[^\n]\n", dato.condiciones);
		//strcmp("131", dato.codigo) == 0;
		//if(dato.codigo[0] == 1 && dato.codigo[1] == 3)
		printf("|%d|\t", dato.codigo);
		printf("|%s|\n", dato.nombre);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\t\t\t|%.2f|\n", dato.precio);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	}
	fclose(arch);
}

//funcion para validar que el analisis exista en la funcion  *agregar dinamico* de "estrucApuntador.h"
int validaCodigo(){
	int codigo = 0;
	bool bandera_buscar = false;
	analisis_clinicos dato;
	do{
		
		if(!(arch = fopen("Analisis_clinicos.xls", "r"))){
			printf("Error al intentar leer archivo");
			exit(1);
		}
		
		codigo = validaEntero("\nCodigo: ");
		bandera_buscar=false;
		while(!feof(arch)){
			fscanf(arch,"%d\t", &dato.codigo);
			fscanf(arch,"%[^\t]\t", dato.nombre);
			fscanf(arch,"%f\t", &dato.precio);
			fscanf(arch,"%[^\n]\n", dato.condiciones);
			if(dato.codigo == codigo){
				bandera_buscar=true;
			}
		}
		fclose(arch);
		if(bandera_buscar==false){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			printf("Analisis no encontrado");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		}
	}while(bandera_buscar==false);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	
	return codigo;
}

void buscarCodigo_archivo(){
	setlocale(LC_CTYPE, "Spanish");
	bool bandera = false;
	bool bandera_buscar = false;
	int codigo = 0;
	analisis_clinicos dato;
	
	printf("\nAnalisis disponibles:\n");
	leer_archivo_0condiciones();
	
	
	
	do{
		
		if(!(arch = fopen("Analisis_clinicos.xls", "r"))){
			printf("Error al intentar leer archivo");
			exit(1);
		}
		
		codigo = validaEntero("\nIntroduce el codigo del analisis: ");
		bandera_buscar=false;
		while(!feof(arch)){
			fscanf(arch,"%d\t", &dato.codigo);
			fscanf(arch,"%[^\t]\t", dato.nombre);
			fscanf(arch,"%f\t", &dato.precio);
			fscanf(arch,"%[^\n]\n", dato.condiciones);
			if(dato.codigo == codigo){
				printf("\nAnalisis: \n");
				printf("|%d|\t", dato.codigo);
				printf("|%s|\t", dato.nombre);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				printf("|%.2f|\t", dato.precio);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				printf("|%s|\n", dato.condiciones);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				bandera_buscar=true;
			}
		}
		fclose(arch);
		if(bandera_buscar==false){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			printf("Analisis no encontrado");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		}
	}while(bandera_buscar==false);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	
}

void modifRegisAnalisis(){
	setlocale(LC_CTYPE, "Spanish");
	analisis_clinicos dato;
	FILE *arch2;
	int codigo, p;
	bool bandera=false;
	
	if(!(arch=fopen("Analisis_clinicos.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	if(!(arch2=fopen("copia.xls", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	codigo = validaEntero("\nDame el codigo del analisis a modificar: ");
	
	while(!feof(arch)){
		fscanf(arch,"%d\t", &dato.codigo);
		fscanf(arch,"%[^\t]\t", dato.nombre);
		fscanf(arch,"%f\t", &dato.precio);
		fscanf(arch,"%[^\n]\n", dato.condiciones);
		if(dato.codigo == codigo){
			printf("|%d|\t", dato.codigo);
			printf("|%s|\t", dato.nombre);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
			printf("|%.2f|\t", dato.precio);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("|%s|\n", dato.condiciones);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			
			do{
				p = validaFlotante("Nuevo precio del analisis: ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				if (p<=0) printf("Valor no valido\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			}while(p<=0);
			dato.precio = p;
			validaCadYNum("Nuevas condiciones del analisis: ", dato.condiciones);
			bandera = true;
		}
		fprintf(arch2,"%d\t", dato.codigo);
		fprintf(arch2,"%s\t", dato.nombre);
		fprintf(arch2,"%f\t", dato.precio);
		fprintf(arch2,"%s\n", dato.condiciones);
	}
	if(bandera==false){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		printf("No se encuentra el registro");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	}else printf("\nAnalisis Actualizados\n\n");
	fclose(arch2);
	fclose(arch);
	remove("Analisis_clinicos.xls");
	rename("copia.xls", "Analisis_clinicos.xls");
}

void agregarRegisAnalisis(){
	setlocale(LC_CTYPE, "Spanish");
	analisis_clinicos dato;
	int p = 0, codigo = 0;
	bool bandera;
	
	if(!(arch=fopen("Analisis_clinicos.xls", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	printf("\nAgregar Registro: \n");
	do{
		bandera = false;
		do{
			codigo = validaEntero("Codigo: ");	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			if (codigo<=0) printf("Valor no valido\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		}while(codigo<=0);
		
		
		while(!feof(arch)){
			fscanf(arch,"%d\t", &dato.codigo);
			fscanf(arch,"%[^\t]\t", dato.nombre);
			fscanf(arch,"%f\t", &dato.precio);
			fscanf(arch,"%[^\n]\n", dato.condiciones);
			if(dato.codigo == codigo){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				printf("Este codigo ya existe\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				bandera = true;
				break;
			}
		}
	}while(bandera == true);
	dato.codigo = codigo;
	validaCadena("Nombre: ", dato.nombre);
	do{
		p = validaFlotante("Precio: ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		if (p<=0) printf("Valor no valido\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	}while(p<=0);
	dato.precio = p;
	validaCadYNum("Condiciones: ", dato.condiciones);
	
	fprintf(arch,"%d\t", dato.codigo);
	fprintf(arch,"%s\t", dato.nombre);
	fprintf(arch,"%f\t", dato.precio);
	fprintf(arch,"%s\n", dato.condiciones);
	
	printf("\nRegistro agregado\n\n");
	
	fclose(arch);
}

void modificaPrecio(){
	setlocale(LC_CTYPE, "Spanish");
	analisis_clinicos dato;
	FILE *arch2;
	int codigo, p;
	bool bandera=false;
	
	if(!(arch=fopen("Analisis_clinicos.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	if(!(arch2=fopen("copia.xls", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	codigo = validaEntero("\nDame el codigo del analisis para modificar su precio: ");
	bandera=false;
	while(!feof(arch)){
		fscanf(arch,"%d\t", &dato.codigo);
		fscanf(arch,"%[^\t]\t", dato.nombre);
		fscanf(arch,"%f\t", &dato.precio);
		fscanf(arch,"%[^\n]\n", dato.condiciones);
		if(dato.codigo == codigo){
			printf("|%d|\t", dato.codigo);
			printf("|%s|\t", dato.nombre);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
			printf("|%.2f|\t", dato.precio);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("|%s|\n", dato.condiciones);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			
			do{
				p = validaFlotante("Nuevo precio del analisis: ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				if (p<=0) printf("Valor no valido\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			}while(p<=0);
			dato.precio = p;
			bandera = true;
		}
		fprintf(arch2,"%d\t", dato.codigo);
		fprintf(arch2,"%s\t", dato.nombre);
		fprintf(arch2,"%f\t", dato.precio);
		fprintf(arch2,"%s\n", dato.condiciones);
	}
	if(bandera==false){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		printf("No se encuentra el registro");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	}else printf("\nAnalisis Actualizados\n\n");
	fclose(arch2);
	fclose(arch);
	remove("Analisis_clinicos.xls");
	rename("copia.xls", "Analisis_clinicos.xls");
}

void modificaCondicion(){
	setlocale(LC_CTYPE, "Spanish");
	analisis_clinicos dato;
	FILE *arch2;
	int codigo, p;
	bool bandera=false;
	
	if(!(arch=fopen("Analisis_clinicos.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	if(!(arch2=fopen("copia.xls", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	
	codigo = validaEntero("\nDame el codigo del analisis para modificar su condicion: ");
	
	while(!feof(arch)){
		fscanf(arch,"%d\t", &dato.codigo);
		fscanf(arch,"%[^\t]\t", dato.nombre);
		fscanf(arch,"%f\t", &dato.precio);
		fscanf(arch,"%[^\n]\n", dato.condiciones);
		if(dato.codigo == codigo){
			printf("|%d|\t", dato.codigo);
			printf("|%s|\t", dato.nombre);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			printf("|%.2f|\t", dato.precio);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("|%s|\n", dato.condiciones);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			
			validaCadYNum("Nuevas condiciones del analisis: ", dato.condiciones);
			bandera = true;
		}
		fprintf(arch2,"%d\t", dato.codigo);
		fprintf(arch2,"%s\t", dato.nombre);
		fprintf(arch2,"%f\t", dato.precio);
		fprintf(arch2,"%s\n", dato.condiciones);
	}
	if(bandera==false){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		printf("No se encuentra el registro");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	}else printf("\nAnalisis Actualizados\n\n");
	fclose(arch2);
	fclose(arch);
	remove("Analisis_clinicos.xls");
	rename("copia.xls", "Analisis_clinicos.xls");
}


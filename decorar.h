void portada(){
	int aux = 0;
	FILE *archivo = fopen("portada.txt", "r");
	
	for(int i=0; i<71; i++){
		for(int j=0; j<53; j++){
			fscanf(archivo, "%d\t", &aux);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aux);
			printf("%c", 177);
		}
		printf("\n");
	}
	
	fclose(archivo);
}

void datos(){
	setlocale(LC_CTYPE, "Spanish");
	gotoxy(65, 35);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Universidad Politécnica de San Luis Potosí");
	gotoxy(65, 37);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Programación I Lenguaje C");
	gotoxy(65, 39);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("MTI. Guadalupe Ledesma Ramos");
	gotoxy(65, 41);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("- Cortes Beltran Carol Elizabeth - 177203");
	gotoxy(65, 43);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("- Loredo Martínez Miguel Angel - 178424");
	gotoxy(65, 45);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Presiona cualquier tecla para iniciar...");
	getch();
}

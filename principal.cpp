#include "librerias.h"

int main(){
	//Función para ajustar el tamaño de la pantalla
	system("mode con: cols=140 lines=100");
	/*
	Carol Elizabeth Cortes Beltran - 177203
	Miguel Angel Loredo Martínez - 178424
	*/
	
	portada();
	datos();
	
	crear_archivo();
	menuProyecto();
	return 0;
		
}

#include "librerias.h"

int main(){
	//Funci�n para ajustar el tama�o de la pantalla
	system("mode con: cols=140 lines=100");
	/*
	Carol Elizabeth Cortes Beltran - 177203
	Miguel Angel Loredo Mart�nez - 178424
	*/
	
	portada();
	datos();
	
	crear_archivo();
	menuProyecto();
	return 0;
		
}

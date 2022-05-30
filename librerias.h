#include <stdio.h>
#include <conio.h>	//kbhit -> determina si se presiona una tecla
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <time.h>

void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X = x;
	dWPos.Y = y;
	SetConsoleCursorPosition(hcon, dWPos);
}

/*struct analisis_clinicos{ //nombre de la esctructura
	int matricula;
	char nombre[20];
	char carrera[20];
	float calif[3];
];*/

typedef struct {
	int codigo;
	char nombre[25];
	float precio;
	char condiciones[75];
}analisis_clinicos; //variable de la estructura

analisis_clinicos analisis[] = {	{23, "ACS. ANTI-HEPATITIS", 550, "Ayuno de 8 hrs"},
									{53, "CANNABINOIDES EN ORINA", 150, "Ninguna"},
									{111, "ESPERMOCULTIVO",310, "Abstinencia sexual 3 a 5 dias y no orinar por 3 horas antes del estudio"},
									{131, "GLUCOSA", 100, "Ayuno de 8 hrs"},
									{146, "INSULINA", 420, "Ayuno de 8 hrs"},
									{182, "PROGESTERONA", 290, "Ninguna"},
									{183, "PROLACTINA", 290, "Ayuno de 10 a 12 hrs"},
									{210, "UROCULTIVO", 310, "No ingerir antibioticos durante 48 hrs"},
									{291, "PRUEBA DE DU", 110, "Ayuno de 12 a 14 hrs"},
									{536, "BUSQUEDA DE HONGOS", 140, "Ninguna"}	};

typedef struct{
	int idPaciente;
	char nombre[25];
	int edad;
	char tel[20];
	char correo[30];
	char fecha_hora[25];
}Paciente;

typedef struct{
	int idDetalle;
	int idPrueba;
	analisis_clinicos Analisis;
}Detalle;

typedef struct{
	int idPrueba;
	char estado[20];
	Paciente paciente;
	Detalle detalle;
}Prueba;

enum MENU { OPC1=1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7};

FILE *arch = NULL;
Prueba *regis = (Prueba *)malloc(sizeof(Prueba));

#include "validaciones.h"
#include "decorar.h"
#include "estructura.h"
#include "estrucApuntador.h"
#include "menu.h"

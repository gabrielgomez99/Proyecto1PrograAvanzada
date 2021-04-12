/*
*Gabriel David Gomez Novau
*
*Sirve clase para simular un estudiante
*
*/
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

typedef struct{
	int mat[4];
	int id;
	char nombre[100];
	char apellido[100];
	char carrera[6];
	char ciudad[100];
	char fecha[11];
} Estudiante;


void imprimeTabla1(Estudiante E[],int tamanoE,int o,FILE *fptrOut);
void imprimeTabla2(Estudiante E[],int tamanoE,int o,FILE *fptrOut);
void imprimeHelp();
void kardex(Estudiante E[], int id, int tamanoE,int o, FILE *fptrOut);
void fechaGrad(Estudiante E[], int id, int tamanoE,int o, FILE *fptrOut);
void numeroAlumnos(Estudiante E[], char arg1[100],char arg2[100], int tamanoE,int sizeOfQuery,int o, FILE *fptrOut);
void nombreAlumnos(Estudiante E[], char arg1[100],char arg2[100], int tamanoE,int sizeOfQuery,int o, FILE *fptrOut);


#endif

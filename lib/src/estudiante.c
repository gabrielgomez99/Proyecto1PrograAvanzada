#include <stdio.h>
#include <stdlib.h>
#include "estudiante.h"
#include <string.h>


/*
void imprimeTabla1(Estudiante E[],int tamanoE)
void imprimeTabla2(Estudiante E[],int tamanoE)
*/


//imprime todas las calificaciones de cada alumno
void imprimeTabla1(Estudiante E[],int tamanoE,int o,FILE *fptrOut){
	for(int i = 0;i < tamanoE; i++){
		if(o == 1){
			fprintf(fptrOut,"%d %s %s %s %s %s\n",E[i].id,E[i].nombre,E[i].apellido,E[i].carrera,E[i].ciudad,E[i].fecha);
		}
		else{
			printf("%d %s %s %s %s %s\n",E[i].id,E[i].nombre,E[i].apellido,E[i].carrera,E[i].ciudad,E[i].fecha);
		}
	}
}

void imprimeTabla2(Estudiante E[],int tamanoE,int o,FILE *fptrOut){
	for(int i = 0;i < tamanoE; i++){
		if(o == 1){
			fprintf(fptrOut,"%d %d %d %d %d\n",E[i].id,E[i].mat[0],E[i].mat[1],E[i].mat[2],E[i].mat[3]);
		}
		else{
			printf("%d %d %d %d %d\n",E[i].id,E[i].mat[0],E[i].mat[1],E[i].mat[2],E[i].mat[3]);
		}
		
	}
}


void imprimeHelp(){
	printf("HELP:\n");
		printf("	Argumentos\n");
		printf("		file1 file2 (comandos extra)\n");
		printf("			-h: sirve para mostrar menu de ayuda\n");
		printf("			-v: sirve para mostrar como va la ejecucion del programa\n");
		printf("			-o: file(nombre de archivo) se abre un archivo en el que se mostraran los querys\n");
		printf("	\nMenu:\n");
		printf("		1: es para desplegar la informacion de los dos archivos\n");
		printf("		2: usar querys\n");
		printf("		3: acaba el programa\n");
		printf("	\nQuerys:\n");
		printf("		Kardex <estudiante_id>: es para ver la informacion de un estudiante\n");
		printf("		Fecha_estimada_graduacion <estudiante_id>: es para saber la fecha de graduacion de un estudiante\n");
		printf("		Numero_alumnos <nombre_carrera> <ciudad_origen>: cantidad de alumnos con esa carrera y ciudad de origen\n");
		printf("		Numero_alumnos <nombre_carrera>: cantidad de alumnos con esa carrera\n");
		printf("		Numero_alumnos *: Es para saber cuantos alumnos hay\n");
		printf("		Nombre_alumnos <nombre_carrera> <ciudad_origen>: cantidad de alumnos con esa carrera y ciudad de origen\n");
		printf("		Nombre_alumnos <nombre_carrera>: nombre de alumnos con esa carrera\n");
		printf("		Nombre_alumnos *: nombres de los alumnos\n");
		printf("		Nombre_alumnos <operador> <numero>: nombre de alumnos y su promedio con la condicion del operador y la califiacion mandada\n");
		printf("			<: calificaciones menores al numero que sigue\n");
		printf("			>: calificaciones mayores al numero que sigue\n");
		printf("			==: calificaciones iguales al numero que sigue\n");
		printf("			!=: calificaciones diferentes al numero que sigue\n");
}

void kardex(Estudiante E[], int id, int tamanoE,int o,FILE *fptrOut){
	int existio = 0;
	for(int i = 0; i < tamanoE; i++){
		if(E[i].id == id){
			if(o == 1){
				fprintf(fptrOut,"-------------------------------\n");
				fprintf(fptrOut,"id: %d nombre: %s %s carrera: %s\nCiudad: %s Fecha de graduacion: %s \nmateria[A]: %d materia[B]: %d materia[C]: %d materia[D]: %d\n",E[i].id,E[i].nombre,E[i].apellido,E[i].carrera,E[i].ciudad,E[i].fecha,E[i].mat[0],E[i].mat[1],E[i].mat[2],E[i].mat[3]);
				fprintf(fptrOut,"-------------------------------\n");
				existio = 1;
			}
			else{
				printf("-------------------------------\n");
				printf("id: %d nombre: %s %s carrera: %s\nCiudad: %s Fecha de graduacion: %s \nmateria[A]: %d materia[B]: %d materia[C]: %d materia[D]: %d\n",E[i].id,E[i].nombre,E[i].apellido,E[i].carrera,E[i].ciudad,E[i].fecha,E[i].mat[0],E[i].mat[1],E[i].mat[2],E[i].mat[3]);
				printf("-------------------------------\n");
				existio = 1;
			}
		}
	}
	if(existio == 0){
		printf("No existe el alumno");
	}
}

void fechaGrad(Estudiante E[], int id, int tamanoE,int o, FILE *fptrOut){
	int existio = 0;
	for(int i = 0; i < tamanoE; i++){
		if(o == 1){
			if(E[i].id == id){
				fprintf(fptrOut,"-------------------------------\n");
				fprintf(fptrOut,"id: %d nombre: %s %s Fecha de graduacion: %s\n",E[i].id,E[i].nombre,E[i].apellido,E[i].fecha);
				fprintf(fptrOut,"-------------------------------\n");
				existio = 1;
			}
		}
		else{
			if(E[i].id == id){
				printf("-------------------------------\n");
				printf("id: %d nombre: %s %s Fecha de graduacion: %s\n",E[i].id,E[i].nombre,E[i].apellido,E[i].fecha);
				printf("-------------------------------\n");
				existio = 1;
			}
		}
	}
	if(existio == 0){
		printf("No existe el alumno");
	}
}

void numeroAlumnos(Estudiante E[], char arg1[100],char arg2[100], int tamanoE,int sizeOfQuery,int o, FILE *fptrOut){
	int numero = 0;
	if(sizeOfQuery == 2){
		if(strcmp(arg1,"*")==0){
			if(o == 1){
				fprintf(fptrOut,"-------------------------------\n");
				fprintf(fptrOut,"Numero de alumnos: %d\n",tamanoE);
				fprintf(fptrOut,"-------------------------------\n");
			}
			else{
				printf("-------------------------------\n");
				printf("Numero de alumnos: %d\n",tamanoE);
				printf("-------------------------------\n");
			}
		}
		else{	
			for(int i = 0;i < tamanoE;i++){
					if(strcmp(E[i].carrera,arg1)==0){
						numero++;
					}
			}
			if(o == 1){
				fprintf(fptrOut,"-------------------------------\n");
				fprintf(fptrOut,"Numero de alumnos: %d\n",numero);
				fprintf(fptrOut,"-------------------------------\n");
			}
			else{
				printf("-------------------------------\n");
				printf("Numero de alumnos: %d\n",numero);
				printf("-------------------------------\n");
			}
		}
	}
	else if(sizeOfQuery == 3){
		for(int i = 0;i < tamanoE;i++){
			if(strcmp(E[i].carrera,arg1)==0){
				if(strcmp(E[i].ciudad,arg2)==0){
					numero++;
				}
			}
		}
		if(o == 1){
			fprintf(fptrOut,"-------------------------------\n");
			fprintf(fptrOut,"Numero de alumnos: %d\n",numero);
			fprintf(fptrOut,"-------------------------------\n");
		}
		else{
			printf("-------------------------------\n");
			printf("Numero de alumnos: %d\n",numero);
			printf("-------------------------------\n");
		}
	}
}

void nombreAlumnos(Estudiante E[], char arg1[100],char arg2[100], int tamanoE,int sizeOfQuery,int o, FILE *fptrOut){
	int numero = 0;
	if(sizeOfQuery == 2){
		if(strcmp(arg1,"*")==0){
			for(int i = 0; i < tamanoE;i++){
				if(o == 1){	
					fprintf(fptrOut,"-------------------------------\n");
					fprintf(fptrOut,"Nombre: %s %s\n", E[i].nombre,E[i].apellido);
					fprintf(fptrOut,"-------------------------------\n");
				}
				else{
					printf("-------------------------------\n");
					printf("Nombre: %s %s\n", E[i].nombre,E[i].apellido);
					printf("-------------------------------\n");
				}
			}
		}
		else{	
			for(int i = 0; i < tamanoE;i++){
				if(strcmp(E[i].carrera,arg1)==0){
					if(o == 1){	
						fprintf(fptrOut,"-------------------------------\n");
						fprintf(fptrOut,"Nombre: %s %s\n", E[i].nombre,E[i].apellido);
						fprintf(fptrOut,"-------------------------------\n");
					}
					else{
						printf("-------------------------------\n");
						printf("Nombre: %s %s\n", E[i].nombre,E[i].apellido);
						printf("-------------------------------\n");
					}
				}
			}
		}
	}
	else if(sizeOfQuery == 3){
		if(strcmp("<",arg1)==0){
			for(int i = 0;i < tamanoE;i++){
				int avg = (E[i].mat[0] + E[i].mat[1] + E[i].mat[2] + E[i].mat[3])/4;
				int avgParametro = atoi(arg2);
				if(avg > avgParametro){
					if(o == 1){	
						fprintf(fptrOut,"-------------------------------\n");
						fprintf(fptrOut,"Nombre: %s %s promedio: %d\n", E[i].nombre,E[i].apellido,avg);
						fprintf(fptrOut,"-------------------------------\n");
					}
					else{
						printf("-------------------------------\n");
						printf("Nombre: %s %s promedio: %d\n", E[i].nombre,E[i].apellido,avg);
						printf("-------------------------------\n");
					}
				}
			}
		}
		else if(strcmp(">",arg1)==0){
			for(int i = 0;i < tamanoE;i++){
				int avg = (E[i].mat[0] + E[i].mat[1] + E[i].mat[2] + E[i].mat[3])/4;
				int avgParametro = atoi(arg2);
				if(avg < avgParametro){
					if(o == 1){	
						fprintf(fptrOut,"-------------------------------\n");
						fprintf(fptrOut,"Nombre: %s %s promedio: %d\n", E[i].nombre,E[i].apellido,avg);
						fprintf(fptrOut,"-------------------------------\n");
					}
					else{
						printf("-------------------------------\n");
						printf("Nombre: %s %s promedio: %d\n", E[i].nombre,E[i].apellido,avg);
						printf("-------------------------------\n");
					}
				}
			}
		}
		else if(strcmp("==",arg1)==0){
			for(int i = 0;i < tamanoE;i++){
			int avg = (E[i].mat[0] + E[i].mat[1] + E[i].mat[2] + E[i].mat[3])/4;
			int avgParametro = atoi(arg2);
				if(avg == avgParametro){
					if(o == 1){	
						fprintf(fptrOut,"-------------------------------\n");
						fprintf(fptrOut,"Nombre: %s %s promedio: %d\n", E[i].nombre,E[i].apellido,avg);
						fprintf(fptrOut,"-------------------------------\n");
					}
					else{
						printf("-------------------------------\n");
						printf("Nombre: %s %s promedio: %d\n", E[i].nombre,E[i].apellido,avg);
						printf("-------------------------------\n");
					}
				}
			}
		}
		else if(strcmp("!=",arg1)==0){
			for(int i = 0;i < tamanoE;i++){
				int avg = (E[i].mat[0] + E[i].mat[1] + E[i].mat[2] + E[i].mat[3])/4;
				int avgParametro = atoi(arg2);
				if(avg != avgParametro){
					if(o == 1){	
						fprintf(fptrOut,"-------------------------------\n");
						fprintf(fptrOut,"Nombre: %s %s promedio: %d\n", E[i].nombre,E[i].apellido,avg);
						fprintf(fptrOut,"-------------------------------\n");
					}
					else{
						printf("-------------------------------\n");
						printf("Nombre: %s %s promedio: %d\n", E[i].nombre,E[i].apellido,avg);
						printf("-------------------------------\n");
					}
				}
			}
		}
		else{
			for(int i = 0; i < tamanoE;i++){
				if(strcmp(E[i].carrera,arg1)==0){
					if(strcmp(E[i].ciudad,arg2)==0){
						if(o == 1){	
							fprintf(fptrOut,"-------------------------------\n");
							fprintf(fptrOut,"Nombre: %s %s\n", E[i].nombre,E[i].apellido);
							fprintf(fptrOut,"-------------------------------\n");
						}
						else{
							printf("-------------------------------\n");
							printf("Nombre: %s %s\n", E[i].nombre,E[i].apellido);
							printf("-------------------------------\n");
						}
					}

				}
			}
		}
	}
}



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../lib/src/estudiante.h"

int main(int argc, char *argv[]){
	Estudiante *E;
	int option = 0;
	int o = 0;
	int verbose = 0;
	char file1[100];
	char file2[100];
	char file3[100];
	FILE *fptrOut;
	
	if(argc > 2){
		
	}
	else{
		printf("Faltaron argumentos");
		exit(0);
	}	
	
	strcpy(file1,argv[1]);
	strcpy(file2,argv[2]);
	
	while((option = getopt(argc, argv, "hvo:")) != -1){
		switch(option){
			case 'h':
				imprimeHelp();
				exit(0);
				break;
			case 'v':
				verbose =1;
				break;
			case 'o':
				o = 1;
				strcpy(file3,optarg);
				break;
			default:
				break;
		}
	}
	//se abre archivo de salida cuando hay -o
	if(o == 1){
		if(verbose == 1){
			printf("[INFO]: Se abrio archivo de salida (%s)\n",file3);
		}
		fptrOut = fopen(file3, "w");
	}
	
	if(verbose == 1){
		printf("[INFO]: se abrio primer archivo\n");
	}
	FILE *fptr;
	fptr = fopen(file1, "r");
	if(fptr == NULL){
		printf("no existe el archivo 1");
		exit(1);
	}
	int tempLeer;
	char tempLeerNom[100];
	char tempLeerAp[100];
	char tempLeerCa[6];
	char tempLeerCiu[100];
	char tempLeerFe[11];
	int tamanoE = 0;
	//para saber tamano de archivo
	if(verbose == 1){
		printf("[INFO]: se sabe tamano de los archivos\n");
	}
	while(!feof(fptr)){
		fscanf(fptr,"%d%s%s%s%s%s",&tempLeer,tempLeerNom,tempLeerAp,tempLeerCa,tempLeerCiu,tempLeerFe);
		tamanoE++;
	}
	//porque termina uno extra sumado
	tamanoE--;
	fclose(fptr);
	if(verbose == 1){
		printf("[INFO]: se aloca memoria dinamica\n");
	}
	E = malloc(sizeof(Estudiante)*tamanoE);
	if(verbose == 1){
		printf("[INFO]: se leyo primer archivo\n");
	}
	//leer primer archivo
	fptr = fopen(file1, "r");
	for(int i = 0;i < tamanoE;i++){
		fscanf(fptr,"%d%s%s%s%s%s",&E[i].id,E[i].nombre,E[i].apellido,E[i].carrera,E[i].ciudad,E[i].fecha);
	}
	fclose(fptr);
	
	if(verbose == 1){
		printf("[INFO]: se abrio segundo archivo\n");
	}
	fptr = fopen(file2, "r");
	if(fptr == NULL){
		printf("no existe el archivo 2");
		exit(2);
	}
	if(verbose == 1){
		printf("[INFO]: se leyo segundo archivo\n");
	}
	//leer el segundo archivo
	for(int i = 0;i < tamanoE;i++){
		fscanf(fptr,"%d",&tempLeer);
		for(int j = 0;j < tamanoE;j++){
			if(tempLeer == E[j].id){
				fscanf(fptr,"%d%d%d%d",&E[i].mat[0],&E[i].mat[1],&E[i].mat[2],&E[i].mat[3]);
			}
		}
	}
	fclose(fptr);
	if(verbose == 1){
		printf("[INFO]: abriendo MENU\n");
	}
	//menu
	option = 0;
	char argumento[100];
	int sizeOfQuery = 0;
	
	char temp;
	//size_t characters;
	
	while(option != 3){
		printf("[MENU]\n1 mostrar tablas de estudiantes,2 hacer Querys,3 acabar el programa\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				if(verbose == 1){
					printf("[INFO]: se imprimiran las tablas de los archivos\n");
				}
				imprimeTabla1(E,tamanoE,o,fptrOut);
				imprimeTabla2(E,tamanoE,o,fptrOut);
				break;
			case 2:
				sizeOfQuery = 1;
				printf("ingrese query: ");
				scanf("%c",&temp);
				scanf("%[^\n]",argumento);
				char arg[100];
				char arg1[100];
				char arg2[100];
				int j = 0;
				int k = 0;
				for(int i = 0; i < strlen(argumento);i++){
					if(argumento[i] == ' '){
						sizeOfQuery++;
					}
					else{
						if(sizeOfQuery == 1){
							arg[i] = argumento[i];
						}
						else if(sizeOfQuery == 2){
							arg1[j] = argumento[i];
							j++;
						}
						else if(sizeOfQuery == 3){
							arg2[k] = argumento[i];
							k++;
						}
					}
				}
				if(sizeOfQuery == 2){
					if(strcmp(arg,"Kardex")==0){
						if(verbose == 1){
							printf("[INFO]: Sacando Kardex\n");
						}
						int idTemp = atoi(arg1);
						kardex(E,idTemp,tamanoE,o,fptrOut);
					}
					else if(strcmp(arg,"Numero_alumnos")==0){
						if(verbose == 1){
							printf("[INFO]: Sacando Numero de Alumnos\n");
						}
						numeroAlumnos(E,arg1,arg2,tamanoE,sizeOfQuery,o,fptrOut);
					}
					else if(strcmp(arg,"Fecha_estimada_graduacion")==0){
						if(verbose == 1){
							printf("[INFO]: Sacando Fecha de graduacion del alumno\n");
						}
						int idTemp = atoi(arg1);
						fechaGrad(E,idTemp,tamanoE,o,fptrOut);
					}
					else if(strcmp(arg,"Nombre_alumnos")==0){
						if(verbose == 1){
							printf("[INFO]: Sacando nombre de alumnos\n");
						}
						nombreAlumnos(E,arg1,arg2,tamanoE,sizeOfQuery,o,fptrOut);
					}
					else{
						printf("Query no existe\n");
					}
				}
				else if(sizeOfQuery == 3){
					if(strcmp(arg,"Numero_alumnos")==0){
						if(verbose == 1){
							printf("[INFO]: Sacando numero de alumnos\n");
						}
						numeroAlumnos(E,arg1,arg2,tamanoE,sizeOfQuery,o,fptrOut);
					}
					else if(strcmp(arg,"Nombre_alumnos")==0){
						if(verbose == 1){
							printf("[INFO]: Sacando nombre de alumnos\n");
						}
						nombreAlumnos(E,arg1,arg2,tamanoE,sizeOfQuery,o,fptrOut);
					}
					else{
						printf("Query no existe\n");
					}
				}
				else{
					printf("Query no existe\n");
				}
				break;
			case 3:
				if(verbose == 1){
					printf("[INFO]: cerrando programa\n");
				}
				break;
			default:
				printf("opcion invalida ingrese de nuevo");
				option = 0;
				break;
		}
	}
	
	if(o == 1){
		if(verbose == 1){
			printf("[INFO]: se cierra archivo de salida\n");
		}
		fclose(fptrOut);
	}
	if(verbose == 1){
		printf("[INFO]: se libera memoria dinamica\n");
	}
	free(E);
	return 0;
}

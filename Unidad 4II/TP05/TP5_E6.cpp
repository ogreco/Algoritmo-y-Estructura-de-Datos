/*Se tiene una Arreglo Multidimensional de orden MxNxP con valores reales.
:
a. Realizar la carga del Arreglo Multidimensional, por medio de una función SIN TIPO.
b. Por medio de una función CON TIPO, encontrar el menor valor dentro del Arreglo Multidimensional.
c. Por medio de una función CON TIPO, determinar si el menor valor encontrado es o no par.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(float matriz[10][10][10], int filas, int columnas, int planos);
void muestra(float matriz[10][10][10], int filas, int columnas,  int planos);
float menor(float matriz[10][10][10], int filas, int columnas,  int planos);
bool esPar(float num);

main(){
	int n, m, p;
	printf("ingrese la cantidad de planos: ");
	scanf("%d", &p);
	printf("ingrese la cantidad de filas: ");
	scanf("%d", &m);
	printf("ingrese la cantidad de columnas: ");
	scanf("%d", &n);
	
	
	float matriz[10][10][10];
	carga(matriz, m, n, p);
	muestra(matriz, m, n, p);
	
	float elmenor = menor(matriz, m, n, p);
	
	printf("el menor de todos los elementos es %.2f", elmenor);
	if (esPar(elmenor)) printf("\nes par");
	else printf("\n no es par");
}

void carga(float matriz[10][10][10], int filas, int columnas, int planos){
	srand(time(NULL));
	for(int p=0; p<planos; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				matriz[p][i][j] = 2 + rand()%10;
			}
		}	
	}
	
}

void muestra(float matriz[10][10][10], int filas, int columnas, int planos){
	for(int p=0; p<planos; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				printf("[%.2f] ", matriz[p][i][j]);
			}	
			printf("\n");	
		}
		printf("\n");
	}	
}

float menor(float matriz[10][10][10], int filas, int columnas,  int planos){
	float m = matriz[0][0][0];
		
	for(int p=0; p<planos; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				if(matriz[p][i][j] < m)	m = matriz[p][i][j];
			}	
		}
	}	
	
	return m;
}

bool esPar(float num){
	return (int)num%2==0;
}

/*Se tiene un Arreglo Multidimensional de valores enteros, de orden MxNxP.
a. Realizar la carga del Arreglo Multidimensional, por medio de una función.
b. Mediante una función, Realizar la carga a un vector, que contendrá en cada elemento la suma de los
elementos de cada plano de la Arreglo Multidimensional. (Nota: Tener en cuenta el orden que se deberá dar al
vector en su definición).
c. Mostrar el vector generado a través de una función sin tipo
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(int matriz[10][10][10], int filas, int columnas, int plano);
void muestra(int matriz[10][10][10], int filas, int columnas,  int plano);
void cargarVector(int v[], int matriz[10][10][10], int filas, int columnas,  int plano);
void listarVector(int v[], int plano);

main(){
	int n, m, p;
	printf("ingrese la cantidad de planos: ");
	scanf("%d", &p);
	printf("ingrese la cantidad de filas: ");
	scanf("%d", &m);
	printf("ingrese la cantidad de columnas: ");
	scanf("%d", &n);
	
	
	int matriz[10][10][10];
	int vp[p];
	
	carga(matriz, m, n, p);	
	muestra(matriz, m, n, p);
	cargarVector(vp, matriz, m, n, p);
	listarVector(vp, p);
}



void carga(int matriz[10][10][10], int filas, int columnas, int plano){
	srand(time(NULL));
	for(int p=0; p<plano; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				matriz[p][i][j] = 1 + rand()%10;
			}
		}	
	}
	
}

void muestra(int matriz[10][10][10], int filas, int columnas, int plano){
	for(int p=0; p<plano; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				printf("[%d] ", matriz[p][i][j]);
			}	
			printf("\n");	
		}
		printf("\n");
	}	
}

void cargarVector(int v[], int matriz[10][10][10], int filas, int columnas,  int plano){
	for(int p=0; p<plano; p++){
		int suma = 0;
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				suma = suma + matriz[p][i][j];
			}	
		}
		v[p] = suma;
	}	
}

void listarVector(int v[], int plano){
	for(int i=0; i<plano; i++)
		printf("[%d] ", v[i]);
}

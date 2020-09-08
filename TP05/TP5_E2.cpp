/*Ingresar los elementos de una matriz donde sus elementos son números enteros. El orden de la
matriz es MxN.
Diagrama de flujo y Codificación en C
a. Realizar la carga de la matriz por medio de una función sin tipo. Al ingresar un valor negativo o
cero mostrar mensaje de error y volver a ingresar el valor para dicha celda.
b. Mostrar la matriz por medio de una función.
c. Cambiar un elemento de la matriz, de una posición ingresada por teclado, por el valor cero.
Utilizar la función realizada en el punto b para mostrar como quedo.
d. Mostrar los elementos de una fila “X”, ingresando el número de fila, por teclado.
e. Mostrar los elementos de una Columna “Y”, ingresando el número de columna por teclado*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(int matriz[100][100], int m, int n);
void muestra(int matriz[100][100], int m, int n);
void cambio(int matriz[100][100], int f, int c);
void elementosFila(int matriz[100][100], int f, int n);
void elementosColumna(int matriz[100][100], int c, int m);

main(){
	int matriz[100][100];
	int m, n;
	printf("Ingrese la cantidad de Filas: ");
	scanf("%d", &m);
	printf("Ingrese la cantidad de Columnas: ");
	scanf("%d", &n);
	carga(matriz, m, n);
	muestra(matriz, m, n);
	int f, c;
	printf("Ingrese la Fila para cambiar: ");
	scanf("%d", &f);
	printf("Ingrese la Columna para cambiar: ");
	scanf("%d", &c);
	cambio(matriz, f, c);
	muestra(matriz, m, n);
	
	printf("\nIngrese la Fila para mostrar: ");
	scanf("%d", &f);
	elementosFila(matriz, f, m);
	printf("\nIngrese la Columna para mostrar: ");
	scanf("%d", &c);
	elementosColumna(matriz, c, n);
	
}


void carga(int matriz[100][100], int m, int n){
	srand(time(NULL));
	int x;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			do{
				x = (rand()%50)-40;	
			}while(x<=0);
			
			matriz[i][j] = x;
		}	
	}
}


void muestra(int matriz[100][100], int m, int n){
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%d - ", matriz[i][j]);
		}	
		printf("\n");
	}
}

void cambio(int matriz[100][100], int f, int c){
	matriz[f-1][c-1] = 0;
}

void elementosFila(int matriz[100][100], int f, int n){	
	for(int j=0; j<n; j++){
		printf("%d - ", matriz[f-1][j]);
	}
}

void elementosColumna(int matriz[100][100], int c, int m){
	for(int i=0; i<m; i++){
		printf("%d\n", matriz[i][c-1]);
	}
}

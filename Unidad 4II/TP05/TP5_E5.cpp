/*?Se tiene un de orden MxNxP de valores enteros.
a. Usando una función SIN TIPO, realizar la carga del Arreglo Multidimensional.
b. Usando una función, llenar un vector donde cada elemento del vector corresponde a la suma de
todos los elementos del plano del arreglo Multidimensional. (Nota: La suma de los elementos del plano
cero se almacena en la posición cero del vector, La suma de los elementos del plano uno se almacena en
la posición uno del vector, La suma de los elementos del plano dos se almacena en la posición dos del
vector,…., así hasta sumar todos los planos).
c. Usando una función SIN TIPO, listar el vector.
d. Usando una función CON TIPO, calcular el promedio del vector y mostrar en main.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(float matriz[10][10][10], int filas, int columnas, int plano);
void muestra(float matriz[10][10][10], int filas, int columnas,  int plano);
void cargarVector(float v[], float matriz[10][10][10], int filas, int columnas,  int plano);
void listarVector(float v[], int plano);
float promedioVector(float v[], int plano);

main(){
	int n, m, p;
	printf("ingrese la cantidad de planos: ");
	scanf("%d", &p);
	printf("ingrese la cantidad de filas: ");
	scanf("%d", &m);
	printf("ingrese la cantidad de columnas: ");
	scanf("%d", &n);
	
	
	float matriz[10][10][10];
	float vp[p];
	
	carga(matriz, m, n, p);	
	muestra(matriz, m, n, p);
	cargarVector(vp, matriz, m, n, p);
	listarVector(vp, p);
	printf("\n el promedio del vector es %.2f", promedioVector(vp, p));
}



void carga(float matriz[10][10][10], int filas, int columnas, int plano){
	srand(time(NULL));
	for(int p=0; p<plano; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				matriz[p][i][j] = 1 + rand()%10;
			}
		}	
	}
	
}

void muestra(float matriz[10][10][10], int filas, int columnas, int plano){
	for(int p=0; p<plano; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				printf("[%.2f] ", matriz[p][i][j]);
			}	
			printf("\n");	
		}
		printf("\n");
	}	
}

void cargarVector(float v[], float matriz[10][10][10], int filas, int columnas,  int plano){
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

void listarVector(float v[], int plano){
	for(int i=0; i<plano; i++)
		printf("[%.2f] ", v[i]);
}

float promedioVector(float v[], int plano){
	int suma = 0;
	for(int i=0; i<plano; i++)
		suma += v[i];
	
	return suma/plano;
}

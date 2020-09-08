#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(float matriz[100][100], int filas, int columnas);
void muestra(float matriz[100][100], int filas, int columnas);
int sucursal_mayor_venta(float matriz[100][100], int filas, int columnas);
int deporte_mayor_venta(float matriz[100][100], int filas, int columnas);
float total_venta_sucursal(float matriz[100][100], int columnas, int sucursal);

main(){
	
	int n, m;
	printf("ingrese la cantidad de surcursales: ");
	scanf("%d", &m);
	printf("ingrese la cantidad de deportes: ");
	scanf("%d", &n);	
	float negocio[100][100];
	
	carga(negocio, m, n);
	muestra(negocio, m, n);
	int sucursal = sucursal_mayor_venta(negocio, m, n);
	printf("\nla sucursal con mayor venta es: %d", sucursal);
	int deporte = deporte_mayor_venta(negocio, m, n);
	printf("\nla sucursal con mayor venta es: %d", deporte);
	
	for(int i=0; i<m; i++){
		printf("\nla sucursal %d vendio: %f", i, total_venta_sucursal(negocio, n, i));
	}
}


void carga(float matriz[100][100], int filas, int columnas){
	srand(time(NULL));
	for(int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			matriz[i][j] = 1 + rand()%101;
		}
	}
}

void muestra(float matriz[100][100], int filas, int columnas){
	for(int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			printf("[%f] ", matriz[i][j]);
		}
		printf("\n");
	}
}

int sucursal_mayor_venta(float matriz[100][100], int filas, int columnas){
	float mayor = 0;
	float sumaFila = 0;
	int sucursal = 0;
	
	for(int i=0; i<filas; i++){
		sumaFila = 0;
		for (int j=0; j<columnas; j++){
		 sumaFila += matriz[i][j];
		}
		if (sumaFila > mayor) {
			mayor = sumaFila;
			sucursal = i;	
		}
	}
	
	return sucursal;
}

int deporte_mayor_venta(float matriz[100][100], int filas, int columnas){
	float mayor = 0;
	float sumaColumna = 0;
	int deporte = 0;
	
	for (int j=0; j<columnas; j++){
		sumaColumna = 0;
		for(int i=0; i<filas; i++){
		 sumaColumna += matriz[i][j];
		}
		if (sumaColumna > mayor) {
			mayor = sumaColumna;
			deporte = j;	
		}
	}
	
	return deporte;
}

float total_venta_sucursal(float matriz[100][100], int columnas, int sucursal){
	float suma = 0;
	
	for(int j=0; j<columnas; j++){
		suma += matriz[sucursal][j];
	}
	
	return suma;
}

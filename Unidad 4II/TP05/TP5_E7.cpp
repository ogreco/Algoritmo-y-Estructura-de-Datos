/*
Una empresa internacional, comercializa en 3 países los 4 productos que produce a través de sus 2
sucursales. Los datos de ventas están registrado en una matriz multidimensional MxNxP. Donde P
representa países, M representa las sucursales y N representan los productos.
a. Defina y realizar la carga de las ventas en la matriz, por medio de una función.
b. Usando una función CON TIPO, calcule y muestre en main cual fue el país que más vendió.
c. Usando una función CON o SIN TIPO según estime conveniente. Realizar un listado que muestre el
total de venta de cada una de las sucursales.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(float matriz[10][10][10], int filas, int columnas, int pais);
void muestra(float matriz[10][10][10], int filas, int columnas,  int pais);
int pais_mayor_venta(float matriz[10][10][10], int filas, int columnas, int pais);
float total_sucursal(float matriz[10][10][10], int nrosuc, int columnas, int nropais);
/*int deporte_mayor_venta(float matriz[10][10][10], int filas, int columnas);
float total_venta_sucursal(float matriz[10][10][10], int columnas, int sucursal);*/

main(){
	
	int n, m, p;
	p = 3;
	m = 2;
	n = 4;
	
	float negocio[10][10][10];
	
	carga(negocio, m, n, p);	
	muestra(negocio, m, n, p);
	printf("\nel pais con mayor venta es %d", pais_mayor_venta(negocio, m, n, p));
	
	for(int k=0; k<p; k++){
		for(int i=0; i<m; i++){
			printf("\nel pais %d en la sucursal %d tiene %f", k, i, total_sucursal(negocio, i, n, k));
		}
	}
	
}


void carga(float matriz[10][10][10], int filas, int columnas, int pais){
	srand(time(NULL));
	for(int p=0; p<pais; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				matriz[p][i][j] = 1 + rand()%101;
			}
		}	
	}
	
}

void muestra(float matriz[10][10][10], int filas, int columnas, int pais){
	for(int p=0; p<pais; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				printf("[%.2f] ", matriz[p][i][j]);
			}	
			printf("\n");	
		}
		printf("\n");
	}	
}

int pais_mayor_venta(float matriz[10][10][10], int filas, int columnas, int pais){
	float mayor = 0;
	float sumaPais = 0;
	int numPais = 0;
	
	for(int p=0; p<pais; p++){
		sumaPais = 0;
		for(int i=0; i<filas; i++){			
			for (int j=0; j<columnas; j++){
		 		sumaPais += matriz[p][i][j];
			}			
		}
		printf("\n el pais %d tiene %f", p, sumaPais);
		if (sumaPais > mayor){
				mayor = sumaPais;
				numPais = p;	
			}
	}

	return numPais;
	
}

float total_sucursal(float matriz[10][10][10], int nrosuc, int columnas, int nropais){
	
	float suma = 0;
	for (int j=0; j<columnas; j++){
		suma += matriz[nropais][nrosuc][j];
	}	
	
	return suma;
}

/*
int deporte_mayor_venta(float matriz[10][10][10], int filas, int columnas){
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

float total_venta_sucursal(float matriz[10][10][10], int columnas, int sucursal){
	float suma = 0;
	
	for(int j=0; j<columnas; j++){
		suma += matriz[sucursal][j];
	}
	
	return suma;
}*/

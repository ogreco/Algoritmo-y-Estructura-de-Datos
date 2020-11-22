/*Una empresa internacional, comercializa en 3 países los 4 productos que produce a través de sus 2
sucursales. 
Los datos de ventas están registrado en una matriz multidimensional MxNxP. Donde P
representa países, M representa las sucursales y N representan los productos.
0     A   B    
     0   1    
 A 0 10  50   
 B 1 50  25   
 C 3 30  30   
 D 4 30  30   
 
 
1      A   B   
     0   1    
 A 0 10  50   
 B 1 50  20   
 C 3 30  20   
 D 4 30  30   
 
2      A   B   
     0   1    
 A 0 10  50   
 B 1 50  24   
 C 3 30  30   
 D 4 30  30   

a. Defina y realizar la carga de las ventas en la matriz, por medio de una función.
b. Usando una función CON TIPO, calcule y muestre en main cual fue el país que más vendió.
c. Usando una función CON o SIN TIPO según estime conveniente. Realizar un listado que muestre el
total de venta de cada una de las sucursales.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(int m, int n, int p, float arreglo[3][4][2]);
void muestra(int m, int n, int p, float arreglo[3][4][2]);
int mayorVentaPais(int m, int n, int p, float arreglo[3][4][2]);
float totales(int m, int n, int p, int i, float arreglo[3][4][2]);

main(){
	int p = 3;
	int n = 4;
	int m = 2;
	float arreglo[3][4][2];
	
	carga(m, n, p, arreglo);
	muestra(m, n, p, arreglo);
	
	printf("\nel pais con mas ventas es: %d", mayorVentaPais(m, n, p, arreglo));
	//totales(m, n, p, arreglo);
	printf("\nEl pais %d tiene $%.2f en ventas.", 0, totales(m, n, p, 0, arreglo));
	printf("\nEl pais %d tiene $%.2f en ventas.", 1, totales(m, n, p, 1, arreglo));
	printf("\nEl pais %d tiene $%.2f en ventas.", 2, totales(m, n, p, 2, arreglo));
}

void carga(int m, int n, int p, float arreglo[3][4][2]){
	srand(time(NULL));
	
	for (int i=0; i<p; i++){
		for (int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				arreglo[i][j][k] = rand()%10;
			}
		}
	}
	
}

void muestra(int m, int n, int p, float arreglo[3][4][2]){

	
	for (int i=0; i<p; i++){
		for (int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				printf("[%.2f] ", arreglo[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
}

int mayorVentaPais(int m, int n, int p, float arreglo[3][4][2]){
	float suma = 0;
	int mayor = 0;
	int posMayor = 0;
	
	
	for (int i=0; i<p; i++){
		for (int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				suma += arreglo[i][j][k];
			}		
		}
		if (suma > mayor){
			mayor = suma;
			posMayor = i;
		}
		suma = 0;		
	}
	
	return posMayor;
}


float totales(int m, int n, int p, int i, float arreglo[3][4][2]){

	float suma = 0;
	
	
		for (int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				suma += arreglo[i][j][k];
			}			
		}
	
		return suma;
	
	
}

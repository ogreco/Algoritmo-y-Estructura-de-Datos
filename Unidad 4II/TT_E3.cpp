/*Una cadena de P hoteles registra por cada uno de los mismos la cantidad de personas 
que ocupan las N habitaciones de los M pisos.En cada hotel la información queda registrada
de la siguiente manera.
 P0  N 0   1   2  3
 M 
   0  20  15  0
   1
   2
   3
   
 P1	N 0   1   2  3
 M 
   0  20  15  0
   1
   2
   3
   
 P2	N 0   1   2  3
 M 
   0  20  15  0
   1
   2
   3
   
   
Se pide:

Ingresar el arreglo a través de una función sin tipo.
Cantidad total de personas alojadas por esta cadena de hoteles. Calcularlo a través de una función con tipo.
Cuál es el número de hotel que tiene mayor cantidad de personas alojadas.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void carga(int matriz[10][10][10], int filas, int columnas, int hotel);
void muestra(int matriz[10][10][10], int filas, int columnas,  int hotel);
int hotel_mayor_cantidad(int matriz[10][10][10], int filas, int columnas, int hotel);
int total_alojadas(int matriz[10][10][10], int nrosuc, int columnas, int nrohotel);

main(){
	
	int n, m, p;
	
	printf("\n Ingresar la cantidad de hoteles: ");
	scanf("%d" ,&p);
	printf("\n Ingresar la cantidad de habitaciones: ");
	scanf("%d" ,&n);
	printf("\n Ingresar la cantidad de pisos: ");
	scanf("%d" ,&m);
	
	int hotel[10][10][10];
	 
    carga(hotel, m, n, p);	
	muestra(hotel, m, n, p);
	printf("\nla cantidad de personas alojadas es %d.", total_alojadas(hotel, m, n, p));
	
	printf("\nel hotel con mayor cantidad de habitantes es %d", hotel_mayor_cantidad(hotel, m, n, p));
}
	     
void carga(int matriz[10][10][10], int filas, int columnas, int hotel){
	srand(time(NULL));
	for(int p=0; p<hotel; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				matriz[p][i][j] = 1 + rand()%10;
			}
		}	
	}
	
}

void muestra(int matriz[10][10][10], int filas, int columnas, int hotel){
   	for(int p=0; p<hotel; p++){
		for(int i=0; i<filas; i++){
			for (int j=0; j<columnas; j++){
				printf("[%d] ", matriz[p][i][j]);
			}	
			printf("\n");	
		}
		printf("\n");
	}
}
	
int hotel_mayor_cantidad(int matriz[10][10][10], int filas, int columnas, int hotel){
	int mayor = matriz[0][0][0];
	int sumahotel = 0;
	int numhotel = 0;
	
	for(int p=0; p<hotel; p++){
		sumahotel = 0;
		for(int i=0; i<filas; i++){			
			for (int j=0; j<columnas; j++){
		 		sumahotel += matriz[p][i][j];
			}			
		}
		
		if (sumahotel > mayor){
				mayor = sumahotel;
				numhotel = p;	
			}
	}

	return numhotel;
	
}

int total_alojadas(int matriz[10][10][10], int nrohabitaciones, int columnas, int nrohotel){
	
	int suma = 0;
	for (int p=0; p<columnas; p++){
		for (int i=0; i<columnas; i++){
			for (int j=0; j<columnas; j++){
				suma += matriz[p][i][j];
			}	
		}
	}
	
	return suma;
  }	


/*Desarrolle la codificación para el siguiente ejercicio:
Ingrese el orden MxM de una matriz, se pide:
1) Ingrese una matriz antisimétrica a través de una función sin tipo
2) Ordene los elementos de la matriz a través de una función sin tipo.
3) Calcule la suma de los elementos del cuadro de la matriz a través de una función con tipo.
*/

#include <stdio.h>


void carga(int matriz[10][10], int orden);
void muestra(int matriz[10][10], int orden);
bool antisimetrica(int matriz[10][10], int orden);

void ordenar(int matriz[10][10], int orden);

main(){
	int matriz[10][10];
	int orden;
	printf("ingrese el orden de la matriz");
	scanf("%d", &orden);
	carga(matriz, orden);
	printf("\n");
	muestra(matriz, orden);
	printf("\n");
	ordenar(matriz, orden);
	muestra(matriz, orden);
}


void carga(int matriz[10][10], int orden){
	
	do{
		for(int i=0; i<orden; i++){
			for(int j=0; j<orden; j++){
				scanf("%d", &matriz[i][j]);
			}	
		}		
	}while(!antisimetrica(matriz, orden));
	
}


bool antisimetrica(int matriz[10][10], int orden){
	int transpuesta[10][10];
	bool b = true;
	
	for(int i=0; i<orden; i++){
		for(int j=0; j<orden; j++){
			transpuesta[i][j] = matriz[j][i]*-1;
		}
	}	
	
	for(int i=0; i<orden; i++){
		for(int j=0; j<orden; j++){
			if (transpuesta[i][j] != matriz[i][j]) b = false;
		}
	}	
	if(!b) printf("la matriz no es antisimetrica");
	else printf("la matriz es antisimetrica");
	return b;
	
	
}

void muestra(int matriz[10][10], int orden){
	for(int i=0; i<orden; i++){
		for(int j=0; j<orden; j++){
			printf("%d ", matriz[i][j]);
		}	
		printf("\n");
	}	
}

void ordenar(int matriz[10][10], int orden){
	int aux;
	
	for (int I=0; I<orden; I++){
		for (int J=0; J<orden; J++){			
			for (int i=0; i<orden; i++){
				for (int j=0; j<orden; j++){
					if (matriz[I][J] < matriz[i][j]){
						aux = matriz[I][J];
						matriz[I][J] = matriz[i][j];
						matriz[i][j] = aux;	
					}
				}		
			}
		}		
	}
	
	
	
}

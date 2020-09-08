/*Una empresa que se dedica a la producción de ropa masculina, posee N talleres para la confección
de las prendas que comercializa, que son pantalones, camisas y remeras. La cantidad mensual
producida de pantalones, camisas y remeras por cada una de sus fábricas son registradas en una
matriz. ¿Determinar el orden de la matriz M x N?
a. Realizar la carga de la matriz, de manera aleatoria.
b. Mostrar la cantidad producida de cada una de sus prendas en los N talleres.
c. Usando una función calcular y mostrar en la función main() cual fue el taller que tuvo mayor
producción.
d. resultado en la función main().
e. d. Realizar la carga de la matriz.

   P   C   R
1  10  50  90 
2  10  30  50
3
4


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(int matriz[100][100], int m, int n);
void muestra(int matriz[100][100], int m, int n);
int elementosColumna(int matriz[100][100], int c, int m);
int elementosFila(int matriz[100][100], int f, int n);
int mayor(int matriz[100][100], int m, int n);

main(){
	int matriz[100][100];
	int m, n=3;
	printf("Ingrese la cantidad de Talleres: ");
	scanf("%d", &m);
	carga(matriz, m, n);
	muestra(matriz, m, n);
	int p, c, r;
	p = elementosColumna(matriz, 1, m);
	c = elementosColumna(matriz, 2, m);
	r = elementosColumna(matriz, 3, m);
	printf(" la cantidad de remeras es de %d, de camisas es de %d, y pantalones %d\n", p, c, r);
	printf("el taller con mayor produccion es %d ", mayor(matriz, m, n));
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

int elementosColumna(int matriz[100][100], int c, int m){
	int s = 0;
	for(int i=0; i<m; i++){
		s += matriz[i][c-1];
	}
	return s;
}

int elementosFila(int matriz[100][100], int f, int n){	
	int s = 0;
	for(int j=0; j<n; j++){
		s += matriz[f-1][j];
	}
	return s;
}

int mayor(int matriz[100][100], int m, int n){
	int may = elementosFila(matriz, 1, n);
	int mayTaller = 1;
	
	for(int i=0; i<m; i++){
		int s = elementosFila(matriz, i+1, n);		
		if (s > may){
			may = s;	
			mayTaller = i+1;
		} 
	}
	
	return mayTaller;
	
}

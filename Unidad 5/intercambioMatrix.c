#include <stdio.h>
#include <stdlib.h>

void cargarMat(int n, int m, int mat[n][m]);  // declaro las funciones
void verMat(int n, int m, int mat[n][m]);
void intercambio(int n, int m, int mat[n][m],int fa,int fb);
int main (){
	int n,m,a,b;
	
	printf("Indique la cantidad de filas que tendra la matriz: ");
	scanf ("%i",&n);
	printf("Indique la cantidad de columnas que tendra la matriz: ");
	scanf ("%i",&m);
	
	printf ("\n");
	
	int mat[n][m];  // declaro la matriz de n filas y m columnas
	
	cargaMat (n, m, mat);  // llamo mis funciones
	verMat (n, m, mat);
	printf ("ingrese el numero de columna para a:");
	scanf("%i",&a);
	printf ("ingrese el numero de columna para b:");
	scanf("%i",&b);
	intercambio(n, m, mat,a,b);
	verMat (n, m, mat);
	system ("pause");
	return 0;
}

void cargaMat (int n, int m, int mat[n][m]){  
	int i,j;
	
	for (i = 0; i < n ; i++){   // para que el usuario me vaya dando los elementos
		for (j = 0; j < m ; j++){
			printf ("Introduzca el #%i valor de la #%i fila: ",j+1,i+1);
			scanf ("%i",&mat[i][j]);
		}
		printf ("\n");
	}
}

void verMat (int n, int m, int mat[n][m]){
	int i,j;
	
	printf ("\tM\t|");
	
	for (i = 0; i < n ; i++){
		
		for (j = 0 ; j < m ; j++){
			
			printf ("%i ",mat[i][j]);
			
			if ( j< m-1){
				printf (" ");
			}
		}
		if (i < n-1){
			printf ("|\n\t\t|");
		}
	}
	printf ("|\n\n");
}
void intercambio(int n, int m, int mat[n][m],int fa,int fb){
	int i,aux;
	for (i=0;i<n;i++){
		aux=mat[i][fa];
		mat[i][fa]=mat[i][fb];
		mat[i][fb]=aux;
	}
}

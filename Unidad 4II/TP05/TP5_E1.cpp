/*01) ? Dado un de MxN donde M=4 y N=3 cuyo contenido son números
reales.
a. Haciendo uso de una función SIN TIPO, Ingrese elementos a la matriz.
b. Haciendo uso de una función CON TIPO, encuentre el mayor y menor elemento de la matriz. Los
valores se mostraran en la función principal main.
c. Usando una función SIN TIPO, liste los elementos de la matriz separados por un guion medio de
manera que se visualicen sus datos en forma de matriz (filas y columnas).*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga(float matriz[4][3]);
void muestra(float matriz[4][3]);
float mayormenor(float matriz[4][3], float &menor);

main(){
	float matriz[4][3];
	carga(matriz);
	muestra(matriz);
	float may, men;
	may = mayormenor(matriz, men);
	printf("el mayor es %f, y el menor es %f", may, men);
}

void carga(float matriz[4][3]){
	srand(time(NULL));
	
	for(int i=0; i<4; i++){
		for(int j=0; j<3; j++){
			matriz[i][j] = rand()%10;
		}	
	}
}

void muestra(float matriz[4][3]){
	
	for(int i=0; i<4; i++){
		for(int j=0; j<3; j++){
			printf("%.2f - ", matriz[i][j]);
		}	
		printf("\n");
	}
}

float mayormenor(float matriz[4][3], float &menor){
	float mayor = matriz[0][0];
	menor = matriz[0][0];
	for(int i=0; i<4; i++){
		for(int j=0; j<3; j++){
			if (matriz[i][j] > mayor) mayor = matriz[i][j];
			if (matriz[i][j] < menor) menor = matriz[i][j];
		}
	}	
	return mayor;
}


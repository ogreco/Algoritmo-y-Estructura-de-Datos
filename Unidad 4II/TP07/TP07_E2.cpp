/*Las coordenadas de dos puntos en un plano deben guardarse en un registro. Hacer un programa con menú de
opciones que permita registrar los dos puntos P1 y P2, representados como registros:
:
1. Cargar dos puntos por teclado.
2. Mostrar los dos puntos en forma de par ordenado. Ej: P1(x1,y1) ; P2(x2,y2)
3. Calcular la distancia del punto P1 al origen de coordenadas (usar teorema de Pitágoras).
4. Calcular y mostrar en pantalla, la longitud del segmento de recta que une los dos puntos.
 
 (P1,P2) = sqrt( (x2 – x1)2+ (y2 – y1)2
 
)*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct punto{
	int x;
	int y;
};
 
void carga(punto &P1, punto &P2);
int distancia(punto p1, punto p2);
 
main(){
	punto P1, P2, origen;
	origen.x = 0;
	origen.y = 0;
	
	carga(P1, P2);
	printf("\nla distancia entre el punto 1 y el origen es %d", distancia(P1, origen));
	printf("\nla distancia entre el punto 1 y el punto 2 es %d", distancia(P1, P2));
	
}

void carga(punto &P1, punto &P2){
	printf("ingrese la coordenada x para P1: ");
	scanf("%d", &P1.x);
	printf("ingrese la coordenada y para P1: ");
	scanf("%d", &P1.y);
	
	printf("ingrese la coordenada x para P2: ");
	scanf("%d", &P2.x);
	printf("ingrese la coordenada y para P2: ");
	scanf("%d", &P2.y);
}

int distancia(punto p1, punto p2){
	return sqrt(pow(p2.x - p1.x, 2)+ pow(p2.y - p1.y, 2));
}

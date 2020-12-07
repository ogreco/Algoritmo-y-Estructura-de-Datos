/*
Cree una estructura dinámica de lista, para almacenar la información de N empleados de una
fábrica de los cuales se debe guardar, la siguiente información:
? legajo
? apellido y nombre
? edad
a) Ingrese los datos de los empleados.
b) Borre la información de uno de ellos.
c) Muestre la información que quedó en la pila

*/

#include <stdio.h>

typedef char cadena[45];

struct Empleado{
	int legajo;
	cadena apellnom;
	int edad;
	Empleado *sig;
};

void carga(Empleado *&pila);
void mostrar(Empleado *pila);
void eliminar(Empleado *&pila, int legajo);

main(){
	Empleado *pila = NULL;
	int n, legajo;
	printf("ingrese la cantidad de valores: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) carga(pila);
	mostrar(pila);
	
	printf("\ningrese un legajo para eliminarlo: ");
	scanf("%d", &legajo);
	eliminar(pila, legajo);
	mostrar(pila);
}

void carga(Empleado *&pila){
	Empleado *e = new Empleado;
	printf("ingrese el legajo ");
	scanf("%d", &e->legajo);
	printf("ingrese el apellido y nombre ");
	_flushall();
	gets(e->apellnom);
	printf("ingrese la edad ");
	scanf("%d", &e->edad);
	
	e->sig = pila;	
	pila = e;
}


void mostrar(Empleado *pila){
	printf("\n");
	while(pila != NULL){
		printf("Legajo: %d\n", pila->legajo);
		printf("Apellido y Nombre: %s\n", pila->apellnom);
		printf("Edad: %d\n", pila->edad);
		printf("\n");
		pila = pila->sig;
	}
}

void eliminar(Empleado *&pila, int legajo){
	Empleado *act = pila, *ant = pila;
	
	while ((act!=NULL) && (act->legajo != legajo)){
 		ant=act;
 		act=act->sig;
 	}
 	
 	if ((act!=NULL) && (act->legajo == legajo)){
 		if (ant!=act){
		 ant->sig=act->sig;
		}else{
		 pila=act->sig;
 		}
 	delete(act);
 	printf("\nNodo eliminado\n");
 	} 
}

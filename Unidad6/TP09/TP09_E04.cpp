/*En un sistema se registra la información de los N programas en una estructura dinámica de pila
implementada dinámicamente,
? Nombre del programa
? Cantidad de líneas
a) Ingresar la información en la pila.
b) Borrar los datos de un programa.
c) Mostrar los datos.
d) Mostrar los datos de los programas registrados.*/

#include <stdio.h>
#include <string.h>

typedef char cadena[45];

struct Programa{	
	cadena nombre;
	int cantLineas;
	bool baja;
	Programa *sig;
};

void carga(Programa *&pila);
void mostrarSinBaja(Programa *pila);
void mostrarTodos(Programa *pila);
void eliminar(Programa *&pila, cadena nombre);
void bajaLogica(Programa *pila, cadena nombre);

main(){
	Programa *pila = NULL;
	int n;
	cadena nombre;
	printf("ingrese la cantidad de valores: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) carga(pila);
	mostrarTodos(pila);
	
	printf("ingrese el nombre del programa a eliminar: ");
	_flushall();
	gets(nombre);
	bajaLogica(pila, nombre);
	printf("\nSin Eliminar: \n");
	mostrarSinBaja(pila);
	
	printf("\nTodos los Registrados: \n");
	mostrarTodos(pila);
}

void carga(Programa *&pila){
	Programa *e = new Programa;
	
	printf("ingrese el nombre del programa: ");
	_flushall();
	gets(e->nombre);
	printf("ingrese la cantidad de lineas: ");
	scanf("%d", &e->cantLineas);
	e->baja = false;
	
	e->sig = pila;	
	pila = e;
}


void mostrarTodos(Programa *pila){
	printf("\n");
	while(pila != NULL){		
		printf("Nombre: %s\n", pila->nombre);
		printf("Lineas de Codigo: %d\n", pila->cantLineas);
		printf("\n");
		pila = pila->sig;
	}
}

void mostrarSinBaja(Programa *pila){
	printf("\n");
	while(pila != NULL){		
		if(!pila->baja){
			printf("Nombre: %s\n", pila->nombre);
			printf("Lineas de Codigo: %d\n", pila->cantLineas);
			printf("\n");			
		}
		pila = pila->sig;
	}
}



void bajaLogica(Programa *pila, cadena nombre){
	while(pila != NULL){		
		if (strcmp(pila->nombre, nombre) == 0) pila->baja = true;
		pila = pila->sig;
	}
}




void eliminar(Programa *&pila, cadena nombre){
	Programa *act = pila, *ant = pila;
	
	while ((act!=NULL) && (strcmp(act->nombre, nombre) != 0)){
 		ant=act;
 		act=act->sig;
 	}
 	
 	if ((act!=NULL) && (strcmp(act->nombre, nombre) == 0)){
 		if (ant!=act){
		 ant->sig=act->sig;
		}else{
		 pila=act->sig;
 		}
 	delete(act);
 	printf("\nNodo eliminado\n");
 	} 
}

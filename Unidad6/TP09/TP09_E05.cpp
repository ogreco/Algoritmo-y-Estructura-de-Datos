/*
Dada la siguiente configuración de un registro:
? Código
? Importe
a) Inicializar una estructura de cola.
b) Ingresar n valores.
c) Borrar un valor.
d) Mostrar los datos de los artículos que quedan
*/


#include <stdio.h>

struct nodo{//producto
	int codigo;
	float importe;
	nodo *sig;
};

void carga(nodo *&frente, nodo *&fondo);
void eliminar(nodo *&frente, int dato);
void mostrar(nodo *frente);

main(){
	nodo *frente = NULL, *fondo = NULL;
	int dato;
	int n;
	printf("ingrese la cantidad de valores: ");
	scanf("%d", &n);
	for (int i=0; i<n; i++)	carga(frente, fondo);
	
	mostrar(frente);
	printf("ingrese el codigo para eliminar ");
	scanf("%d", &dato);
	eliminar(frente, dato);
	mostrar(frente);
}



void carga(nodo *&frente, nodo *&fondo){
	nodo *nuevo = new nodo;
	printf("ingrese el codigo: ");
	scanf("%d", &nuevo->codigo);
	printf("ingrese el importe: ");
	scanf("%f", &nuevo->importe);
	nuevo->sig = NULL;
	
	
	if(frente == NULL) frente = nuevo;
	else fondo->sig = nuevo;
	
	fondo = nuevo;
}

void mostrar(nodo *frente){
	
	while(frente != NULL){
		printf("Codigo: %d -> Importe %f\n", frente->codigo, frente->importe);		
		frente = frente->sig;
	}
	
}

void eliminar(nodo *&frente, int dato){
	nodo *act = frente, *ant = frente;
	
	while ((act!=NULL) && (act->codigo != dato)){
 		ant=act;
 		act=act->sig;
 	}
 	if ((act!=NULL) && (act->codigo == dato)){
 		if (ant!=act){
		 ant->sig=act->sig;
		}else{
		 frente=act->sig;
 		}
 	delete(act);
 	printf("\nNodo eliminado\n");
 	} 
}

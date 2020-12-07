#include <stdio.h>

struct nodo{
	float dato;
	nodo *sig;
};

void carga(nodo *&frente, nodo *&fondo);
void mostrar(nodo *frente);
void ordenar(nodo *frente, int n);
void eliminar(nodo *&frente, float dato)


main(){
	nodo *frente = NULL, *fondo = NULL;
	float dato;
	int n;
	printf("ingrese la cantidad de valores: ");
	scanf("%d", &n);
	for (int i=0; i<n; i++)	carga(frente, fondo);
	ordenar(frente, n);
	mostrar(frente);
	printf("ingrese un dato para eliminar ");
	scanf("%f", &dato);
	eliminar(frente, dato);
	mostrar(frente);
}

void carga(nodo *&frente, nodo *&fondo){
	nodo *nuevo = new nodo;
	printf("ingrese un valor para el nuevo nodo: ");
	scanf("%f", &nuevo->dato);
	nuevo->sig = NULL;
	if(frente == NULL) frente = nuevo;
	else fondo->sig = nuevo;
	
	fondo = nuevo;
}

void mostrar(nodo *frente){
	int i=1;
	while(frente != NULL){
		printf("%d -> %f\n", i, frente->dato);
		i++;
		frente = frente->sig;
	}
	
}

void ordenar(nodo *frente, int n){
	float v[n], aux;
	int i=0;
	nodo *frente2 = frente;
	
	while(frente2 != NULL){	
		v[i] = frente2->dato;
		i++;
		frente2 = frente2->sig;
	}
	
	for(int i=0; i<n; i++)
		for(int j=i; j<n; j++){
			if (v[i] > v[j]){
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	i=0;
	while(frente != NULL){	
		frente->dato = v[i];
		i++;
		frente = frente->sig;
	}
}

void eliminar(nodo *&frente, float dato){
	nodo *act = frente, *ant = frente;
	
	while ((act!=NULL) && (act->dato != dato)){
 		ant=act;
 		act=act->sig;
 	}
 	if ((act!=NULL) && (act->dato == dato)){
 		if (ant!=act){
		 ant->sig=act->sig;
		}else{
		 frente=act->sig;
 		}
 	delete(act);
 	printf("\nNodo eliminado\n");
 	} 
}

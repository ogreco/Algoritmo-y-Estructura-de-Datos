/*En una empresa de servicios de telefonía celular se registra la información de los clientes a ser
atendidos en una estructura de cola, de cada uno de los N clientes se ingresa la siguiente
información:
? Número de atención.
? Número de celular.
? Tipo de reclamo: (F: Facturación, C:Compra, T:Técnico)
a) Ingresar los datos en la cola dinámica.
b) Mostrar los datos del próximo cliente a atender y borrarlo de la cola.

c) Indicar el porcentaje de clientes que fueron por problemas técnicos.*/

#include <stdio.h>
typedef char cadena[60];

struct nodo{//producto
	int nroAtencion;
	cadena nroCelular;
	char tipoReclamo;
	nodo *sig;
};

void carga(nodo *&frente, nodo *&fondo);
void Atender(nodo *frente, int &tecnicos);

main(){
	nodo *frente = NULL, *fondo = NULL;
	int dato;
	int n;
	printf("ingrese la cantidad de valores: ");
	scanf("%d", &n);
	for (int i=0; i<n; i++)	carga(frente, fondo);
	int t = 0;
	Atender(frente, t);
	printf("\nel porcentaje de problemas tecnicos fue %d", t*100/n);
	
	
}



void carga(nodo *&frente, nodo *&fondo){
	nodo *nuevo = new nodo;
	printf("ingrese el nro Atencion: ");
	scanf("%d", &nuevo->nroAtencion);
	printf("ingrese el Telefono: ");
	_flushall();
	gets(nuevo->nroCelular);
	do{
		printf("Tipo de Reclamo: ");
		_flushall();
		scanf("%c", &nuevo->tipoReclamo);	
	}while(nuevo->tipoReclamo != 'F' && nuevo->tipoReclamo != 'C' && nuevo->tipoReclamo != 'T');
	
	nuevo->sig = NULL;
	
	
	if(frente == NULL) frente = nuevo;
	else fondo->sig = nuevo;
	
	fondo = nuevo;
}

void Atender(nodo *frente, int &tecnicos){
	char a;
	while(frente != NULL){
		printf("Continua el cliente: %d", frente->nroAtencion);
		do{
			printf("\ningrese A para atender este cliente.");
			_flushall();
			scanf("%c", &a);
		}while(a != 'A');
		if (frente->tipoReclamo == 'T') tecnicos++;
		frente = frente->sig;
	}
	
}

/*En una empresa de servicios de telefon�a celular se registra la informaci�n de los clientes a ser
atendidos en una estructura de cola, de cada uno de los N clientes se ingresa la siguiente
informaci�n:
? N�mero de atenci�n.
? N�mero de celular.
? Tipo de reclamo: (F: Facturaci�n, C:Compra, T:T�cnico)
a) Ingresar los datos en la cola din�mica.
b) Mostrar los datos del pr�ximo cliente a atender y borrarlo de la cola.

c) Indicar el porcentaje de clientes que fueron por problemas t�cnicos.*/

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

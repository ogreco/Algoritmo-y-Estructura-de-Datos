/*Un médico registra la información de sus pacientes en una estructura dinámica de pila, que
posee los siguientes campos:
? Nombre
? Teléfono
? Edad
a) Ingresar la información de N pacientes.
b) Indicar los datos del paciente con mayor edad.*/

#include <stdio.h>

typedef char cadena[45];

struct Paciente{	
	cadena apellnom;
	cadena telefono;
	int edad;
	Paciente *sig;
};

void carga(Paciente *&pila);
void mostrar(Paciente *pila);
void mayorEdad(Paciente *pila);

main(){
	Paciente *pila = NULL;
	int n;
	printf("ingrese la cantidad de valores: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) carga(pila);
	mostrar(pila);
	mayorEdad(pila);
	
}

void carga(Paciente *&pila){
	Paciente *e = new Paciente;	
	printf("ingrese el apellido y nombre ");
	_flushall();
	gets(e->apellnom);
	printf("ingrese el telefono ");
	gets(e->telefono);
	printf("ingrese la edad ");
	scanf("%d", &e->edad);
	
	e->sig = pila;	
	pila = e;
}


void mostrar(Paciente *pila){
	printf("\n");
	while(pila != NULL){		
		printf("Apellido y Nombre: %s\n", pila->apellnom);
		printf("Edad: %s\n", pila->telefono);
		printf("Edad: %d\n", pila->edad);
		printf("\n");
		pila = pila->sig;
	}
}

void mayorEdad(Paciente *pila){
	int mayorEdad;
	Paciente *aux;
	
	if(pila != NULL){
	  mayorEdad = pila->edad;
	  while(pila != NULL){		
		if (pila->edad > mayorEdad){
			mayorEdad = pila->edad;
			aux = pila;
		}
		pila = pila->sig;
	  }
	  printf("El paciente con mayor edad es: \n");
	  printf("Apellido y Nombre: %s\n", aux->apellnom);
	  printf("Edad: %s\n", aux->telefono);
	  printf("Edad: %d\n", aux->edad);
	  printf("\n");
	  
	}
}

/*
Ingresar en un vector los nombres de las N asignaturas de la carrera Ing. Sistema de Información, 
paralelamente ingresar en otro vector la cantidad de alumnos inscriptos en cada asignatura.
SE PIDE:
a. En una función Sin Tipo, realizar la carga de los vectores en forma simultánea, 
Asignatura y nro. de inscriptos.

b. Haciendo uso de una función Con Tipo, determinar y mostrar en la función main(), 
que asignatura tiene el mayor número de inscriptos.
c. Por medio de una función con tipo, encontrar la cantidad de inscriptos tiene una determinada asignatura.
 El nombre de la asignatura se ingresa por teclado solicitado en la función de búsqueda.

*/
#include <stdio.h>
#include <string.h>

typedef char nombre[45];
typedef int numero;

void carga(numero cant, nombre arregloAsig[], int arregloInsc[]);
void muestra(numero cant, nombre arregloAsig[], int arregloInsc[]);
int mayorInscripcion(numero cant, nombre arregloAsig[], int arregloInsc[]);
int busqueda(numero cant, nombre arregloAsig[], int arregloInsc[]);


main(){
	numero n;
	int pos;
	int cantInsc;
	printf("ingrese la cantidad de asignaturas: ");
	scanf("%d", &n);
	
	nombre asignaturas[n];	
	numero inscriptos[n];
	
	carga(n, asignaturas, inscriptos);
	muestra(n, asignaturas, inscriptos);
	pos = mayorInscripcion(n, asignaturas, inscriptos);
	printf("\nla materia con mayor inscripcion es: %s", asignaturas[pos]);
	
	
	cantInsc = busqueda(n, asignaturas, inscriptos);
	if (cantInsc>-1) printf(" \n tiene %d inscriptos.", cantInsc);
	else printf("\nasignatura no encontrada!");
}


void carga(numero cant, nombre arregloAsig[], int arregloInsc[]){
	for(int i=0; i<cant; i++){
		printf("ingrese el nombre de la asignatura %d: ", i+1);
		_flushall();
		gets(arregloAsig[i]);
		printf("ingrese la cantidad de inscriptos: ");
		scanf("%d", &arregloInsc[i]);
	}
	
	
}

void muestra(numero cant, nombre arregloAsig[], int arregloInsc[]){
	for(int i=0; i<cant; i++){
		printf("\nasignatura %s: ", arregloAsig[i]);
		printf("\ninscriptos: %d\n", arregloInsc[i]);
	}
	
	
}

int mayorInscripcion(numero cant, nombre arregloAsig[], int arregloInsc[]){
	int mayor = arregloInsc[0];	
	nombre nombreMayor;
	strcpy(nombreMayor, arregloAsig[0]);
	int pos = 0;

	for(int i=0; i<cant; i++){
		if (arregloInsc[i]>mayor){
			mayor = arregloInsc[i];	
			strcpy(nombreMayor, arregloAsig[i]);
			pos = i; 
		} 
	}
	
	return pos;	
}

int busqueda(numero cant, nombre arregloAsig[], int arregloInsc[]){
	
	nombre dato;
	printf("\nIningrese el nombre de la asignatura buscada: ");
	_flushall();
	gets(dato);
	
	for(int i=0; i<cant; i++){
		if (strcmp(dato, arregloAsig[i]) == 0) return arregloInsc[i];
	}	
	
	
	return -1;
}



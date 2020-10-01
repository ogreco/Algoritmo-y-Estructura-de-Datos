/*--------------------------------------- 
REGISTRO DE ARREGLO.
---------------------------------------
Que el alumno aprenda a trabajar con REGISTRO DE ARREGLO.

Enunciado:
			Ingrese los datos de un alumno en una estructura como la siguiente: legajo, 
		notas (donde notas es un vector de orden 3).
	SE PIDE: 
		1- Defina la estructura apropiada a los requerimientos.
		2- Ingrese la informaci�n de un alumno (c�digo y sus 3 notas). 
		3- Muestre los datos ingresados con su promedio.
-----------------------------------------*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/*------- Define la Estructura -----*/
struct registro
{ 
	int legajo; 
	float notas[3]; //Vector de orden 3 dentro de la estructura.
};

/*------  Bloque Principal ------*/
main ()
{ 
	registro reg;
	int j; 
	float proNotas, sumNotas=0; 
	
 /*------- Carga del Registro -------*/	
	printf("Ingrese los datos del alumno\n");
	printf("----------------------------\n\n"); 
	printf("Legajo: ");
	scanf("%d",&reg.legajo); 
	for (j=0; j<3 ;j++)		//For para cargar las notas al vector.
    { 
		printf("\tNota %d: ", j+1); 
		scanf("%f",&reg.notas[j]); 
	} 
	
/*------- Listado del Registro ------*/
	printf("\n\nLos datos ingresados del Alumno\n");
	printf("-------------------------------\n\n"); 
	printf("Legajo: %d", reg.legajo); 
	for (j=0; j<3; j++)		//For para listar las notas del vector.
    { 
		printf("\n\tNota %d: %.2f", j+1, reg.notas[j] ); 
		sumNotas = sumNotas + reg.notas[j];		// Suma las notas del alumno.
	}
/*------ Calculo del promedio ------*/
	proNotas =float (sumNotas/3 );		//Calcula el Promedio.
	printf("\n Promedio: %.2f \n ",proNotas); //Muestra el promedio.
	
	printf("\n  Fin del Listado     \n" );
	system("PAUSE"); 
} 


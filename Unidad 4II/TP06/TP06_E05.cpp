/*Un negocio tiene una lista de sus socios (apellidos y nombres). Se le pide realizar un programa, que
por medio de un menú de opciones se pueda realizar lo siguiente:
a. Usando una función, Ingrese los datos de sus socios.
b. Usando una función, Ordenar en el mismo vector los datos en forma decreciente.
c. Usar una función, para mostrar en pantalla la lista de personas.
d. En otro vector ordenar los apellidos en forma creciente (“A” a la “Z”). Mostrar los datos
e. Buscar un determinado apellido que deberá ser introducido por teclado y verificar si existe en la lista.
 Si existe más de una vez indicar la cantidad de veces que aparece.

galleguillo damian
berdu jasmin
garcia celia
coronel juan
garcia olga

************Administracion de Socios*************

1) Ingresar Socio*
2) Ordenar Datos (decreciente)*
3) Mostrar Listado*
4) Mostrar Apellidos Ordenados (creciente)*
5) Buscar Apellido
*************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[45];

void dibujarMenu();
void cargar(cadena apellidos[], cadena nombres[], int &n);
void muestra(cadena apellidos[], cadena nombres[], int n);
void ordenDecreciente(cadena apellidos[], cadena nombres[], int n);
void ordenCreciente(cadena apellidos[], int n);
int busqueda(cadena apellidos[], int n, cadena apellido);

main(){
	int opcion, n=0;
	cadena apellidos[1000], nombres[1000];
	
	do{
		dibujarMenu();
		printf("ingrese una Opcion para continuar: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: cargar(apellidos, nombres, n);
					break;
					
			case 2: ordenDecreciente(apellidos, nombres, n);
					break;
					
			case 3: muestra(apellidos, nombres, n);
					break;
			
			case 4: ordenCreciente(apellidos, n);
					break;
					
			case 5: printf("ingrese un apellido para buscar: ");
					_flushall();
					cadena apellido;
					gets(apellido);
					printf("ese apellido esta %d veces.\n", busqueda(apellidos, n, apellido));
					system("pause");
		}
		
		
		
	}while(opcion != 6);	
	
}


void dibujarMenu(){
	system("cls");
	printf("************Administracion de Socios*************\n");
	printf("\n");
	printf("1) Ingresar Socio\n");
	printf("2) Ordenar Datos (decreciente)\n");
	printf("3) Mostrar Listado\n");
	printf("4) Mostrar Apellidos Ordenados (creciente)\n");
	printf("5) Buscar Apellido\n");
	printf("6) Salir\n");
	printf("*************************************************\n");
}


void cargar(cadena apellidos[], cadena nombres[], int &n){
	
	printf("\ningrese el apellido del socio: ");
	_flushall();
	gets(apellidos[n]);
	printf("\ningrese el nombre del socio: ");	
	gets(nombres[n]);
	n++;
}

void muestra(cadena apellidos[], cadena nombres[], int n){
	for(int i=0; i<n; i++){
		printf("\napellido: ");
		puts(apellidos[i]);
		printf("nombre: ");
		puts(nombres[i]);
		printf("\n");
	}
	
	system("pause");
}

void ordenDecreciente(cadena apellidos[], cadena nombres[], int n){
	cadena auxApel;
	cadena auxNom;
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if (strcmp(apellidos[i], apellidos[j]) < 0){
				strcpy(auxApel, apellidos[j]);
				strcpy(apellidos[j], apellidos[i]);
				strcpy(apellidos[i], auxApel);
				
				strcpy(auxNom, nombres[j]);
				strcpy(nombres[j], nombres[i]);
				strcpy(nombres[i], auxNom);
			}	
		}	
	}
	
	printf("datos ordenados\n");
}

void ordenCreciente(cadena apellidos[], int n){
	cadena otro[n];
	for(int i=0; i<n; i++){
		strcpy(otro[i], apellidos[i]);		
	}
	
	cadena aux;
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if (strcmp(otro[i], otro[j]) > 0){
				strcpy(aux, otro[j]);
				strcpy(otro[j], otro[i]);
				strcpy(otro[i], aux);				
			}	
		}	
	}
	
	for(int i=0; i<n; i++){
		puts(otro[i]);		
	}
	system("pause");
}

int busqueda(cadena apellidos[], int n, cadena apellido){
	int c = 0;
	for(int i=0; i<n; i++){
		if (strcmp(apellidos[i], apellido) == 0) c++;
	}
	
	return c;
	
}


//Se debe ingresar por teclado el Apellido y nombre de una persona y mostrar por pantalla las
//cadenas ingresadas, utilizando printf(...), scanf(...), gets(...), puts(...).
//Realizar Codificación en Dev-C++

/*
Realizar una prueba de ingresos de datos
//Ejemplo 1
Apellido: Casasola
Nombre: Juan.
Notaras en la salida que todo se muestra bien.

///Ejemplo 2
Apellido: Casasola
Nombre: Juan Manuel
Notaras en la salida que la segunda palabra del
identificador nombre, Manuel, no se muestra.

///Ejemplo 3
Apellido: Casasola Ruiz
Nombre: Juan Manuel
*/



#include <stdio.h>
#include <stdlib.h>
 
main() 
  { 
	typedef char Cadena[30];  //Crea un nuevo tipo de dato llamado Cadena, que es un vector de 30 caracteres.
	Cadena ListaDeNombre[100]; //define un vector de tipo Cadena, llamado ListaDeNombre de 100 caracteres.    
	int i, CantPers;  
	printf("Cuantas personas desea ingresar: ");
	scanf("%d", &CantPers); 
	_flushall(); //Función que limpia el buffers de entrada.   
	 
 
	printf("\n\n...............Registraci\242n de Personas......................\n\n"); 
	for(i=0; i<CantPers; i++) 
	{
	     printf("Ingrese Apellido y Nombre/s de la persona %d: ", i+1);
		 gets(ListaDeNombre[i]);
		 
	} //Fin de la carga de Personas. 
	system("CLS");
	
	printf("\t...................Listado de Personas Ingresadas..............\n");
	for(i=0; i<CantPers; i++)
	    {   puts(ListaDeNombre[i]);  }
		 //Fin del listado de Personas ingresadas.
		 
	printf("\n\n"); 
	system("PAUSE");
} 

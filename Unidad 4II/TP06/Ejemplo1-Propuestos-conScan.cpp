
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
    typedef char cadena1[16], cadena2[31];  //Define dos tipos de datos char nuevos.   
	cadena1 apellido;     //Define la variable apellido del tipo de dato cadena1.
	cadena2 nombres;      //Define la variable nombres del tipo de dato cadena2.
    printf("Introduzca los Apellidos: ");
	scanf("%s", apellido);  
	printf("Introduzca los Nombres: ");
	scanf("%s", nombres); 
	printf("\n-------------------------\n");
	printf("\n Los datos son: %s, %s \n", apellido, nombres);
	system("PAUSE");							
  }   

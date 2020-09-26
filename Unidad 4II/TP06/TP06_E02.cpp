/*Ingresar una lista con los nombres de personas, separados por una coma. La cadena tiene un tamaño
máximo de 100 caracteres. Ejemplo de cómo se ingresa la lista: Juan, Pedro, Angela, Beatriz, Jose, Luis, Angel,
 El ingreso termina cuando se presiona la tecla Enter.
a. Haciendo uso de una Función Sin Tipo, por pantalla Mostrar cada una de las palabras que forman la cadena una
debajo de la otra. 
Ten en cuenta que el separador de palabras es la coma.
b. Haciendo uso de una función Con tipo devolver la longitud de la cadena ingresada. 
No utilizar la función strlen(cadena), incluida en la biblioteca string.h. 
(Lo que deberá hacer es contar caracter por caracter)*/

#include <stdio.h>
#include <string.h>
typedef char cadena[100];

void mostrarPalabras(cadena nombres);
int longitud(cadena nombres);

main(){
	cadena nombres;
	
	printf("\ningrese una lista de nombres separados por , (coma)");
	_flushall();
	gets(nombres);
	/*nombres[40] = '\0';
	puts(nombres);*/
	
	mostrarPalabras(nombres);
	printf("\nla cantidad de caracateres de la cadena es %d", longitud(nombres));
}

void mostrarPalabras(cadena nombres){
	for(int i=0; i<strlen(nombres); i++){
		if (nombres[i] == ',') printf("\n");
		else printf("%c", nombres[i]);
	}
	/*Juan
	 Pedro
	  Angela, Beatriz, Jose, Luis, Angel,*/
}

int longitud(cadena nombres){
	int c=0;
	while (nombres[c] != '\0'){
		c++;
	}	
	return c;
}

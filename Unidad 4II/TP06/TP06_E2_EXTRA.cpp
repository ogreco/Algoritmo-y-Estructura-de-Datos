/*
Escriba un programa que lea una cadena desde el teclado el ingreso termina cuando se presione la tecla enter.
Se Pide:
a. Cuente el número de caracteres de tres categorías: 
letras (a-z y A-Z), 
dígitos (0-9) y 
otros caracteres. 
Utilice las funciones: isdigit() e isalpha() definidas en la librería ctype.h. Mostrando
el resultado en la función main().
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char cadena[90];

main(){
	cadena x;
	printf("ingrese una cadena y luego enter para finalizar. \n");
	gets(x);
	int digitos = 0, letras = 0, otros = 0;
	
	for(int i=0; i<strlen(x); i++){
		if (isdigit(x[i])) 	digitos++;
			else if (isalpha(x[i])) letras++;
				 else otros++;
	}
	
	printf("Letras: %d\nNumeros: %d\nOtros: %d\n", letras, digitos, otros);
	
}

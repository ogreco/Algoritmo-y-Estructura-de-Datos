/*Realizar un programa que reciba por teclado diferentes palabras, hasta que se ingrese la palabra "final". 
Entonces se deberá mostrar por pantalla cual fue la palabra más larga ingresada y cuantas palabras
se ingresaron sin contar la palabra “final”.*/

#include <stdio.h>
#include <string.h>

main(){
	char palabra[50];
	char mayorpalabra[50];
	int mayor = 0;
	int c = 0;
	
	do{
		gets(palabra);
		if (strcmp(palabra, "final") != 0){
			if (strlen(palabra) > mayor){
			mayor = strlen(palabra);
			strcpy(mayorpalabra, palabra);			
			} 
			c++;	
		}		
	}while(strcmp(palabra, "final") != 0);
	
	printf("\nla palabra con mayor cantidad de caracteres fue %s", mayorpalabra);
	printf("\nla cantidad de palabra fue %d", c);
}

/*
Se tiene un poema con un máximo de 200 caracteres. 
Se solicita un programa que permita el ingreso
del poema para luego contar y mostrar en pantalla: 


cuantas consonantes, 
letras mayúsculas, 
letras minúsculas 
vocales, 

dígitos, 
espacios. 

signos de puntuación, 

Para el ingreso del poema se utilizara gets() y para la salida puts().
*/
#include <stdio.h>
#include <string.h>

typedef char poema[200];

bool isVocal(char x);

main(){
	poema Poema;
	int mayusculas = 0, minusculas = 0, vocales = 0, consonantes = 0, numeros = 0, espacios = 0, otros = 0;
	
	
	
	printf("ingrese un poema de no mas de 200 caracteres: \n");
	gets(Poema);
	
	
	
	
	for(int i=0; i<strlen(Poema); i++){			
		if (Poema[i] > 64 && Poema[i] < 90){
			mayusculas++;	
			if (isVocal(Poema[i])) vocales++;
			else consonantes++;
		}else 
			if (Poema[i] > 96 && Poema[i] < 123){
				minusculas++;	
				if (isVocal(Poema[i])) vocales++;
				else consonantes++;
			}else
				if (Poema[i] > 47 && Poema[i]< 58){
					numeros++;
				}else
				 if (Poema[i] == ' ') espacios++;
				 else otros++;
		
	}
	
	printf("mayusculas = %d\nminusculas = %d\nvocales = %d\n consonantes = %d\n numeros = %d\n espacios = %d\n otros = %d", mayusculas, minusculas, vocales, consonantes, numeros, espacios, otros);
	
}

bool isVocal(char x){
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
	       x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U';
}




/*Se tiene un poema con un máximo de 200 caracteres. Se solicita un programa que permita el ingreso
del poema para luego contar y mostrar en pantalla: 
cuantas 
	consonantes, 
	vocales, 
	dígitos, 
	signos de puntuación, 
	letras mayúsculas, 
	letras minúsculas 
	espacios. 
Para el ingreso del poema se utilizara gets() y para la salida puts().*/

#include <stdio.h>
#include <string.h>
typedef char cadena[200];

main(){
	cadena poema;
	int consonantes = 0, 
	vocales = 0, 
	digitos = 0, 
	signos_de_puntuacion = 0, 
	letras_mayusculas = 0, 
	letras_minusculas = 0,
	espacios = 0;
	
	printf("\ningrese el poema: \n");
	_flushall();
	gets(poema);
	
	for(int i=0; i<strlen(poema); i++){
		if (poema[i]>=65 && poema[i]<=90){
			letras_mayusculas++;
			if (poema[i]=='A' || poema[i]=='E'||poema[i]=='I'||poema[i]=='O'||poema[i]=='U') vocales++;
			else consonantes++;
		} 
		
		if(poema[i]>=97 && poema[i]<=122){
			letras_minusculas++;		
			if (poema[i]=='a' || poema[i]=='e'||poema[i]=='i'||poema[i]=='o'||poema[i]=='u') vocales++;
			else consonantes++;
		}
		
		if (poema[i]>=48 && poema[i]<=57) digitos++;
		if (poema[i]=='{' || poema[i]=='}'||
			poema[i]==','||poema[i]==';'||
			poema[i]=='.'||poema[i]==':'||
			poema[i]=='('||poema[i]==')'||
			poema[i]=='-'||poema[i]=='"'||
			poema[i]=='!'||poema[i]=='¡'||
			poema[i]=='?'||poema[i]=='¿') signos_de_puntuacion++;
		if (poema[i]==' ') espacios++;
	}
	
	
	printf("%d, %d, %d, %d, %d, %d, %d", consonantes, 
	vocales, 
	digitos, 
	signos_de_puntuacion, 
	letras_mayusculas, 
	letras_minusculas,
	espacios);
}

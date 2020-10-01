/*
Cadena:

Crear un vector de cadenas de caracteres.
Ingresar los valores en el vector
Ordenar el vector
Mostrar el vector ordenado.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char cadena[60];
void muestra(cadena v[], int n);
void ordenar(cadena v[], int n);
//int contarVocales(cadena v[], int n);

main(){
	int n;
	printf("ingrese la cantidad de palabras");
	scanf("%d", &n);
	cadena v[n];
	
	for(int i=0; i<n; i++){
		printf("ingrese una palabra: ");
		_flushall();
		gets(v[i]);
	}
	ordenar(v, n);
	muestra(v, n);
	//printf("la cantidad de palabras que inician con vocal es de %d", contarVocales(v, n));
}

void muestra(cadena v[], int n){
	for(int i=0; i<n; i++){
		//printf("%s\n", v[i]);		
		puts(v[i]);
	}
}

void ordenar(cadena v[], int n){
	cadena aux;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(strcmp(v[i], v[j]) < 0){ //v[i] < v[j]   -1 0 1
				strcpy(aux, v[j]); // aux = v[j];
				strcpy(v[j], v[i]);
				strcpy(v[i], aux);
			}
		}			
	}
}
/*
int contarVocales(cadena v[], int n){
	int c = 0;
	char primeraLetra;
	
	for(int i=0; i<n; i++){	  
	  primeraLetra = v[i][0];
	  if (primeraLetra == 'a' || primeraLetra == 'e' || primeraLetra == 'i' ||
	      primeraLetra == 'o' || primeraLetra == 'u') c++;	
	}
	
	return c;
}*/

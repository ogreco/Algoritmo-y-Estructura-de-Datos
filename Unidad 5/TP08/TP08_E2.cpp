/*Al iniciar el programa el sistema deberá abrir para su escritura, sin perder los datos, el archivo
numeros.dat en caso de que no exista el archivo deberá crear el archivo numero.dat y almacenar (guardar)
la cantidad de 276 números enteros comprendido entre el rango de valores [125…789].


Creado o abierto el archivo, realizar un menú que permita mostrar en la función main la siguiente
información:
? Determinar cuántos valores pares e impares están guardado en el archivo.
? Listar el archivo.
? Agregar nuevos Datos. Verificando que el valor ingresado sea un entero.
? Ingresar por teclado un valor y determinar si el mismo está almacenado (guardado) en archivo. 
Enviar un mensaje en pantalla indicando si se encontró o no dicho valor.
? Determinar cuántos valores están en el rango [125…500] y (500…789].*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void paresimpares(FILE *f, int &contPar, int &contImp);
void visualiar(FILE *f);
main(){
	FILE *archivo = fopen("numeros.dat", "a+b");
	srand(time(NULL));
	int numero;
	
	for(int i=0; i<276; i++){
		numero = 125+rand()%(790-125);
		fwrite(&numero, sizeof(int), 1, archivo);
	}
	
	int cp, ci;
	paresimpares(archivo, cp, ci);
	printf("\nla cantidad de pares es %d y de impares es %d\n", cp, ci);
	visualiar(archivo);
	
}

void paresimpares(FILE *f, int &contPar, int &contImp){
	contPar = 0;
	contImp = 0;
	
	int lectura;
	rewind(f);
	fread(&lectura, sizeof(int), 1, f);
	while(!feof(f)){
		if (lectura % 2 == 0) contPar++;
		else contImp++;
		
		fread(&lectura, sizeof(int), 1, f);
	}
	
}

void visualiar(FILE *f){
	int lectura;
	int c = 0;
	rewind(f);
	fread(&lectura, sizeof(float), 1, f);
	while(!feof(f)){
	
		printf("%d", lectura);		
		
		if (c < 9){
			printf(" - ");
			c++;
		}			
		else{
			printf("\n");
			c = 0;
		}
		fread(&lectura, sizeof(float), 1, f);
	}
	
}


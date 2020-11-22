/*Una empresa tiene dos empleados los cuales reciben en sus cuentas de correos diferentes email con
frases de una longitud no superior a 80 caracteres cada frase. 

Cada cierto número de frases estas deben ser
guardadas en un archivo de texto sin perder lo que se tenía ya guardado en el archivo.

Se Pide: que por medio de un menú se pueda realizar lo siguiente
a- Al abrir el sistema (programa) se deben crear los archivos “Archivo1.txt” y “Archivo2.txt”
b- Crear y Guardar la/s frase/s recibida por el empleado José Luis en el fichero “Archivo1.txt”. La/s
frase/s son ingresada por teclado.
c- Crear y Guardar las frases recibida por la empleada María Emilia en el fichero “Archivo2.txt”.
La/s frase/s son ingresada por teclado.


d- Al final del día ambos archivos son guardados en un único fichero. Deberá combinar ambos archivos mezclados, en un nuevo fichero “Frases.txt”. Es decir, una frase del Archivo1.txt y una del Archivo2.txt, otra del archivo1 otra del archivo2 y así sucesivamente.

e- Mostrar las frases del archivo de José Luis en minúscula.
f- Mostrar las frases del archivo de María Emilia en Mayúscula.
g- Mostrar las frases del Archivo combinado. Donde cada palabra deberá comenzar en mayúscula y el
resto de cada palabra en minúscula.
h- Al salir del sistema, Los archivos, Archivo1.txt y Archivo2.txt, creados deberán ser eliminados físicamente.
Nota: Tener en cuenta que para los ítems d, e, f existen funciones que realizan tales operaciones. También
se puede hacer de manera secuencial, analizando cada palabra. Deberán elegir que aplicar. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char frase[80];
char dibujarMenu();
void combinar(FILE *arch1, FILE *arch2);

main(){
	FILE *arch1 = NULL, *arch2 = NULL;	
	frase fraseX;
	char opc;
	do{
		opc = dibujarMenu();
		switch(opc){
			case 'a':arch1 = fopen("misfrases1.txt", "a+");
					 arch2 = fopen("misfrases2.txt", "a+");
					 if(arch1 == NULL || arch2 == NULL) {
						printf("el archivo no se pudo crear");
							return 0;	
					 }
					 break;
			case 'b':if(arch1 != NULL) {
						printf("ingrese una frase para Jose Luis: ");
						_flushall();
						gets(fraseX);
						fprintf(arch1, "\n%s", fraseX);
				     }else printf("el archivo no se pudo crear");
					break;
			case 'c':if(arch2 != NULL) {
						printf("ingrese una frase para Maria Emilia: ");
						_flushall();
						gets(fraseX);
						fprintf(arch2, "\n%s", fraseX);
				     }else printf("el archivo no se pudo crear");
					break;
			case 'd': combinar(arch1, arch2);
		}
		system("pause");
	}while(opc != 'f' && opc != 'F');
	
	
	fclose(arch1);
	fclose(arch2);
}

char dibujarMenu(){
	system("cls");
	printf("*********************VENTAS*************************\n");
	printf("\t a) Crear Archivos\n");
	printf("\t b) Cargar frases de Jose Luis\n");
	printf("\t c) Cargar frases de Maria Emilia\n");
	printf("\t d) Combinar ambos archivos\n");
	printf("\t e) Listado total de Ventas\n");
	printf("\t f) Salir\n");
	printf("****************************************************\n");
	printf("ingrese la opcion deseada: \n");
	char opc;
	_flushall();
	scanf("%c", &opc);
	return opc;
}

void combinar(FILE *arch1, FILE *arch2){
	FILE *combinado = fopen("combinado.txt", "w+");
	rewind(arch1);
	rewind(arch2);
	int c = 0;
	char lect1, lect2;
	fgets(&lect1, 1, arch1);
	fgets(&lect2, 1, arch2);
	while(!feof(arch1) || !feof(arch2)){
		
		if (c%2==0){
		   fprintf(combinado, "%c", lect1);	
		   fgets(&lect1, 1, arch1);
		} 
		else{
		   fprintf(combinado, "%c", lect2);	
		   fgets(&lect2, 1, arch2);
		} 
		
		if (lect1 == 10){
			c++;
			fgets(&lect1, 1, arch1);
		} 
		if (lect2 == 10){
			c++;	
			fgets(&lect2, 1, arch2);
		} 
	}
	
	fclose(combinado);
}

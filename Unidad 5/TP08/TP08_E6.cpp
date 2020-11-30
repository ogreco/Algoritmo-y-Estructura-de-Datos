/*Crear un archivo de texto en donde se guardaran los siguientes de N estudiante, cada dato (campo)
que se almacenan en el archivo son los siguientes
Nombre.
Apellidos.
Carrera que estudia.
Nota promedio.
1) Realizar la carga de los N estudiantes, tenga en cuenta que cada uno de los datos estará separado por un
 punto y como “;” y los datos de cada estudiante debe ocupar una línea en el
archivo.
2) Realizar el listado de los datos guardados.
3) Contar la cantidad de apellidos iguales que tiene el archivo.
4) Contar cuantos estudiantes cursan la misma carrera.
5) Ingresar el apellido y nombre de un estudiante y mostrar la carrera que estudia y su nota
promedio. Tenga en cuenta que los datos se pueden ingresar de diferente forma ej: todo en
mayúscula, minúscula, alguna mayúscula.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[45];

struct elemento{
	cadena descripcion;
	int cantidad;
};

void split(cadena x, cadena array[4], char patron);
void mostrarArray(cadena array[4]);
void listado(FILE *arch);
void contarRepetidos(elemento conjunto[100], int &n, FILE * arch);
void contarApellidosRepetidos(FILE * arch);
void contarCarreras(FILE * arch);
void buscarYMostrar(FILE * arch, cadena nombre);

main(){
	FILE *arch = fopen("datos.txt", "a+");
	int n;
	cadena nombre;
	cadena apellido;
	cadena carrera;
	float promedio;
	
	elemento conjunto[100];

	printf("ingrese la cantidad de estudiantes: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("ingrese el nombre ");
		_flushall();
		gets(nombre);
		printf("ingrese el apellido ");		
		gets(apellido);
		printf("ingrese el carrera ");		
		gets(carrera);
		printf("ingrese el promedio ");		
		scanf("%f", &promedio);
		fprintf(arch, "%s;%s;%s;%f\n", nombre, apellido, carrera, promedio);
	}
	
	listado(arch);
	contarApellidosRepetidos(arch);
	printf("\n");
	contarCarreras(arch);
	printf("\ningrese el nombre para ver sus datos: ");
	_flushall();
	gets(nombre);
	buscarYMostrar(arch, nombre);
	fclose(arch);
	
}

void mostrarArray(cadena array[4]){
	for(int i=0; i<4; i++){
		puts(array[i]);
	}
}

void split(cadena x, cadena array[4], char patron){
	
	int j = 0;
	strcpy(array[0], "");	
	for(int i=0; i<strlen(x); i++){
		if (x[i] == patron){			
			j++;	
			strcpy(array[j], "");
		} 
		else {			
			array[j][strlen(array[j])+1] = '\0'; 
			array[j][strlen(array[j])] = x[i]; 	
		}
	}
	
}

void listado(FILE *arch){
	rewind(arch);
	char lectura[100];
	cadena array[4];
	fgets(lectura, 100, arch);
	
	while(!feof(arch)){
		//printf("%s", lectura);
		split(lectura, array, ';');
		mostrarArray(array);
		fgets(lectura, 100, arch);
		
	}
	
}

void contarApellidosRepetidos(FILE * arch){
	rewind(arch);
	char lectura[100];
	cadena array[4];
	fgets(lectura, 100, arch);	
	elemento conjunto[100];
	int n = 0;
		
	while(!feof(arch)){
		split(lectura, array, ';');
		bool b = false;
		for(int i=0; i<n; i++){
			if (strcmp(array[1], conjunto[i].descripcion) ==0 ){// incremento contador si existe dato
				conjunto[i].cantidad++;	
				b = true;				
			}
		}
		
		if (!b){//agrego nuevo dato y contador
			strcpy(conjunto[n].descripcion, array[1]);
			conjunto[n].cantidad = 1;
			n++;
		}
		
		
		fgets(lectura, 100, arch);
		
	}
	
	for(int i=0; i<n; i++){
		printf("%s, %d\n", conjunto[i].descripcion, conjunto[i].cantidad);
	}
}


void contarCarreras(FILE * arch){
	rewind(arch);
	char lectura[100];
	cadena array[4];
	fgets(lectura, 100, arch);	
	elemento conjunto[100];
	int n = 0;
	
	while(!feof(arch)){
		split(lectura, array, ';');
		bool b = false;
		for(int i=0; i<n; i++){
			if (strcmp(array[2], conjunto[i].descripcion) ==0 ){// incremento contador si existe dato
				conjunto[i].cantidad++;	
				b = true;				
			}
		}
		
		if (!b){//agrego nuevo dato y contador
			strcpy(conjunto[n].descripcion, array[2]);
			conjunto[n].cantidad = 1;
			n++;
		}		
		fgets(lectura, 100, arch);		
	}
	
	for(int i=0; i<n; i++){
		printf("%s, %d\n", conjunto[i].descripcion, conjunto[i].cantidad);
	}
}

void buscarYMostrar(FILE * arch, cadena nombre){
	rewind(arch);
	char lectura[100];
	cadena array[4];
	fgets(lectura, 100, arch);
	
	while(!feof(arch)){	
		split(lectura, array, ';');
		if (strcmp(array[0], nombre) == 0) mostrarArray(array);
		fgets(lectura, 100, arch);
		
	}
}









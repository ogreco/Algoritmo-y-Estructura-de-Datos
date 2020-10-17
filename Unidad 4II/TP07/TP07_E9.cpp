/*
Se desea almacenar el inventario de un comercio de art�culos deportivos, en un arreglo de registro.
La descripci�n de cada art�culo, contiene.
- C�digo, Descripci�n, cantidad en stock, precio unitario.
Desarrolla un programa controlado por un men�, que brinde opciones para:
a. Ingresar N registros en el arreglo.
b. Buscar un art�culo, dado su c�digo y mostrar sus datos en pantalla. 
Si el art�culo es encontrado dar la posibilidad de
eliminar dicho art�culo del arreglo. 
En caso de no ser encontrado mostrar por pantalla informando que el art�culo no
fue encontrado. Tener en cuenta que si se elimin� un art�culo, se debe reagrupar el arreglo para no dejar 
celdas vac�as.

c. Lista todo el inventario, ordenado alfab�ticamente (decreciente) seg�n descripci�n de cada art�culo. 
El ordenamiento se deber� realizar en otro arreglo.

d. Lista todo el inventario, ordenado crecientemente por cantidad de stock. (usar otro arreglo, puede ser el mismo que
se us� para ordenar alfab�ticamente.
*/
#include <stdio.h>
#include <string.h>

typedef char cadena[45];

struct articulo{
	int codigo;
	cadena descripcion;
	int stock;
	float precio;
};

void carga(articulo v[], int n);
void muestra(articulo v[], int n);
void busqueda(articulo v[], int &n, int cod);
void ordenar(articulo v[], int n);
void ordenarxcant(articulo v[], int n);

main(){
	int n;
	printf("ingrese la cantidad de articulos");
	scanf("%d", &n);
	articulo inventario[n];
	
	carga(inventario, n);
	int cod;
	printf("\ningrese un codigo para buscar el articulo: ");
	scanf("%d", &cod);
	busqueda(inventario, n, cod);
	ordenar(inventario, n);
	ordenarxcant(inventario, n);
}

void carga(articulo v[], int n){
	for(int i=0; i<n; i++){
		printf("ingrese el codigo del articulo: ");
		scanf("%d", &v[i].codigo);
		printf("ingrese la descripcion: ");
		_flushall();
		gets(v[i].descripcion);
		printf("ingrese el stock del articulo: ");
		scanf("%d", &v[i].stock);
		printf("ingrese el precio del articulo: ");
		scanf("%f", &v[i].precio);
	}
}

void busqueda(articulo v[], int &n, int cod){
	int opc;
	bool b = false;
	for(int i=0; i<n; i++){
		if (v[i].codigo == cod){
			b = true;
			printf("\nCodigo: %d", v[i].codigo);
			printf("\nDescripcion: %s", v[i].descripcion);
			printf("\nCantidad: %d", v[i].stock);
			printf("\nPrecio: %f", v[i].precio);
			printf("\nDesea eliminar este registro? 0(no)/1(si)");
			scanf("%d", &opc);
			if (opc == 1){
				for(int j=i; j<n-1; j++){
					v[j] = v[j+1];
				}
				n = n - 1;
			}
		}
	}
	if (!b) printf("\nel articulo no fue encontrado.");
}

void muestra(articulo v[], int n){
	for(int i=0; i<n; i++){
		printf("\nCodigo: %d", v[i].codigo);
		printf("\nDescripcion: %s", v[i].descripcion);
		printf("\nCantidad: %d", v[i].stock);
		printf("\nPrecio: %f", v[i].precio);				
	}
}

void ordenar(articulo v[], int n){
	articulo v2[n];
	articulo aux;
	for(int i=0; i<n; i++){
		v2[i] = v[i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if (strcmp(v2[i].descripcion, v2[j].descripcion) == -1){
				aux = v2[i];
				v2[i] = v2[j];
				v2[j] = aux;
			}
		}			
	}
	
	muestra(v2, n);
}

void ordenarxcant(articulo v[], int n){
	articulo v2[n];
	articulo aux;
	for(int i=0; i<n; i++){
		v2[i] = v[i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if (v2[i].stock > v2[j].stock){
				aux = v2[i];
				v2[i] = v2[j];
				v2[j] = aux;
			}
		}			
	}
	
	muestra(v2, n);
}







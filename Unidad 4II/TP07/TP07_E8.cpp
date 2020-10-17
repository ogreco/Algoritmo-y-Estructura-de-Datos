/*
? En un negocio de venta de art�culos para el hogar se registra el stock o existencia de sus productos 
en un vector de estructuras que tiene los siguientes datos:
? C�digo. //C�digo producto 5 d�gitos.
? Art�culo. //Nombre del producto.
? Cantidad m�nima. //es el stock m�nimo que puede tener el producto.
? Fecha �ltima Compra. (anidar) //Fecha �ltima Compra realizada.
? Existencia Actual. //Cantidad disponible del producto para la venta.
? Precio //Monto de venta final al p�blico.
: definir las estructuras necesarias para

a. Ingresar como m�nimo 10 productos.

b. Ingresado un determinado c�digo, actualizar su existencia actual y la fecha de compra. 
Usar funci�n que recibe entre otros datos necesarios el c�digo del producto, fecha de compra, cantidad comprada. 
En caso de no encontrar el c�digo del producto mostrar un mensaje de error.


c. Realizar la venta de un determinado producto solicitando su c�digo y mostrar
 en pantalla su descripci�n, precio, solicitar la cantidad comprada y mostrar el monto a pagar. 
 Controlar que la Venta no sea mayor a la Existencia actual. Usar funci�n.
Ejemplo:
C�digo Descripci�n Precio/Unitario Cantidad Solicitada Monto Pagar
Mostrar informaci�n del registro Mostrar informaci�n registro Precio * cantidad


d. Usando una funci�n mostrar por pantallas todos los productos que tienen una existencia Actual menor
 a la cantidad m�nima para realizar el pedido o compra de los productos y reponer su stock.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha{
	int dia, mes, anio;
};

struct producto{
 int codigo; //C�digo producto 5 d�gitos.
 char articulo[30]; //Nombre del producto.
 float cantidad_min; //es el stock m�nimo que puede tener el producto.
 fecha fecha_ultima_compra;//Fecha �ltima Compra realizada.
 float existencia_Act; //Cantidad disponible del producto para la venta.
 float precio; //Monto de venta final al p�blico.
};

void actualizar(producto v[], int n, int cod, fecha f, float cantidad);
void regVenta(producto v[], int n, int cod, fecha f, float cantidad);
void listado(producto v[], int n);
main(){
	
	int n;
	do{
		printf("ingrese la cantida de productos, al menos 10: ");
		scanf("%d", &n);	
	}while(n<2);
	producto prod[n];
	
	
      for(int i=0; i<n; i++)
	  {
		printf("ingrese el codigo del producto: ");
		scanf("%d",&prod[i].codigo);
	  	_flushall();
		printf("Ingrese el nombre del producto: ");		
		gets(prod[i].articulo);
		printf("ingrese el stock minimo que puede tener el producto: ");
		scanf("%f",&prod[i].cantidad_min);
		printf("ingrese la fecha de la ultima compra realizada: ");
			scanf("%d/%d/%d", &prod[i].fecha_ultima_compra.dia,
						  	  &prod[i].fecha_ultima_compra.mes,
						      &prod[i].fecha_ultima_compra.anio);
		printf("ingrese la cantidad disponible del producto para la venta: ");
		scanf("%f",&prod[i].existencia_Act);
		printf("ingrese el monto de venta: ");
		scanf("%f",&prod[i].precio);		
	}
	
	int opc;
	do{
		system("cls");
		printf("ingrese 1 para actualizar: ");
		printf("ingrese 2 para registrar venta: ");
		printf("ingrese 3 para listado de productos con stock bajo: ");
		printf("ingrese 4 para salir: ");
		scanf("%d", &opc);
		int cod;
		fecha f;
		float cant;
		switch(opc){
			case 1:
					
					printf("ingrese el codigo que desea acutalizar: ");
					scanf("%d", &cod);
					printf("ingrese la nueva fecha: ");
					scanf("%d/%d/%d", &f.dia, &f.mes, &f.anio);
					printf("ingrese la nueva cantidad: ");
					scanf("%f", &cant);
					actualizar(prod, n, cod, f, cant);
			        break;
			case 2: 
					printf("ingrese el codigo que desea vender: ");
					scanf("%d", &cod);
					printf("ingrese la fecha: ");
					scanf("%d/%d/%d", &f.dia, &f.mes, &f.anio);
					printf("ingrese la cantidad vendida: ");
					scanf("%f", &cant);
					regVenta(prod, n, cod, f, cant);
					break;	
			case 3: listado(prod, n);
					system("pause");
					break;
		}
	}while(opc!=4);
}

void actualizar(producto v[], int n, int cod, fecha f, float cantidad){
	bool b = false;
	
	for(int i=0; i<n; i++){
		if(v[i].codigo == cod){
			b = true;
			v[i].fecha_ultima_compra = f;
			v[i].existencia_Act = cantidad;
		}
	}
	
	if(!b) printf("Error no existe ese producto");
}

void regVenta(producto v[], int n, int cod, fecha f, float cantidad){
	bool b = false;
	
	for(int i=0; i<n; i++){
		if(v[i].codigo == cod){
			if(v[i].existencia_Act >= cantidad){
				b = true;
				v[i].fecha_ultima_compra = f;
				v[i].existencia_Act -= cantidad;	
			}else printf("No posee suficiente stock");
		}
	}
	
	if(!b) printf("Error no existe ese producto");
}

void listado(producto v[], int n){
	for(int i=0; i<n; i++){
		if(v[i].existencia_Act < v[i].cantidad_min){
			printf("\nCodigo: %d", v[i].codigo);
			printf("\nArticulo: %s", v[i].articulo);
			printf("\nexistencia Actual: %f", v[i].existencia_Act);
			printf("\ncantidad minima: %f", v[i].cantidad_min);
			printf("\nprecio: %f", v[i].precio);	
		}
		
	}
}

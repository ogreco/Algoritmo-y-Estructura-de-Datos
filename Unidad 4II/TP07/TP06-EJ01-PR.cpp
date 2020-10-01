/*--------------------------------------- 
  	Objetivo: Definir un registro estatico o estructura de datos estáticos, mostrando
	como se realiza la carga, lectura y visualización de un registro en pantalla.

-----------------------------------------
Enunciado:
			 Dada la siguiente configuraci�n, correspondiente a los productos de 
			 un negocio: c�digo (entero), descripci�n (Car�cter) y precio (Real).
		Se Pide: 
			 1- Defina el registro apropiado para los datos, 
			 2- Ingrese los datos de un producto  y 
			 3- Muestre en pantalla, lo Ingresado.
-----------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct registro
{
	int codigo;
	char descri[30];
	float precio;
};

main ()
{
	registro reg;	//Declara una variable (reg) de tipo de dato estructura (registro)
/*-------------- Los datos se registran en el registro -----------*/
	printf("Ingrese Los Datos Del Producto\n");
	printf("========================\n\n");
	printf("Codigo: "); 
	scanf("%d", &reg.codigo);	//Los datos son almacenado directamente en el miembro c�digo.
	printf("\nDescripcion: "); 
	_flushall();				//Limpia el buffers.
	gets(reg.descri);			//Los datos son almacenado directamente en el miembro descri.
	printf("\nPrecio: "); 
	scanf("%f", &reg.precio);	//Los datos son almacenado directamente en el miembro precio.
/*-------------- Muestra los datos ingresado en el registro -----------*/
	printf("\n\nLos Datos Ingresados Son\n"); 
	printf("========================\n\n");
	printf("\tCodigo: %d", reg.codigo);
	printf("\n\n\tDescripcion: ");
	puts(reg.descri);
	printf("\n\tPrecio: %.2f\n\n\n", reg.precio);
	system("PAUSE");
}


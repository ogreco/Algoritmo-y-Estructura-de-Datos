/*--------------------------------------- 
	Definir un registro jerarquia o Jerarquizados
-----------------------------------------
Definir un registro jerarquia o Jerarquizados, Transferir un registro a una función utilizando Parámetros por referencia.
La transferencia e registro a una función se utiliza de la misma forma en registros Estáticos.

Enunciado:
		Dada los siguientes datos correspondiente a  los art�culos deportivos de un 
		negocio: c�digo, descripci�n, precio y fecha de adquisici�n (compra) (que  a su 
		vez, fecha, es un registro que posee los miembros simples: d�a, mes y a�o).
	SE PIDE: 
		1-	Defina de manera apropiada el registro para los datos y requerimientos descriptos.
		2-	Permita la registraci�n de una compra (Ingreso al registro). 
		3-	Muestre los datos ingresados en pantalla (Muestra los datos que tiene el registro).
 
-----------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct registro
{
	int codigo;
	char descri[30];
	float precio;
	fecha fec;
};
//Prototipos
void agregarArticulo(struct registro &art);	//Funci�n con par�metro por referencia (una estructura).
void mostrarArticulo(struct registro &art);	//Funci�n con par�metro por referencia (una estructura).

main ()
{
	registro  reg;		//Define o declara la variable (reg) como un tipo de dato estructura de la estructura registro).
	agregarArticulo(reg);	//Llamada a la funci�n para agregar los datos al registro, transfiere como como par�metro la variable reg.
	mostrarArticulo(reg);	//Llamada a la funci�n para mostrar los datos almacenados (guardados) en la variable reg.
	printf("\n\n ���.. Fin del programa .............\n");
	system("PAUSE");
}

/* ---------------------------------------------------------
 Nombre			: mostrarArtuculo(...)
 Descripcion	: Permite mostrar los datos registrado en el registro.
 Tipo de Funci�n: Sin Tipo.
 Retorna		: -------
 Parametros		: Recibe un parametros 
 					1- La estructura usando parametro por referencia.  
------------------------------------------------------------*/
void mostrarArticulo(struct  registro &art)
{
	printf("\n\n LOS DATOS INGRESADOS SON\n");
	printf("=======================\n");
	printf("Codigo: %d", art.codigo);
	printf("\nDescripcion: ");
	puts(art.descri);
	printf("Precio: %f", art.precio);
	printf("\n\n Fecha de Vto: %d - %d - %d \n\n\n", art.fec.dia , art.fec.mes , art.fec.anio);
	system("PAUSE");
}

/* ---------------------------------------------------------
 Nombre			: agregarArticulo(...)
 Descripcion	: Permite almacenar (Guardar) los datos en el registro.
 Tipo de Funci�n: Sin Tipo.
 Retorna		: -------
 Parametros		: Recibe un parametros, 
 					1- La estructura usando parametro por referencia.  
------------------------------------------------------------*/
void agregarArticulo(struct  registro  &art)
{
	system("CLS");
	printf("Ingrese los datos del Articulo\n");
	printf("==============================\n\n");
	printf("Codigo: ");	
	scanf("%d", &art.codigo); 
	printf("Descripcion: ");
	_flushall();
	gets(art.descri); 
	printf("Precio: "); 
	scanf("%f",  &art.precio); 
	printf("\n\nFecha de Vto: \n");
	printf("\tDia: ");
	scanf("%d",  &art.fec.dia);
	printf("\tMes: ");
	scanf("%d", &art.fec.mes);
	printf("\tA�o: ");
	scanf("%d", &art.fec.anio);
	printf("\n\n Fin de la Carga..........................\n");
	system("PAUSE");
}


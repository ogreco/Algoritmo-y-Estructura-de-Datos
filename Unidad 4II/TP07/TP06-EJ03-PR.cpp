/*--------------------------------------- 
Arreglo de registro o Arreglos estáticos.	
-----------------------------------------
Definir un arreglo de registro o Arreglos estáticos. 
Ingreso de datos a un vector y mostrar los datos ingresados en el vector.

Enunciado:
		Un negocio dedicado a la venta de art�culos variados, los cuales poseen los datos 
		siguientes: c�digo, descripci�n y precio.
	SE PIDE: 
		1-	Defina la estructura del  registro apropiada a los datos descriptos.
		2-	Ingresar N Art�culos y almacene los mismos en un vector. Use una funci�n sin tipo.
		3-	Muestre los datos ingresados en el vector por pantalla. Use una funci�n sin tipo. 
-----------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------- Estructura o Registro L�gico.---------*/
struct registro
{
	int codigo;
	char descri[30];
	float precio;
};

/*---------- Prototipos a utilizar. ----------*/
void cargarDatosVector(registro A[100], int N);	
void mostrarDatosVector(registro A[100], int N);

/*---------- Bloque Principal. -----------*/
main()
{
       registro Array[100]; //Define el vector de tipo registro de 100 elementos como m�ximo.
       int N;
       printf("Cuantos Articulos Desea Ingresar: ");
       scanf("%d", &N);	//
       cargarDatosVector(Array, N);
       mostrarDatosVector(Array, N);
}

/* ---------------------------------------------------------
 Nombre			: cargarDatosVector(...)
 Descripcion	: Permite almacenar (Guardar) los datos en el arreglo.
 Tipo de Funci�n: Sin Tipo.
 Retorna		: -------
 Parametros		: Recibe dos parametros, 
 					1- El arreglo de tipo registro.  
					2- Cantidad de elementos a ingresar.
------------------------------------------------------------*/
void cargarDatosVector(registro A[100],int N)
{
     printf("\n\nIngreso de Articulos........\n");
     for(int i=0; i<N; i++)
     {
        printf("\n   Codigo: ");	
        scanf("%d", &A[i].codigo);	//Almacena el codigo, usa scanf(...).
         
        printf("Descripcion: ");
		_flushall();
        gets(A[i].descri);			//Almacena la descripcion, usa gets(...).
        
        printf("     Precio: ");	
        scanf("%f", &A[i].precio);	//Almacena el precio, usa scanf(...).
        printf("\n\n");
        _flushall();				//Limpia el buffers de entrada.
     }
     printf("\n\n    Fin de la carga   \n");
     system("PAUSE");
     system("CLS");
}

/* ---------------------------------------------------------
 Nombre			: mostrarDatosVector(...)
 Descripcion	: Muestra los datos que se ingresaron al vector.
 Tipo de Funci�n: Sin Tipo.
 Retorna		: --------
 Parametros		: Recibe dos parametros:
					1- El vector de tipo registro.
					2- Cantidad de elementos a ingresar.
------------------------------------------------------------*/
void mostrarDatosVector(registro A[100], int N)
{
     printf("\n\nListado de Articulos........\n");
     for(int i=0;  i<N;   i++)
    {
		/*  Muestra los 3 datos almacenado en la misma posicion del vector */
        printf("\t%d , \t%s, \t%.2f\n", A[i].codigo, A[i].descri, A[i].precio);
     }
     printf("\n\n  Fin del Listado  \n");
     system("PAUSE");
     system("CLS");
}


/*
En un centro médico se registra lo que pagan en consulta particulares N pacientes en un array de
registro que tiene la siguiente configuración de registro: código del paciente, apellido y nombre,
monto abonado, tipo de práctica (0: traumatología – 1: fonoaudiología – 2: cardiología)
a) Ingresar los datos de los N registros y a través de una función con tipo encuentre el
monto total recaudado por la clínica y muéstrelo en main.
b) Encuentre a través de funciones con tipo el porcentaje de pacientes que fueron atendidos
en traumatología y el porcentaje de pacientes atendidos en cardiología, muestre los
resultados en la función main().
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------- Estructura o Registro L�gico.---------*/
struct registro
{
	int codigo;
	char apellidoNombre[30];
	float precio;
    int tipoPractica;
};

/*---------- Prototipos a utilizar. ----------*/
float cargarDatosVector(registro A[100], int N, int &traumatologia, int &fonoaudiologia, int &cardiologia);
void mostrarDatosVector(registro A[100], int N);


/*---------- Bloque Principal. -----------*/
main()
{
       int traumatologia, fonoaudiologia, cardiologia= 0;
       float recau= 0.0;
       registro Array[100]; //Define el vector de tipo registro de 100 elementos como m�ximo.
       int N;

       printf("¿Cuantos Pacientes desea ingresar?: ");
       scanf("%d", &N);	//
       recau=  cargarDatosVector(Array, N, traumatologia, fonoaudiologia, cardiologia);
       
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
float cargarDatosVector(registro A[100],int N,int &traumatologia, int &fonoaudiologia, int &cardiologia)
{
     float recaudado=0.0; 
          
     printf("\n\nIngreso de Pacientes........\n");
     for(int i=0; i<N; i++)
     {
        printf("\n   Codigo del Paciente: ");	
        scanf("%d", &A[i].codigo);	//Almacena el codigo, usa scanf(...).
         
        printf("Nombre y Apellido: ");
		_flushall();
        gets(A[i].apellidoNombre);			//Almacena la descripcion, usa gets(...).
        
        printf("     Precio: ");	
        scanf("%f", &A[i].precio);	//Almacena el precio, usa scanf(...).

        printf("     Tipo de practica: ");	
        scanf("%d", &A[i].tipoPractica);	//Almacena el precio, usa scanf(...).

        printf("\n\n");
        _flushall();				//Limpia el buffers de entrada.


        recaudado= recaudado + A[i].precio; 

        ///0: traumatología – 1: fonoaudiología – 2: cardiología)

        if ( A[i].tipoPractica== 1 )
        {
            traumatologia = traumatologia + 1;
        }
        
        if ( A[i].tipoPractica== 2 )
        {
            fonoaudiologia = fonoaudiologia + 1;
        }

        if ( A[i].tipoPractica== 3)
        {
            cardiologia = cardiologia + 1;
        }

        
     }
     
     printf("\n\nEl total por Trauma: %.2f........\n", traumatologia );
     printf("\n\nEl total por Fono: %.2f........\n", fonoaudiologia);
	 printf("\n\nEl total por Cardio: %.2f........\n", cardiologia);
     
     
     printf("\n\n    Fin de la carga   \n");
     system("PAUSE");
     system("CLS");

     return recaudado; 

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
     printf("\n\nListado de Pacientes........\n");
     for(int i=0;  i<N;   i++)
    {
		/*  Muestra los 3 datos almacenado en la misma posicion del vector */
        printf("\t%d , \t%s, \t%.2f, \t%d\n", A[i].codigo, A[i].apellidoNombre, A[i].precio, A[i].tipoPractica);
     }
     printf("\n\n  Fin del Listado  \n");
     system("PAUSE");
     system("CLS");
}





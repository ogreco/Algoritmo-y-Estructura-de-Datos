/* 
Enunciado:
	Ingresar en un vector los nombres de las N asignaturas de la 
	carrera Ing. Sistema de Informaci?n, paralelamente ingresar en otro 
	vector la cantidad de alumnos inscriptos en cada asignatura.
SE PIDE:
	a.	En una funci?n Sin Tipo, realizar la carga de los vectores en forma 
		simult?nea, Asignatura y nro. de inscriptos. 
	b.	Haciendo uso de una funcion Con Tipo, determinar y mostrar en la 
		funcion main(), que asignatura tiene mayor numero de inscriptos.
	c.  Por medio de una funcion con tipo, encontrar la cantidad de inscriptos tiene una determinada asignatura. El nombre
	    de la asignatura se ingresa por teclado solicitado en la funcion de busqueda 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Nombre[30]; //Asigno nombre alternativo a tipo de dato existente
						
int MayorCantIns(int Inscritos[50],int Cant);		//Punto b
void cargarVector(int Cant, Nombre Asignaturas[50], int Inscritos[50] );	//Punto a
int cantidadInscriptos(int Cant, Nombre Asignaturas[50], int Inscritos[50]);

main()
{
	
	Nombre Asignaturas[50], XAsig;
	int Inscritos[50], Cant=0, posMayor;
	int Encontrar[50], Inscriptos=0, posAsig;
	printf("Cantidad de Asignaturas a Registrar: ");
	scanf("%d", &Cant);
	
	cargarVector(Cant, Asignaturas, Inscritos);
	
	posMayor = MayorCantIns(Inscritos,Cant);
	/*posAsig = (Inscritos,Cant);
	system("CLS");
	printf("\n\n\n");*/
	printf( "La asignatura %s con %d alumnos tiene el mayor numero de inscritos\n", 
					Asignaturas[posMayor], Inscritos[posMayor] );
	printf( "La cantidad de alumnos incriptos con una determinada asignatura es %d\n",
	                cantidadInscriptos(Cant, Asignaturas, Inscritos));			
	printf("\n\n");
	system("Pause");
}

/*-----------------------------------------------------*/
void cargarVector(int Cant, Nombre Asignaturas[50], int Inscritos[50])
{
	int i;
	
	//Carga los vectores Asignaturas e Inscritos
	for(i=0; i<Cant; i++)
	{	
		printf(" Ingrese la asignatura %d: ",i+1);	
		_flushall();
		gets(Asignaturas[i]); //Nombres de Asignatura		
		printf(" Nro de Inscritos: ");
		scanf("%d",&Inscritos[i]);  //Cantidad de inscrito en la asignatura.
		printf("\n------------------------------\n");
	}//Fin de la carga.............
}


/* Funcion Determina la posicion del mayor*/
int MayorCantIns(int Inscritos[50],int Cant)
{
	int i, posMayor, mayor;
	mayor = Inscritos[0];
	posMayor=0;
	for(i=0; i<Cant; i++)
	{
		if(Inscritos[i] > mayor)
		{
			mayor = Inscritos[i];
			posMayor = i;
		}
	}
	return posMayor;
}

int cantidadInscriptos(int Cant, Nombre Asignaturas[50], int Inscritos[50]){
	
	Nombre materia;
	printf("ingrese el nombre de la materia buscada: ");
	_flushall();
	gets(materia);
	
	for (int i=0; i<Cant; i++){
		if (strcmp(Asignaturas[i], materia) == 0) return Inscritos[i];
	}
	
	printf("la materia ingresada no existe.\n");
	return -1;
}



/* 
Enunciado:
	Ingresar en un vector los nombres de las N asignaturas de la 
	carrera Ing. Sistema de Informaci�n, para-lelamente ingresar en otro 
	vector la cantidad de alumnos inscriptos en cada asignatura.
SE PIDE:
	a.	En una funci�n Sin Tipo, realizar la carga de los vectores en forma 
		simult�nea, Asignatura y nro. de inscriptos. 
	b.	Haciendo uso de una funci�n Con Tipo, determinar y mostrar en la 
		funci�n main(), que asignatura tiene mayor n�mero de inscriptos. 

*/


#include <stdio.h>
#include <stdlib.h>

typedef char Nombre[30]; //Asigno nombre alternativo a tipo de dato existente
						
int MayorCantIns(int Inscritos[50],int Cant);		//Punto b
void cargarVector(int Cant, Nombre Asignaturas[50], int Inscritos[50] );	//Punto a

main()
{
	
	Nombre Asignaturas[50], XAsig;
	int Inscritos[50], Cant=0, posMayor;
		
	printf("Cantidad de Asignaturas a Registrar: ");
	scanf("%d", &Cant);
	
	cargarVector(Cant, Asignaturas,Inscritos);
	
	posMayor = MayorCantIns(Inscritos,Cant);
	
	system("CLS");
	printf("\n\n\n");
	printf( "La asignatura %s con %d alumnos tiene el mayor numero de inscritos\n", 
					Asignaturas[posMayor], Inscritos[posMayor] );
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
		_flushall();
		printf(" Ingrese la asignatura %d: ",i+1);
		gets(Asignaturas[i]); //Nombres de Asignatura
		_flushall();
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
		if(mayor<Inscritos[i])
		{
			mayor = Inscritos[i];
			posMayor = i;
		}
	}
	return posMayor;
}//Fin 
	


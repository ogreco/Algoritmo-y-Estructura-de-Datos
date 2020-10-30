/*
Un ejemplo de apertura es el siguiente:
arch = fopen (“datos.dat”,”r+b”);
donde el segundo parámetro es el modo de apertura, que pueden ser:
• rb: Sólo lectura. El archivo debe existir, caso contrario retorna NULL
• wb: Solo escritura. Si no existe el archivo lo crea, caso contrario borra su contenido y lo abre vacío.
• ab: Sólo escritura. Si no existe el archivo lo crea, caso contrario no lo destruye. Los registros que se
graban lo hacen al final.
• r+b: Lectura y escritura. El archivo debe existir previamente.
• w+b: Lectura y escritura. Si no existe el archivo lo crea, caso contrario lo borra y lo abre vacío.
• a+b: Lectura y escritura. Si no existe el archivo lo crea, caso contrario no lo borra. Añade al final.

*/


#include <stdio.h>
#include <stdlib.h>

int ingresoDeValoresEnteros(FILE *archMultiplo, int &cantidadIngresada);
void listadoDeArchivo(FILE *archMultiplo);
int buscarUnValor(FILE *archMultiplo, int numeroQueBusca);


main()
{
	FILE *archMultiplo;
	
	archMultiplo = fopen("Multiplo.dat", "w+b");
	if(archMultiplo == NULL)
	{
		system("CLS");
		printf("\n\n Se produjo un ERROR al intentar abrir el archivo\n");
		printf("comuniquese con el administrador del Sistema. Gracias");
		printf("\n\n\t");
		system("PAUSE");
		exit(1);
	}
	int cantidadNumerosNoGuardados=0, cantidadIngresada=0;
	
	cantidadNumerosNoGuardados = ingresoDeValoresEnteros(archMultiplo, cantidadIngresada);
	
	system("COLOR 4F"); //Establece color de fondo rojo y letras blancas.
	printf("\n\t\t****************************************************");
	printf("\n\t\t** DE LOS %2d VALORES INGRESADOS NO SE **",cantidadIngresada);
	printf("\n\t\t** GUARDARON %2d POR NO SER MULTIPLOS DE 3 **", cantidadNumerosNoGuardados);
	printf("\n\t\t****************************************************\n");
	
	system("PAUSE");
	system("CLS");
	
	//////////Listado del Archivo//////////////
	listadoDeArchivo(archMultiplo);
	system("CLS");
	
	//////////Busqueda de un valor//////////////
	printf("\n\n\n\t\t");
	printf("Ingrese el Valor que desea Buscar: ");
	int valorQueBusca=0;
	scanf("%d", &valorQueBusca);
	int cantidadDeVeces=0;
	cantidadDeVeces = buscarUnValor(archMultiplo, valorQueBusca);
	
	printf("\n\n\n");
	printf("\n\t\t\t************************************************************");
	printf("\n\t\t\t** El valor buscado (%3d) Se ingreso al archivo %3d veces **",valorQueBusca,
	cantidadDeVeces);
	printf("\n\t\t\t************************************************************");
	printf("\n\n\n");
	system("PAUSE");
	fclose(archMultiplo); //cierra el archivo.
}



/*Nombre : ingresoDeValoresEnteros(...)
Descripci�n : De los valores ingresados Guarda solo aquellos que sean m�ltiplos de 3 y cuenta cuantos valores NO se guardaron.
Tipo Funci�n : con Tipo.
Retorna : variable de tipo entero indicando cuantos datos no se guardaron.
Par�metros : Recibe dos
1- El puntero del registro.
2- Una variable por referencia que indica cuantos datos se ingresaron.
------------------------------------------------------------*/
int ingresoDeValoresEnteros(FILE *archMultiplo, int &cantidadIngresada)
{

	int valorEntero, cantidadNoGuardada=0;
	char opcSalida = 'N';
	system("COLOR 30"); // color de fondo Aguamarina y letra negra.
	
	do{
		printf("\nlngrese un Nro Entero: ");
		scanf("%d", &valorEntero);
		cantidadIngresada++;
		if ( valorEntero%3 == 0) //Determina si es m�ltiplo de 3
		{
			fwrite(&valorEntero, sizeof(valorEntero), 1, archMultiplo); //Guarda el valor ingresado
		}else{
			cantidadNoGuardada++; //Cuenta los no guardados
		}
		
		printf("n\t Continua: (S)i - (N)o, Ingrese Opcion: "); //Pregunta si continua
		_flushall();
		scanf("%c", &opcSalida); //recibe la repuesta por teclado.
	}while ((opcSalida == 'S') || (opcSalida == 's')); //Repite mientras �opcSalida� sea S o s?
	
	printf("\n\n\n");
	printf("\n\t\t****************************************************");
	printf("\n\t\t** F I N A L D E L A C A R G A **");
	printf("\n\t\t****************************************************");
	printf("\n\n\n");
	system("PAUSE");
	system("CLS");
	return cantidadNoGuardada;
}


/* ---------------------------------------------------------
Nombre : listadoDeArchivo(...)
Descripci�n : Lista los datos del archivo que recibe por par�metro
Tipo Funci�n : Sin Tipo.
Retorna : Ningun Valor.
Par�metros : Recibe
1- El puntero al registro.
------------------------------------------------------------*/
void listadoDeArchivo(FILE *archMultiplo)
{
	int numeroGuardado, cantidadDeColumna;
	cantidadDeColumna = 1;
	printf("\n\n\n");
	printf("\n\t\t********************************************************");
	printf("\n\t\t** L I S T A D O D E L A R C H I V O **");
	printf("\n\t\t********************************************************");
	printf("\n\n\n");
	
	rewind(archMultiplo); //Ubica el puntero en el primer valor que tiene el archivo.
	fread(&numeroGuardado, sizeof(int), 1, archMultiplo); //Lee un valor.
	printf("\t\t");
	
	while ( !feof(archMultiplo) ) //Mientras no se fin de archivo hacer
	{
		printf("%03d -- ", numeroGuardado);
		if(cantidadDeColumna==3)
		{
			printf("\n\t\t");
			cantidadDeColumna=1;
		}else
			cantidadDeColumna++;
		fread(&numeroGuardado, sizeof(int), 1 , archMultiplo);
	}
	printf("\n\n\n");
	printf("\n\t\t****************************************************");
	printf("\n\t\t** F I N A L D E L L I S T A D O **");
	printf("\n\t\t****************************************************");
	printf("\n\n");
	system("PAUSE");
}


/* ---------------------------------------------------------
Nombre : buscarUnValor(...)
Descripci�n : Busca en el archivo el numero que recibe por parametro.
Tipo Funci�n : Con Tipo.
Retorna : Cantidad de veces que se encontro el valor.
Par�metros : Recibe
1- El puntero del registro.
2- El numero que debe buscar.
------------------------------------------------------------*/
int buscarUnValor(FILE *archMultiplo, int numeroQueBusca)
{
	int cantidadDeVeces = 0, numeroGuardado;
	
	rewind(archMultiplo); //Ubica el puntero en el primer valor que tiene el archivo.
	
	fread(&numeroGuardado, sizeof(int), 1, archMultiplo); //Lee el primer valor.
	
	while ( !feof(archMultiplo) ) //Mientras no se fin de archivo hacer
	{
		if(numeroGuardado == numeroQueBusca)
		cantidadDeVeces++;
	
		fread(&numeroGuardado, sizeof(int), 1 , archMultiplo);
	}
	return cantidadDeVeces;
}



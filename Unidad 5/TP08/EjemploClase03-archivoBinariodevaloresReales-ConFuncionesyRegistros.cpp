/*
En un negocio se registran las ventas que tuvieron sus empleados de los artículos que se comercializan en un archivo Binario. La configuración lógica del registro es:
-código Artículo,
-importe de Venta.
a) Definir de manera apropiada el registro y realizar la carga de las diferentes ventas por medio de una función Sin Tipo.
b) En una función Con Tipo, recorrer el archivo determinando la cantidad de Artículos cuya venta supero los
$ 1000 y por otro lado, las ventas menores a esta cifra, mostrar ambos resultado en main.
c) En una función Sin Tipo, Realizar el listado del archivo.

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
/*------ Estructura L�gica del Registro Venta ------*/
struct venta{
int cod;
float imp;
};

/*------ Prototipos de Funciones ------*/
void cargarArchivo(FILE *arch1);
int contarMayorMenorQue(FILE *arch1, int &mayorQue);
void listarArchivo(FILE *arch1);
/*----- Bloque Principal -----*/

main (void)
{
	FILE *arch; //Define "arch" de tipo puntero a un archivo.
	int menorQue=0, mayorQue=0; //Define los contador de mayores y menores que 1000.
	/*----- Abre y Determina si se cre� bien el archivo ----*/
	arch = fopen("articulo.dat","w+b"); //Crea el archivo de Escritura.
	if(arch==NULL){
		printf("\n\n Ocurrido un error al intentar abrir el archivo.....\n");
		system("PAUSE");
		exit(1);
	}


	/*----- Realiza la carga del archivo -----*/
	cargarArchivo(arch); //Llamada.
	/*----- Cuenta la cantidad de ventas mayores y menores a 1000 -----*/
	menorQue = contarMayorMenorQue(arch, mayorQue); //Llamada.
	/*----- Muestra los valores obtenidos -----*/
	printf("Hay %d productos con importe menor a $1000\n", menorQue);
	printf("Hay %d productos con importe mayor a $1000\n", mayorQue);
	
	system("PAUSE");
	system("CLS");
	/*----- Realiza el listado del archivo -----*/
	listarArchivo(arch); //Llamada.
	fclose(arch); //Cierra el archivo.
} //Fin de funci�n main.


/*------------------------------------------------------*/
void cargarArchivo(FILE *arch1){
	venta regVenta; //Define "regVenta" de tipo Venta(estructura l�gica).
	char seguir = 'n';//Define "Seguir" para determinar el final de la carga.
	int nroReg = 0; //Define "nroReg" para saber cantidad de registro/s ingresados.
	do{
		system("CLS");
		printf("\n\n***********************\n");
		printf("Registro Nro: %d", ++nroReg);
		printf("\n\n***********************\n\n");
		printf("Codigo : "); scanf("%d", &regVenta.cod);
		printf("Importe: "); scanf("%f", &regVenta.imp);
		fwrite(&regVenta, sizeof(venta), 1, arch1); //Graba el registro.
		_flushall();
		printf("\nIngresar mas datos (s/n):"); scanf("%c", &seguir);
	} while( seguir == 'S' || seguir == 's' );
	printf("\n\n\n***********************************************************\n");
	printf("\n Fin de la Carga............................");
	printf("\n\n***********************************************************\n\t");
	system("PAUSE");
	system("CLS");
}


/* ---------------------------------------------------------
Nombre : contarMayorMenor(...)
Descripci�n : Cuenta las ventas mayores e iguales a 1000 y las menores a 1000.
Tipo Funci�n: Con Tipo.
Retorna : El cantidad de valores que fueron menores a 1000 y por referencia mayor de 1000
Par�metros : Recibe dos (1)- El puntero del registro. (2)- Variable por referencia. Ventas mayores
a 1000.
------------------------------------------------------------*/


int contarMayorMenorQue(FILE *arch1, int &mayorQue)
{
	venta regVenta;
	rewind(arch1);
	fread(&regVenta, sizeof(venta), 1, arch1); //Leer el primer registro.
	int menorQue = 0;
	mayorQue = 0;
	while( !feof(arch1)) //Termina despu�s de leer el �ltimo registro.
	{
		if (regVenta.imp < 1000)
		menorQue = menorQue + 1;
		else
		mayorQue = mayorQue + 1;
		fread(&regVenta, sizeof(venta), 1, arch1); //Continua leyendo.
	}
	return menorQue;
}

/* ---------------------------------------------------------
Nombre : listarArchivo(...)
Descripci�n : Lista todas las ventas Realizadas (registradas).
Tipo Funci�n : Sin Tipo.
Retorna : Ning�n Valor.
Par�metros : Recibe uno
 1- El puntero del registro.
------------------------------------------------------------*/
void listarArchivo(FILE*arch1){
venta regVenta; //crea la variable "regVenta" de tipo venta.
rewind(arch1); //Ubica el puntero en el primer registro del archivo.
fread(&regVenta, sizeof(venta), 1, arch1); //Lee un registro.
printf("\n\n*************************************\n");
printf("\n Listado del Archivo ");
printf("\n*************************************\n");
printf("\t Codigo \t Monto de Venta \n" );
printf("\n *************************************\n");
while(!feof(arch1)) //Termina despu�s de leer el �ltimo registro.
{
	printf("\t %d \t %.2f \n", regVenta.cod, regVenta.imp);
	fread(&regVenta, sizeof(venta), 1, arch1); //Continua leyendo.
}
printf("\n****************************************\n\t");
system("PAUSE");
system("CLS");
}






/*
? Una empresa registra los datos de sus vendedores en un registro y uno de su miembro es un arreglo (vector) que representa el monto de venta realizado por el vendedor de lunes a viernes. La estructura de dicho registro es la siguiente:
? Apellido y nombre
? Numero de documento
? Fecha Ingreso (o de contrato)
? Venta Semanal //Es un vector de 5 posiciones, posición 0 es el día Lunes, posición 1 día martes…………. y posición 4 es el día viernes
: Defina el registro de vectores de manera apropiada según la descripción de los datos y por medio de un menú de opciones realizar las
siguientes operaciones. 
a) Registrar como mínimo 5 empleados, sin registrar ventas.

b) Registrar el total de venta al final del día. La registración se hará por medio de una función que reciba 
el apellido y nombre, 
el día de la venta (Lunes, martes,…, viernes), 
y el monto a registrar. 
(Si hubo un error porque apellido y nombre no figura mostrar un mensaje indicando el error)


c) Listar por pantalla las ventas de la semana y el monto total vendido por cada uno de los empleados. 
Observe el modelo de listado que debe realizar. (Para este tipo de listado, deberá investigar la máscara o
 formato que se aplica a los datos de salida).
 
Documento Apellido y nombre                 Lunes   Martes Miércoles Jueves Viernes Total
xx.xxx.xxx xxxxxxxxx xxxxxxxxxx xxxxxxxxxx 100.00   200.00 xxxx.xx xxxx.xx xxxx.xx xxxxx.xx
xx.xxx.xxx xxxxxxxxx xxxxxxxxxx xxxxxxxxxx xxxx.xx xxxx.xx xxxx.xx xxxx.xx xxxx.xx xxxxx.xx

d) Modificación de los Datos ventas, se realizara por medio de una función, que recibirá entre otros datos necesarios, el Nro. de documento del empleado, día a modificar (lunes, martes, etc.) y el monto a cambiar.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha{
	 int dia,mes,anio;
};
 
struct venta{
int lunes,martes,miercoles,jueves,viernes;
 };
 
struct vendedores{
 	char nombres[35];
 	int dni;
 	fecha fecha_ing;
 	float venta_sem[5];
};
 
void registrarMonto(vendedores v[], int n, char nombre[35], int dia, float monto);
void listadoVenta(vendedores v[], int n);
void modificarMonto(vendedores v[], int n, int dni, int dia, float monto);
 
main(){
	vendedores vend[50];
    int i,n;
	printf("\nIngrese la cantidad de vendedores: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
	 printf("\nIngrese los datos del vendedores: ");
	 
	 printf("\nApellido y Nombre de los vendedores: ");
	 _flushall();
	 gets(vend[i].nombres);
	 printf("\nNumero de documento: ");
	 scanf("%d",&vend[i].dni);
     printf("\nFecha de Ingreso: ");
     printf("\nDIA: ");
     scanf("%d",&vend[i].fecha_ing.dia);
     printf("\nMES: ");
     scanf("%d",&vend[i].fecha_ing.mes);
	 printf("\nAÑO: ");
     scanf("%d",&vend[i].fecha_ing.anio);
	}
	
	char vendedor[35];
	int dia;
	float monto;
	int opc;
	do{
		 printf("\ningrese el nombre del vendedor");
		_flushall();
		gets(vendedor);
		do{
			printf("\ningrese el dia de la venta (0:L, 1:M, 2:Mie, 3:J, 4:V)");
			scanf("%d", &dia);
		}while(dia < 0 || dia > 4);
		printf("\ningrese el monto de la venta: ");
		scanf("%f", &monto);	
		registrarMonto(vend, n, vendedor, dia, monto);		
		printf("ingrese 1 para otro vendedor o 0 para salir");
		scanf("%d", &opc);
	}while(opc != 0);
	
	
	listadoVenta(vend, n);
	printf("desea modificar alguna venta? 0/1");
	scanf("%d", &opc);
	int dni;
	while(opc != 0){
		printf("\ningrese el dni del vendedor");
		scanf("%d", &dni);
		do{
			printf("\ningrese el dia de la venta (0:L, 1:M, 2:Mie, 3:J, 4:V)");
			scanf("%d", &dia);
		}while(dia < 0 || dia > 4);
		printf("\ningrese el monto de la venta: ");
		scanf("%f", &monto);	
		modificarMonto(vend, n, dni, dia, monto);		
		printf("ingrese 1 para otro vendedor o 0 para salir");
		scanf("%d", &opc);
	}
	
	listadoVenta(vend, n);
	/*
	 printf("\nLos Datos de los Vendedores son: ");
	 for(i=0;i<n;i++)
	 {
	 	printf("\nDatos del vendedor: %d\n",i+1);
	    printf("\nApellido y Nombres: %s",&vend[i].nombres);
	    printf("\nNumero de documento: %d",&vend[i].dni);
	    printf("\nVentas Semanales:\n");
	    printf("\nLUNES: %d",&vend[i].venta_sem.lunes);
        printf("\nMARTES: %d",&vend[i].venta_sem.martes);
        printf("\nMIERCOLES: %d",&vend[i].venta_sem.miercoles);
        printf("\nJUEVES: %d",&vend[i].venta_sem.jueves);
        printf("\nVIERNES: %d",&vend[i].venta_sem.viernes);
	    printf("\nFecha de Ingreso:\n");
	    printf("\nDIA: %d",&vend[i].fecha_ing.dia);
        printf("\nMES: %d",&vend[i].fecha_ing.mes);
        printf("\nANIO: %d",&vend[i].fecha_ing.anio);
	 }
      */
       printf("\n\n");
       system("PAUSE");	
}

void registrarMonto(vendedores v[], int n, char nombre[], int dia, float monto){
	bool b = false;
	
	for(int i=0; i<n; i++){
		if (strcmp(v[i].nombres, nombre) == 0){
			v[i].venta_sem[dia] = monto;
			b = true;
		}
	}
	
	if (!b) printf("error no existe ese vendedor");
}

void listadoVenta(vendedores v[], int n){
	printf("Documento\tApellido y nombre\tLunes\tMartes\tMiércoles\tJueves\tViernes\tTotal\n");
	for(int i=0; i<n; i++){
		float total = 0;
		for(int j=0; j<5; j++) total += v[i].venta_sem[j];
		
		printf("%d\t%s\t%f\t%f\t%f\t%f\t%f\t%f\n", 
				v[i].dni,
				v[i].nombres,
				v[i].venta_sem[0],
				v[i].venta_sem[1],
				v[i].venta_sem[2],
				v[i].venta_sem[3],
				v[i].venta_sem[4],
				total);	
	}
}

void modificarMonto(vendedores v[], int n, int dni, int dia, float monto){
	bool b = false;
	
	for(int i=0; i<n; i++){
		if (v[i].dni == dni){
			v[i].venta_sem[dia] = monto;
			b = true;
		}
	}
	
	if (!b) printf("error no existe ese vendedor");
}

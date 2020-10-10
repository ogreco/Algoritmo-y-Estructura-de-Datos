/*Una concesionaria de autos registra el día sábado las ventas realizadas en la semana. El registro tiene la siguiente estructura jerarquizada:
struct fecha{
int dia;
int mes;
int anio;
};
struct datosCliente{
char ApeNom[40]; //apellido y nombre del cliente
char dire[60]; //domicilio particular del cliente
float monVehi; //Monto del vehículo.
fecha fecVenta; //Fecha de venta del vehículo.
};
:
a) Ingresar las N ventas realizadas en la semana.
b) A medida que se registran las ventas, por medio de una función, determinar en qué fecha se vendió menos.
c) Haciendo uso de una función a medida que se ingresa los datos de un cliente mostrar en pantalla los datos ingresados*/


#include <stdio.h>
#include <stdlib.h>

struct fecha{
	int dia;
	int mes;
	int anio;
};

struct datosCliente{
	char ApeNom[40]; //apellido y nombre del cliente
	char dire[60]; //domicilio particular del cliente
	float monVehi; //Monto del vehículo.
	fecha fecVenta; //Fecha de venta del vehículo.
};

void mostrarCliente(datosCliente c);
void calculoMenor(fecha &f, float &m, float mv, fecha fv);

main(){
	datosCliente dc;
	int n;
 	printf("ingrese la cantidad de clientes: ");
 	scanf("%d", &n);
 	float menorVenta = 0;
 	fecha fechaMenorVenta;
 	
 	for(int i=0; i<n; i++){
 		system("cls"); 		
 		printf("Ingrese el apellido y nombre de este cliente: ");
 		_flushall();
 		gets(dc.ApeNom);
 		printf("Ingrese la direccion de este cliente: "); 		
 		gets(dc.dire);
 		printf("Ingrese el monto del vehiculo de este cliente: ");
 		scanf("%f", &dc.monVehi);
 		printf("Ingrese la fecha de venta: ");
 		scanf("%d/%d/%d", &dc.fecVenta.dia, &dc.fecVenta.mes, &dc.fecVenta.anio);
 		if (i == 0) menorVenta = dc.monVehi;
 		
 		calculoMenor(fechaMenorVenta, menorVenta, dc.monVehi, dc.fecVenta);
 		mostrarCliente(dc);
 		
	}
	printf("la fecha en que menos se vedio es %d/%d/%d", fechaMenorVenta.dia,  fechaMenorVenta.mes, fechaMenorVenta.anio);
	

}

void mostrarCliente(datosCliente c){
	printf("\nApellido y Nombres %s\n", c.ApeNom);
	printf("Direccion: ");puts(c.dire);
	printf("Monto vehiculo %f\n", c.monVehi);
	printf("Fecha de venta: %d/%d/%d\n", c.fecVenta.dia, c.fecVenta.mes, c.fecVenta.anio);
	system("pause");
}

void calculoMenor(fecha &f, float &m, float mv, fecha fv){
	if (mv < m){
 		m = mv;	
 		f = fv;
	} 
}

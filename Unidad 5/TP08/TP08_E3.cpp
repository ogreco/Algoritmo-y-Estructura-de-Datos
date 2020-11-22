/*En un archivo se tienen registradas las ventas que realiza un comercio. Cada registro contiene los
siguientes datos:
- Numero de vendedor (Son tres los vendedores 1, 2, 3)
- Apellido y Nombre del vendedor
- Numero Factura.
- Importe facturado por esa venta.
- Forma de venta (1: Contado, 2: Crédito)
- Fecha de Venta (DD MM AAAA) (Año se registra 4 dígitos) campo jerarquizado.



Desarrolle un programa que permita realizar, al encargado del negocio, por medio de un menú las
siguientes operaciones que deben ser realizadas en función diferente:

a.Carga de los datos al archivo, tener en cuenta que cada vez
que se habrá el archivo o se realice una nueva carga NO debe perder lo que ya se tiene registrado.
Y verificar que se ingresen valores válidos para los miembros número de vendedor y forma
de venta.

b.Cantidad total de venta registrada en un mes determinado. (El mes debe ser solicitado por teclado).

c. Mostrar cuantas ventas se realizaron de Contado y cuantas ventas se realizaron a Crédito, de un
determinado mes. (El mes se solicita por teclado).

d.Importe total realizado en el mes por un vendedor. (El apellido y nombre del vendedor, deberá ser
solicitado por teclado).

e. Listar todos los datos que contiene el archivo.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[45];
struct fecha{
	int dia, mes, anio;
};

struct venta{
	int nro_vendedor;
	cadena nombre_vendedor;
	int nro_factura;
	float importe;
	int forma_venta;
	fecha f_venta;
};

char dibujarMenu();
void carga(FILE *arch);
void listarVentasxMes(FILE *arch, int mes);
void cantidadVentasxMes(FILE *arch, int mes, int &contado, int &credito);
float TotalVentasxVendMes(FILE *arch, int mes, cadena nombre);
void listarVentas(FILE *arch);
main(){
	FILE *arch = fopen("misventas.dat", "a+b");
	int mes;
	int contado = 0, credito = 0;
	cadena nombre;
	if (arch == NULL){
		printf("el archivo no se pudo crear! fin del programa");
		return 0;
	}
	
	char opc;
	do{
		opc = dibujarMenu();
		switch(opc){
			case 'a':carga(arch);				 	 
					 break;
					 
			case 'b':printf("ingrese un mes para visualizar sus ventas: ");					 
					 scanf("%d", &mes);
					 listarVentasxMes(arch, mes);					 
					 break;
					 
			case 'c':printf("ingrese un mes para visualizar sus ventas: ");					 
					 scanf("%d", &mes);			
					 contado = 0, credito = 0;		 
					 cantidadVentasxMes(arch, mes, contado, credito);
					 printf("el total de ventas de contado es de %d y en credito es %d\n", contado, credito);					 
					 break;
					 
			case 'd':printf("ingrese un mes para visualizar sus ventas: ");					 
					 scanf("%d", &mes);
					 printf("ingrese un nombre para visualizar sus ventas: ");					 
					 _flushall();
					 gets(nombre);					 
					 printf("el total de ventas de %s es de %f\n", nombre, TotalVentasxVendMes(arch, mes, nombre));					 
					 break;
			case 'e':listarVentas(arch);					 
					 break;
		}
		system("pause");
	}while(opc != 'f' && opc != 'F');
	
	
	fclose(arch);
}

char dibujarMenu(){
	system("cls");
	printf("*********************VENTAS*************************\n");
	printf("\t a) Carga de Ventas\n");
	printf("\t b) Ventas en un mes\n");
	printf("\t c) Cantidad de Ventas por tipo y por mes\n");
	printf("\t d) Ventas por vendedor y por mes\n");
	printf("\t e) Listado total de Ventas\n");
	printf("\t f) Salir\n");
	printf("****************************************************\n");
	printf("ingrese la opcion deseada: \n");
	char opc;
	_flushall();
	scanf("%c", &opc);
	return opc;
}

void carga(FILE *arch){
	venta v;
	do{
		printf("ingrese numero de vendedor: ");
		scanf("%d", &v.nro_vendedor);	
	}while(v.nro_vendedor <1 || v.nro_vendedor>3);
	printf("ingrese el nombre del vendedor: ");
	_flushall();
	gets(v.nombre_vendedor);
	printf("ingrese el numero de factura de la venta: ");
	scanf("%d", &v.nro_factura);
	printf("ingrese el importe de la venta: ");
	scanf("%f", &v.importe);
	do{
		printf("ingrese la forma de venta: ");
		scanf("%d", &v.forma_venta);
	}while(v.forma_venta!=1 && v.forma_venta!=2);
	
	printf("ingrese la fecha de la venta: ");
	scanf("%d/%d/%d", &v.f_venta.dia, &v.f_venta.mes, &v.f_venta.anio);
	
	fwrite(&v, sizeof(v), 1, arch);
}

void listarVentasxMes(FILE *arch, int mes){
	venta v;
	rewind(arch);
	fread(&v, sizeof(v), 1, arch);
	while(!feof(arch)){
		if (v.f_venta.mes == mes){
			printf("Numero de Vendedor: %d\n", v.nro_vendedor);
			printf("Nombre de Vendedor: %s\n", v.nombre_vendedor);
			printf("Numero de factura: %d\n", v.nro_factura);
			printf("Importe de la Venta: %f\n", v.importe);
			printf("Forma de Venta: %d\n", v.forma_venta);
			printf("Fecha de Venta: %d/%d/%d\n", v.f_venta.dia, v.f_venta.mes, v.f_venta.anio);				
		}
		fread(&v, sizeof(v), 1, arch);
	}
	
}

void cantidadVentasxMes(FILE *arch, int mes, int &contado, int &credito){
	venta v;
	rewind(arch);
	fread(&v, sizeof(v), 1, arch);
	while(!feof(arch)){
		if (v.f_venta.mes == mes){
			if (v.forma_venta == 1) contado++;
			else credito++;
		}
		fread(&v, sizeof(v), 1, arch);
	}
}

float TotalVentasxVendMes(FILE *arch, int mes, cadena nombre){
	float total = 0;
	venta v;
	rewind(arch);
	fread(&v, sizeof(v), 1, arch);
	while(!feof(arch)){
		if (v.f_venta.mes == mes && strcmp(v.nombre_vendedor, nombre) == 0){
			total += v.importe;
		}
		fread(&v, sizeof(v), 1, arch);
	}
	
	return total;
}

void listarVentas(FILE *arch){	
	venta v;
	rewind(arch);
	fread(&v, sizeof(v), 1, arch);
	while(!feof(arch)){
		printf("Numero de Vendedor: %d\n", v.nro_vendedor);
		printf("Nombre de Vendedor: %s\n", v.nombre_vendedor);
		printf("Numero de factura: %d\n", v.nro_factura);
		printf("Importe de la Venta: %f\n", v.importe);
		printf("Forma de Venta: %d\n", v.forma_venta);
		printf("Fecha de Venta: %d/%d/%d\n", v.f_venta.dia, v.f_venta.mes, v.f_venta.anio);	
		printf("\n");
		fread(&v, sizeof(v), 1, arch);
	}	
}


/* En un negocio que se dedica a la venta de insumos eléctricos tiene la información de sus clientes en la siguiente
estructura.
struct datosCliente{
int codCli; //código del cliente
char ApeNom[40]; //apellido y nombre
char dire[60]; //domicilio particular
float monCred; //Monto máximo del crédito que puede realizar en cada compra.
};
:
 Ingresar el dato N clientes.
 A medida que se van ingresando los clientes, usando una función mostrar los datos registrados.
 Al finalizar la carga de los N clientes, mostrar cuantos clientes tienen un monto de crédito superior a $ 30.000.*/
 
 #include <stdio.h>
 #include <stdlib.h>
 
 struct datosCliente{
	int codCli; //código del cliente
	char ApeNom[40]; //apellido y nombre
	char dire[60]; //domicilio particular
	float monCred; //Monto máximo del crédito que puede realizar en cada compra.
};

void mostrarCliente(datosCliente c);
 
main(){
 	datosCliente dc;
 	int n, cont=0;
 	printf("ingrese la cantidad de clientes: ");
 	scanf("%d", &n);
 	
 	for(int i=0; i<n; i++){
 		system("cls");
 		printf("Ingrese el codigo de este cliente: ");
 		scanf("%d", &dc.codCli);
 		printf("Ingrese el apellido y nombre de este cliente: ");
 		_flushall();
 		gets(dc.ApeNom);
 		printf("Ingrese la direccion de este cliente: "); 		
 		gets(dc.dire);
 		printf("Ingrese el credito de este cliente: ");
 		scanf("%f", &dc.monCred);
 		if (dc.monCred > 30000) cont++;
 		mostrarCliente(dc);
	}
	
	printf("\n\n la cantidad de clientes con mas de 30000 en credito es: %d", cont);
 	
 	
}
 
void mostrarCliente(datosCliente c){
	printf("Codigo: %d\nApellido y Nombres %s\n", c.codCli, c.ApeNom);
	printf("Direccion: ");puts(c.dire);
	printf("Credito Maximo: %f\n", c.monCred);
	system("pause");
}

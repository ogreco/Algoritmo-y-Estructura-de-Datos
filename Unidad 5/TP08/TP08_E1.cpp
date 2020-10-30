/*Una empresa dedicada a las ventas de productos por mayor registra en un archivo binario solo los
totales de ventas que se van realizando durante el día. 
Las cargas de los datos se realizan en cualquier momento, 
por lo que el archivo no debe perder la información con una nueva carga.

El dueño de la empresa solicita, al centro de cómputos, le confeccione un sistema qué por medio
de un menú se pueda realizar lo siguiente:
? Permitir registrar en cualquier momento los montos totales de venta.
? Saber cuál es la mayor venta guardada y la cantidad de veces que se registró el mismo
monto.

-------------------------------------------

? Visualizar los datos en pantallas, donde cada fila deberá tener 10 datos separados por un
guion y 

visualizar 6 dígitos en cada valor en caso de que la cantidad sea menor a 6 dígitos
rellenar con ceros a la izquierda hasta completar los 6 dígitos.

12-12-10-11-55-11-44-111-44-55
11-11-11-22

? Saber cuál es el monto total de las ventas realizadas en el momento de la consulta.
? Permitir al final del día borrar el archivo.
NOTA:
Utilizar para todas las opciones del menú funciones.
El archivo debe ser abierto al inicio del programa y cerrarlo al final del programa.
Cada función deberá recibir como uno sus parámetros el archivo.*/


#include <stdio.h>
#include <stdlib.h>

void registrarVenta(FILE *f, float montoVenta);
float mayorVenta(FILE *f);
int cantidaddelMayor(FILE *f, float mayor);
void visualiar(FILE *f);
float total(FILE *f);

main(){
	int opc;
	FILE *ventas = fopen("ventas.dat", "a+b");
	float venta;
	do{
		system("cls");
		printf("\ningrese 1 para cargar venta: ");
		printf("\ningrese 2 mayor venta guardada: ");
		printf("\ningrese 3 veces que se registro la mayor venta:");
		printf("\ningrese 4 visualizar datos:");
		printf("\ningrese 5 monto total de las ventas:");
		printf("\ningrese 6 eliminar archivo: ");
		printf("\ningrese 0 para salir: \n");		
		scanf("%d", &opc);
		switch(opc){
			case 1: printf("\ningrese el monto de la venta: ");
					scanf("%f", &venta);
					registrarVenta(ventas, venta);
					break;
			case 2: printf("\nla mayor venta fue de: %f\n", mayorVenta(ventas));
					system("pause");
					break;
			case 3: printf("\n el mayor esta %d veces en el archivo\n", cantidaddelMayor(ventas, mayorVenta(ventas)));
					system("pause");
					break;
			case 4: visualiar(ventas);
					printf("\n");
					system("pause");
					break;
			case 5: printf("\nel total de las ventas es: %f\n", total(ventas));								
					system("pause");
					break;
			case 6:fclose(ventas);
					remove("ventas.dat");
					opc = 0;
					break;
		}
	}while (opc != 0);	
	fclose(ventas);
}

void registrarVenta(FILE *f, float montoVenta){
	fwrite(&montoVenta, sizeof(montoVenta), 1, f);
}

float mayorVenta(FILE *f){
	float lectura;
	float mayor = 0;
	rewind(f);
	fread(&lectura, sizeof(lectura), 1, f);
	while(!feof(f)){
	  if (lectura > mayor) mayor = lectura;
	  fread(&lectura, sizeof(lectura), 1, f);
	}
	
	return mayor;
}


int cantidaddelMayor(FILE *f, float mayor){
	float lectura;
	int c = 0;
	rewind(f);
	fread(&lectura, sizeof(lectura), 1, f);
	while(!feof(f)){
	  if (lectura == mayor) c++;
	  fread(&lectura, sizeof(lectura), 1, f);
	}
	
	return c;
}


float total(FILE *f){
	float lectura;
	float suma = 0;

	rewind(f);
	fread(&lectura, sizeof(lectura), 1, f);
	while(!feof(f)){
	  suma = suma + lectura;
	  fread(&lectura, sizeof(lectura), 1, f);
	}
	
	return suma;
}


void visualiar(FILE *f){
	float lectura;
	int c = 0;
	rewind(f);
	fread(&lectura, sizeof(float), 1, f);
	while(!feof(f)){
		if (lectura < 10) printf("00000");
		else if (lectura < 100) printf("0000");
			 else if (lectura < 1000) printf("000");
			 	  else if (lectura < 10000) printf("00");
			 	  		else if (lectura < 100000) printf("0");				
		printf("%.2f", lectura);
		
		
		if (c < 9){
			printf(" - ");
			c++;
		}			
		else{
			printf("\n");
			c = 0;
		}
		fread(&lectura, sizeof(float), 1, f);
	}
	
	
	
}


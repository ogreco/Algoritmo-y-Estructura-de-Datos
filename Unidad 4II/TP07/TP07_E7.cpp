/* Una empresa lleva los datos de sus empleados en un arreglo (vector), tener en cuenta que la empresa puede
tener un número máximo de 20 empleados. Los datos que se registran tiene la siguiente información.
? Apellido y Nombre
? Domicilio
? Fecha de Ingreso (anidar) //el año tiene 4 dígitos.
? Fecha de Proceso (anidar) //el año tiene 4 dígitos.
? Antigüedad (Se calcula durante el ingreso de los datos Fecha de Proceso – Fecha de Ingreso).

: definir las estructuras necesarias para
a) Ingresar los datos de los empleados hasta que se decida terminar el ingreso 
o se hayan cargado todos los empleados. (para continuar se deberá preguntar si continua o no)
b) Terminada la carga, calcular y mostrar el promedio de Antigüedad de todos los empleados. Usar una función.
c) Ingresado un determinado apellido y nombre y por medio de una función Listar por pantalla su Antigüedad. En
caso de no existir el empleado mostrar un mensaje de error.
d) Listar todos los empleados de la empresa.
*/
#include <stdio.h>
#include <string.h>

typedef char cadena[45];

struct fecha{
	int dia, mes, anio;
};

struct empleado{
	cadena ApellidoyNombre;
	cadena Domicilio;
	fecha Fecha_de_Ingreso;
	fecha Fecha_de_Proceso;
	int Antiguedad;
};

float promedio(empleado v[], int n);
void listar(empleado v[], int n, cadena nombre);
void listarTodos(empleado v[], int n);

main(){
	empleado empleados[20];
	int n=0;
	int opc = 1;
	
	while(n<20 && opc!=0){
		printf("ingrese el Apellido y Nombre: ");
		_flushall();
		gets(empleados[n].ApellidoyNombre);
		printf("ingrese el Domicilio: ");		
		gets(empleados[n].Domicilio);
		do{
			printf("ingrese la fecha de ingreso: ");
			scanf("%d/%d/%d", &empleados[n].Fecha_de_Ingreso.dia,
						  	  &empleados[n].Fecha_de_Ingreso.mes,
						      &empleados[n].Fecha_de_Ingreso.anio);							  
			printf("ingrese la fecha de proceso: ");
			scanf("%d/%d/%d", &empleados[n].Fecha_de_Proceso.dia,
						      &empleados[n].Fecha_de_Proceso.mes,
						      &empleados[n].Fecha_de_Proceso.anio);	
		}while(empleados[n].Fecha_de_Ingreso.anio < 1950 || empleados[n].Fecha_de_Ingreso.anio > 2020 ||
			   empleados[n].Fecha_de_Proceso.anio < 2020 || empleados[n].Fecha_de_Proceso.anio > 2020);
			   
		empleados[n].Antiguedad = empleados[n].Fecha_de_Proceso.anio - empleados[n].Fecha_de_Ingreso.anio;
		n++;
		printf("\ndesea ingresar otro empledo? 0/1: ");
		scanf("%d", &opc);
	}
	
	printf("\nel promedio es %f", promedio(empleados, n));
	
	cadena nomb;
	printf("ingrese el nombre del empleado que desea ver: ");
	_flushall();
	gets(nomb);
	listar(empleados, n, nomb);
	listarTodos(empleados, n);
}

float promedio(empleado v[], int n){
	int suma = 0;
	for(int i=0; i<n; i++){
		suma += v[i].Antiguedad; 
	}
	
	return (float)suma / n;
}

void listar(empleado v[], int n, cadena nombre){
	bool b = false;
	for(int i=0; i<n; i++){
		if (strcmp(v[i].ApellidoyNombre, nombre) == 0){
			printf("\nla antiguedad de %s es %d", nombre, v[i].Antiguedad);
			b = true;
		}
	}
	
	if (!b) printf("\nerror no existe ese empleado");
}

void listarTodos(empleado v[], int n){
	
	for(int i=0; i<n; i++){
		printf("\nempleado: %s", v[i].ApellidoyNombre);
		printf("\ndomicilio: %s", v[i].Domicilio);
		printf("\nla antiguedad es %d", v[i].Antiguedad);
	
	}	
	
}



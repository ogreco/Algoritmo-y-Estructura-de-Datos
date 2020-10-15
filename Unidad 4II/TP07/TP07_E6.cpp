/*
Una empresa dedicada a la fabricación de casas y edificios guarda en registro que contienen
 la siguiente información de la documentación presentada.
? Número de expediente (alfanumérico).
? Nombre propietario.
? Cantidad de metros cuadrados construidos.
? Tipo de obra (0: vivienda básica, 1: vivienda de Lujo, 2: Edificio, 3: predio especial).
? Fecha Registración, de adelanto de obra por un periodo de 12 meses.
? Monto monetario, recibido de adelanto de obra por un periodo de 12 meses.
:
a) Registrar los datos solicitados al menos de 5 registros,
 se colocar la fecha y los montos de adelanto de obra.
b) Registrar por medio de una función el monto recibido. La función debe recibir por parámetro:
 Número de expediente, fecha del adelanto y cantidad de dinero recibido.
c) Listar por pantalla los montos recibido un determinado expediente.

Expediente: xxxxxxxxx
Propietario: xxxxxx xxxxxx xxxxxx
Tipo Obra : xxxxxxxxxxxxxx
			Fecha Monto
			xxxxxxxx xxxx.xx
			xxxx.xx xxxx.xx
			xxxx.xx xxxx.xx
			xxxx.xx xxxx.xx
				TOTAL XXXX.XX
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha{
	int dia, mes, anio;	
};

typedef char cadena[45];

struct registraciones{
	fecha fecha_reg;
	float monto_reg;
};

struct obra{
	cadena numero_expediente;
	cadena propietario;
	int mtcuadr;
	int tipo_obra;
	int n_reg;
	registraciones reg[100];
};

void registrarAdelanto(obra v[], int n, cadena exp, fecha f, float monto);
void muestra(obra v[], int n, cadena exp);
main(){
	int n;
	printf("ingrese la cantidad de obras: ");
	scanf("%d", &n);
	obra obras[n];
	
	for(int i=0; i<n; i++){
		printf("ingrese el numero de exp: ");
		_flushall();
		gets(obras[i].numero_expediente);
		printf("ingrese el nombre del propietario: ");		
		gets(obras[i].propietario);
		printf("ingrese la cantidad de metros cuadrados: ");
		scanf("%d", &obras[i].mtcuadr);
		do{
			printf("ingrese el tipo de obra: (0: vivienda básica, 1: vivienda de Lujo, 2: Edificio, 3: predio especial)");
			scanf("%d", &obras[i].tipo_obra);		
		}while(obras[i].tipo_obra < 0 || obras[i].tipo_obra > 3);
		
		
		printf("ingrese la primer fecha de adelanto de obra: ");
		scanf("%d/%d/%d", &obras[i].reg[0].fecha_reg.dia, 
		                  &obras[i].reg[0].fecha_reg.mes, 
						  &obras[i].reg[0].fecha_reg.anio);
		printf("ingrese el monto del primer adelanto de obra: ");
		scanf("%f", &obras[i].reg[0].monto_reg);
		obras[i].n_reg = 1;
	}
	int opc;
	cadena expediente;
	fecha fe;
	float monto;
	do{
		printf("ingrese la opcion: ");
		scanf("%d", &opc);
		switch(opc){
			case 1: printf("ingrese el expediente: ");
					_flushall();
					gets(expediente);
					printf("ingrese la fecha: ");
					scanf("%d/%d/%d", &fe.dia, &fe.mes, &fe.anio);
					printf("ingrese el monto: ");
					scanf("%f", &monto);
					registrarAdelanto(obras, n, expediente, fe, monto);
					break;
			case 2: printf("ingrese el expediente: ");
					_flushall();
					gets(expediente);					
					muestra(obras, n, expediente);
					system("pause");
		}
	}while (opc != 3);
	
	
}


void registrarAdelanto(obra v[], int n, cadena exp, fecha f, float monto){
	for(int i=0; i<n; i++){
		if(strcmp(v[i].numero_expediente, exp) == 0){			
			v[i].reg[v[i].n_reg].fecha_reg = f;
			v[i].reg[v[i].n_reg].monto_reg = monto;
			v[i].n_reg++;
		}
	}
}

void muestra(obra v[], int n, cadena exp){
	for(int i=0; i<n; i++){
		if(strcmp(v[i].numero_expediente, exp) == 0){			
			printf("Expediente: %s\n", v[i].numero_expediente);
			printf("Propietario: %s\n", v[i].propietario);
			printf("Tipo de Obra: %d\n", v[i].tipo_obra);
			printf("\t\tFecha\tMonto\n");
			for(int j=0; j<v[i].n_reg; j++){
				printf("\t\t%d/%d/%d\t%f\n", v[i].reg[j].fecha_reg.dia, 
									   		 v[i].reg[j].fecha_reg.mes,
									   		 v[i].reg[j].fecha_reg.anio,
									   		 v[i].reg[j].monto_reg);
			}
		}
	}
}



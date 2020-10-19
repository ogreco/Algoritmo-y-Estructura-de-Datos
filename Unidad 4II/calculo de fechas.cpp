#include <stdio.h>

struct fecha{
	int dia, mes, anio;
};

main(){
	fecha nac, hoy;
	
	nac.dia = 18;
	nac.mes = 10;
	nac.anio = 1984;
	
	hoy.dia = 18;
	hoy.mes = 10;
	hoy.anio = 2020;
	
	int edad = hoy.anio - nac.anio;	
	if (hoy.mes < nac.mes || (hoy.mes == nac.mes &&  hoy.dia < nac.dia)) edad--;
	
	printf("edad: %d", edad);
}

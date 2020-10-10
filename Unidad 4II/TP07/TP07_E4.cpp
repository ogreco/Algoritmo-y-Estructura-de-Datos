/*
? En un colegio secundario los datos de los alumnos están en un registro que contiene los siguientes miembros
(campos):
? Nro. de Documento.
? Apellido y nombre.
? Fecha Nacimiento. (es un registro de 3 campos: día, mes, año. Año tiene 4 dígitos)
? Notas Trimestrales (es un registro de 4 campos: Primer Trimestre, Segundo Trimestre, Tercer Trimestre y promedio
anual)
:
a) Definir de manera apropiada cada uno de los registros y vincular de manera de crear registro de jerarquía.
b) Realizar la carga de N alumnos. Teniendo en cuenta que el campo promedio anual, no se lo pide su ingreso, se
calcula de los tres trimestres que tiene el alumno.
c) A medida que se realiza la carga determinar y mostrar en main, cuántos alumnos están por arriba de un promedio
 ocho
*/
#include <stdio.h>

struct fecha{
	int dia, mes, anio;
};

struct notas{
	int pt, st, tt;
	float promedio;
};

struct estudiante{
	int dni;
	char apelnom[40];
	fecha fnac;
	notas nota;
};


main(){
	estudiante e;
	int n, cont = 0;
	printf("ingrese la cantidad de estudiantes: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("ingrese el dni del estudiante: ");
		scanf("%d", &e.dni);
		printf("ingrese el apellido y nombres del estudiante: ");
		_flushall();
		gets(e.apelnom);
		printf("ingrese la fecha de nacimiento del estudiante: ");
		scanf("%d/%d/%d", &e.fnac.dia, &e.fnac.mes, &e.fnac.anio);
		printf("ingrese la nota del primer trimestre: ");
		scanf("%d", &e.nota.pt);
		printf("ingrese la nota del segundo trimestre: ");
		scanf("%d", &e.nota.st);
		printf("ingrese la nota del tercer trimestre: ");
		scanf("%d", &e.nota.tt);
		e.nota.promedio = (float)(e.nota.pt + e.nota.st + e.nota.tt) / 3;
		if (e.nota.promedio >= 8) cont++;
	}
	
	printf("la cantidad de estudiantes con promedio alto es %d", cont);
	
}



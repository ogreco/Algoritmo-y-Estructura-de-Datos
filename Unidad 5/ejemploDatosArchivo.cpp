#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[45];

struct Fecha{
	int dia, mes, anio;
};

struct Mascota{
	int dniDuenio;
	cadena apellidonombre;	
	Fecha fnac;
};

struct Veterinario{
	int matricula;
	cadena apellidonombre;
};

struct Turno{
	Fecha fecha;
	char atenciom[340];
	int dniDuenio;
	Mascota mascota;
	int matricula;
	Veterinario veterinario;
};

void listarTurnos(FILE *turnos);
void cargarTurno(FILE *turnos, Mascota m, Veterinario v);
Mascota crearMascota(FILE *mascotas);
Mascota buscarMascota(FILE *mascotas, int dni);
Veterinario buscarVeterinario(FILE *veterinarios, int matricula);
	
main(){
	FILE *mascotas = fopen("mascotas.dat", "a+b");
	FILE *veterinarios = fopen("veterinarios.dat", "a+b");
	FILE *turnos = fopen("turnos.dat", "a+b");
	int opc;
	
	do{
		system("cls");
		printf("\n1 crear mascota");
		printf("\n2 crear turno");
		printf("\n3 visualizar turno");
		printf("\nIngrese la opcion deseada: ");
		scanf("%d", &opc);
		Mascota m;
		Veterinario v;
		int dni, matricula;
		
		switch(opc){
			case 1: crearMascota(mascotas); break;
			
			case 2: printf("ingrese el dni del dueño de la mascota: ");
					scanf("%d", &dni);			
			 		m = buscarMascota(mascotas, dni);
			 		printf("ingrese la matricula del veterinario: ");
					scanf("%d", &matricula);			
			 		v = buscarVeterinario(veterinarios, matricula);
			 		cargarTurno(turnos, m, v);
			 		break;
			case 3: listarTurnos(turnos);
					
			
		}
		system("pause");
	}while(true);
	
	
	
	
}


Mascota crearMascota(FILE *mascotas){
	Mascota m;
	printf("ingrese el nombre: ");
	_flushall();
	gets(m.apellidonombre);
	printf("ingrese el dni");
	scanf("%d", &m.dniDuenio);
	
	fwrite(&m, sizeof(m), 1, mascotas);
	
	return m;
}
	
	
void cargarTurno(FILE *turnos, Mascota m, Veterinario v){
	Turno turno;
	
	printf("Ingrese la Fecha: ");
	scanf("%d/%d/%d", &turno.fecha.dia, &turno.fecha.mes, &turno.fecha.anio);
	turno.veterinario = v;
	turno.mascota = m;
	
	fwrite(&turno, sizeof(turno), 1, turnos);
}

Mascota buscarMascota(FILE *mascotas, int dni){
	Mascota m;
	rewind(mascotas);
	fread(&m, sizeof(m), 1, mascotas);
	while(!feof(mascotas)){
		if (m.dniDuenio == dni){
			return m;
		}
		fread(&m, sizeof(m), 1, mascotas);
	}

}

Veterinario buscarVeterinario(FILE *veterinarios, int matricula){
	Veterinario v;
	rewind(veterinarios);
	fread(&v, sizeof(v), 1, veterinarios);
	while(!feof(veterinarios)){
		if (v.matricula == matricula){
			return v;
		}
		fread(&v, sizeof(v), 1, veterinarios);
	}
}

void listarTurnos(FILE *turnos){
	Turno turno;
	Mascota m;
	Veterinario v;
	rewind(turnos);
	fread(&turno, sizeof(turno), 1, turnos);
	while(!feof(turnos)){
		v = buscarVeterinario(veterinarios, turno.matricula);
		printf("\nVeterinario: %s, Matricula: %d", v.apellidonombre, v.matricula);
		m = buscarMascota(mascotas, turno.dniDuenio);
		printf("\nMascota: %s, Dni Dueño: %d", m.apellidonombre, m.dniDuenio);
		//printf("\nVeterinario: %s, Matricula: %d", turno.veterinario.apellidonombre, turno.veterinario.matricula);
		//printf("\nMascota: %s, Dni Dueño: %d", turno.mascota.apellidonombre, turno.mascota.dniDuenio);
		printf("\nFecha Turno: %d/%d/%d", turno.fecha.dia, turno.fecha.mes, turno.fecha.anio);
		printf("\n");
		fread(&turno, sizeof(turno), 1, turnos);
	}
}

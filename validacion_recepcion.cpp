#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Cadena[45];

struct Usuario{
	Cadena nombre;
	Cadena clave;
};

bool iniciarSesion(FILE *usuarios);

main(){
	FILE *usuarios = fopen("usuarios.dat", "a+b");
	bool sesion = iniciarSesion(usuarios);
	
	if (sesion) printf("iniciado");
	else printf("no iniciado");
	
	
	fclose(usuarios);
}

bool iniciarSesion(FILE *usuarios){
	rewind(usuarios);
	Usuario u;
	Cadena nombre, clave;
	printf("ingrese su nombre de usuario: ");
	_flushall();
	gets(nombre);
	printf("ingrese su clave de usuario: ");
	gets(clave);
	
	fread(&u, sizeof(u), 1, usuarios);
	while(!feof(usuarios)){
		if (strcmp(u.nombre, nombre) == 0 && strcmp(u.clave, clave) == 0) return true;
		fread(&u, sizeof(u), 1, usuarios);
	}
	
	return false;
}

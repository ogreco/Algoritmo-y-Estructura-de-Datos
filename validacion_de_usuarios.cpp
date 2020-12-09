#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Cadena[45];

struct Usuario{
	Cadena nombre;
	Cadena clave;
};

void crearUsuario();
bool iniciarSesion();
void listado(FILE *usuarios);
bool validarPass(Cadena pass);
bool validarConsecutivasPass(Cadena pass);

main(){
	int opc;	
	//listado(usuarios);
	bool sesion = false;
	do{
		system("cls");
		printf("**********************Administracion************************\n");
		printf("**********************0) inicio sesion**********************\n");
		printf("**********************1) crear usuarios*********************\n");
		printf("**********************2) visualizar veterinarios************\n");
		printf("**********************3) salir******************************\n");
		printf("************************************************************\n");
		scanf("%d", &opc);
		
		switch(opc){
			case 0: sesion = iniciarSesion(); 
					if (sesion) printf("Bienvenido\n");
					else printf("error en inicio de sesion\n");
			        break;
			case 1: if (!sesion) printf("inicie sesion para continuar\n");
			        else crearUsuario();
					break;
			case 2: if(!sesion) printf("inicie sesion para continuar\n");
					else printf("listado\n");
			        break;
			
		}
		system("pause");
	}while(opc != 3);


}


void crearUsuario(){
	Usuario u;
	FILE *usuarios = fopen("usuarios.dat", "a+b");
	printf("ingrese el nombre para este usuario: ");
	_flushall();
	gets(u.nombre);
	do{
		printf("ingrese la clave para este usuario: ");
		gets(u.clave);		
	}while(!validarPass(u.clave));
	
	fwrite(&u, sizeof(u), 1, usuarios);
	fclose(usuarios);
}


bool iniciarSesion(){
	FILE *usuarios = fopen("usuarios.dat", "a+b");
	Usuario u;
	Cadena nombre, clave;
	printf("ingrese su nombre de usuario: ");
	_flushall();
	gets(nombre);
	printf("ingrese su clave de usuario: ");
	gets(clave);
	
	fread(&u, sizeof(u), 1, usuarios);
	while(!feof(usuarios)){
		if (strcmp(u.nombre, nombre) == 0 && strcmp(u.clave, clave) == 0){
			fclose(usuarios);
			return true;
		} 
		fread(&u, sizeof(u), 1, usuarios);
	}
	
	return false;
}

bool validarPass(Cadena pass){
	int may = 0, min = 0, num = 0, otros = 0, numcons = 0;
	
	for(int i=0; i<strlen(pass); i++){
		if (pass[i] >='A' && pass[i] <='Z'){
			may++;
			numcons = 0;		
		} 
		else if (pass[i] >='a' && pass[i] <='z'){
				 min++;
				 numcons = 0;
			 }
			 else if (pass[i] >= '0' && pass[i] <='9'){
			 	num++;
				numcons++;	
			    }
			 	else otros++;
		if (numcons == 4) break;
	}
	
	return may>=1 && 
		   min>=1 && 
		   num>=1 && 
		   otros==0 && 
	       strlen(pass)>=6 && 
		   strlen(pass)<=32 && 
		   numcons<=3 && 
		   validarConsecutivasPass(pass);
}

bool validarConsecutivasPass(Cadena pass){
	int letrasCons = 1;
	Cadena pass2;
	strcpy(pass2, pass);
	strlwr(pass2);
	//aBuel123
	for(int i=0; i<strlen(pass2); i++){
		if (pass2[i] >='a' && pass2[i] <='z'){
			if(i>0 && pass2[i-1]>'9' && pass[i]==pass2[i-1]+1) letrasCons++;
			//else letrasCons = 0;			
		}
		
		if (letrasCons == 2) break;
	}	
	return letrasCons < 2;
}

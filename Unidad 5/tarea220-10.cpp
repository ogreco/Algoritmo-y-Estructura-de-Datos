//EJEMPLO BASICO DE CARGA DE ARCHIVO



#include <stdio.h>

 #include <stdlib.h>

 #include <string.h>



struct registro

 {??

 int codigo;

 char descri[30];

 float precio;

 };



main (void)

 {

 registro reg;

 int codi;

 //Creamos la variable de la dirección del archivo

 FILE* arch;

 arch=fopen("productos.dat","w+b");


 /*CARGA DE DATOS AL REGISTRO*/

 printf("Ingrese los datos del registro\n\n");

 printf("Codigo: ");

 scanf("%d",&codi);

 while(codi!=0)

 {

 reg.codigo=codi;

 printf("Descripcion: ");

 _flushall();

 gets(reg.descri);

 printf("Precio: ");

 scanf("%f",&reg.precio);


 fwrite(&reg,sizeof(reg),1,arch);


 printf("Ingrese los datos del registro\n\n");

 printf("Codigo: ");

 scanf("%d",&codi);

 }


 system("pause");

 }

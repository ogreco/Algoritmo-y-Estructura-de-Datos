/*completar con lectura del archivo*/
#include <stdio.h>

 #include <stdlib.h>



main()

 {

 int numero,c=0;

 FILE* nro;

 nro=fopen("datnro.dat","a+b");

 printf("\nAgregue un numero entero: ");

 scanf("%d",&numero);

 while(numero!=0)

 {

 fwrite(&numero,sizeof(int),1,nro);

 c++;

 printf("\nIngrese un numero entero: ");

 scanf("%d",&numero);

 }

 printf("\nSe agregaron %d numeros\n",c);



printf("\n\n");

 system("pause");

 }

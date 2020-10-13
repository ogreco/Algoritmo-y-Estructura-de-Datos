/*modificar el codigo para que permita la carga sin limetes de elementos en el vector y sin borrar lo ya cargado*/

    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro
{
int codigo;
char descripcion[30];
float precio;
int stock;
char marca[30];
};
void cargar(registro prod[50], int &cantidad);
void ordenar(int n, registro prod[50]);
void mostrar(int n, registro prod[50]);
void buscar(int n, registro prod[50]);
int menuPrincipal();
int n;
main()
{
int nOp, cantidad = 0;
registro producto[50];
 do
{
nOp = menuPrincipal(); //Llama la función que muestra el menú.
switch(nOp)
{
case 1:
cargar(producto, cantidad);
break;
case 2:
mostrar(cantidad,producto);
break;
case 3:
buscar(n,producto);
break;
case 4:
ordenar(n,producto);
break;
case 5:
system("CLS");
printf("\nF i n d e l P r o g r a m a");
printf("\n");
system("pause");
break;
default:
system("CLS");
printf("Ha ingresado una opcion no valida");
printf("\n");
system("pause");
break;
} //Fin del switch().
}while(nOp != 5); //Fin del Ciclo Do

}

int menuPrincipal()
{
int opc=0;
system("CLS");
printf("\t*************************************************\n");
printf("\t** M E N U P R I N C I P A L **\n");
printf("\t*************************************************\n");
printf("\t** **\n");
printf("\t** 1-> Cargar **\n");
printf("\t** **\n");
printf("\t*************************************************\n");
printf("\t** **\n");
printf("\t** 2-> Mostrar **\n");
printf("\t** **\n");
printf("\t*************************************************\n");
printf("\t** **\n");
printf("\t** 3-> Buscar Productos **\n");
printf("\t** **\n");
printf("\t*************************************************\n");
printf("\t** **\n");
printf("\t** 4-> Ordenar **\n");
printf("\t** **\n");
printf("\t*************************************************\n");
printf("\t** **\n");
printf("\t** 5-> S A L I R del S I S T E M A **\n");
printf("\t** **\n");
printf("\t*************************************************\n\n");
printf(" Seleccione la Opcion: ");
scanf("%d", &opc);
return opc; //retorna el número de opción seleccionada.
}
void cargar(registro prod[50], int &cantidad)
{
	system("cls");
	int aux;
	printf("\nIngrese el codigo del producto: ");
	scanf("%d",&aux);	
	prod[cantidad].codigo=aux;
	_flushall();
	printf("\nDescripcion: ");
	gets(prod[cantidad].descripcion);
	printf("\nPrecio: ");
	scanf("%f",&prod[cantidad].precio);
	printf("\nCantidad: ");
	scanf("%d",&prod[cantidad].stock);
	_flushall();
	printf("\nMarca: ");
	gets(prod[cantidad].marca);
	cantidad++;
}
void ordenar(int n, registro prod[50])
{
bool bandera;
registro auxiliar[50];
int i, valor;
do
{
bandera=false;
for(i=0;i<n-1;i++)
{
if(strcmp(prod[i].descripcion,prod[i+1].descripcion)>0)
{
auxiliar[i]=prod[i];
prod[i]=prod[i+1];
prod[i+1]=auxiliar[i];
bandera=true;
}
}
}
while(bandera==true);
}











void mostrar(int n, registro prod[50])
{
	int i;
	system("cls");
	for(i=0;i<n;i++)
	{
		printf("\nCodigo del producto: %d",prod[i].codigo);
		printf("\nDescripcion: %s",prod[i].descripcion);
		printf("\nPrecio: %.2f",prod[i].precio);
		printf("\nStock: %d",prod[i].stock);
		printf("\nMarca: %s",prod[i].marca);
		printf("\n\n");
	}
system("pause");
}














void buscar(int n, registro prod[100])
{
int i,bandera=0,bus;
printf("\nIngrese el codigo a buscar: ");
scanf("%d",&bus);
for(i=0;i<n;i++)
{
if (bus==prod[i].codigo)
{
printf("\nCodigo del producto: %d",prod[i].codigo);
printf("\nDescripcion: %s",prod[i].descripcion);
printf("\nPrecio: %.2f",prod[i].precio);
printf("\nStock: %b",prod[i].stock);
printf("\nMarca: %s",prod[i].marca);
i=n;
bandera=1;
}
}
if(bandera==0)
printf("\nPRODUCTO NO ENCONTRADO...");
printf("\n\n");
system("pause");
}

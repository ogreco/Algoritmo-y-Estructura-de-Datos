/*
ENUNCIADO
En una empresa de taxis se registra la información en un archivo binario llamado Taxi.dat, 
que posee la siguiente configuración de registro:
Número de licencia.
Patente.
Apellido y Nombre del Chofer
Fecha de Incorporación o compra del vehículo por la empresa. (Registro Jerarquizado). 

SE PIDE:

a) Crear la estructura adecuada. Y utilizando un menú
 de opciones realizar
b) Realizar utilizando una función el Ingreso de los datos de una cantidad no determinada de vehículos.
c) Realizar utilizando una función, el Ingreso un número de licencia y borrar físicamente el registro del archivo.
Si el número de licencia, no existe mostrar un mensaje indicando esta situación.
d) Realizar el Listado de los datos guardados en el archivo. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*----- Estructura ----*/
struct fecha
{
    int dia;
    int mes;
    int anio;
};
/*----- Estructura Jerarquica -----*/
struct RegTaxis
{
    int nroLicencia;
    char ApeNomb[40];
    fecha fec; //Miembro "fec" de tipo estructura fecha.
};

/*----- Prototipos Auxiliares -----*/
int menuPrincipal();
void mensaje(char const *cadena);
/*----- Prototipos que dan solución al enunciado -----*/
void registrarTaxis(FILE *taxis);//PUNTO 01.
bool borradoTaxis(FILE *taxis); //PUNTO 02. Devuelve un valor lógico 1si fue borrado.
void listarTaxis(FILE *taxis); //PUNTO 03.
/*----- Bloque Principal -----*/


main()
{
    int N=0, nroLic=0, nOp = 0;
    int nroOp = 0;
    /*------ Abrir y verificar apertura del archivo -----*/
    FILE *ArchTaxis; //Se abre de lectura para conservar
    ArchTaxis = fopen("taxis.dat","w+b"); //los anteriores registros.
    if(ArchTaxis == NULL)
    {// Evalua, Si hubo error, muestra mensaje y termina.
        system("CLS");
        mensaje("Ocurrio un error en la apertura del Archivo....");
        exit(1);
    }


    do
    {
        nOp = menuPrincipal(); //Llama la función que muestra el menú.
        switch(nOp)
        {
            case 1:
                registrarTaxis(ArchTaxis);
                break;

            case 2:
                bool band;
                band = borradoTaxis(ArchTaxis);
                if(band)
                ArchTaxis = fopen("taxis.dat","r+b"); //Se abre de nuevo el archivo, porque
                break; //Fue cerrado en el borrado físico.

            case 3:
                listarTaxis(ArchTaxis);
            break;

            case 4:
                system("CLS");
                mensaje("F i n d e l P r o g r a m a");
                break;

            default:
                system("CLS");
                mensaje("Ha ingresado un numero no valido");
                break;
        } //Fin del switch().

    }while(nOp != 4); //Fin del Ciclo Do
} //Final del main().


/*------------------------------------------------*/
void registrarTaxis(FILE *Taxis)
{
    RegTaxis reg; //crea la variable "reg" de tipo RegTaxis.
    int nroReg=0; //Variable contador del nro de registros almacenado.
    char continua='N';
    do{
        system("CLS");
        printf("\t****************************\n");
        printf("\t** Registro Nro %3.0d **\n", ++nroReg);
        printf("\t****************************\n\n");
        printf("\n\t Nro Licencia : "); scanf("%d",&reg.nroLicencia);
        _flushall();
        printf("\n\t Apellido y Nombre: "); gets(reg.ApeNomb);
        printf("\n\t Fecha: \n");
        printf("\n\t Dia: "); scanf("%d",&reg.fec.dia);
        printf("\n\t Mes: "); scanf("%d",&reg.fec.mes);
        printf("\n\t Anio: "); scanf("%d",&reg.fec.anio);
        fwrite(&reg, sizeof(RegTaxis), 1, Taxis); //Graba el registro lógico.
        _flushall();
        printf("\n\nContinua Registrando Taxis (S/N): ");
        scanf("%c", &continua);
    }while(continua == 'S' || continua == 's');
    system("CLS");
    mensaje("F i n de la c a r g a"); //Muestra el mensaje.
} //Fin de la función registrarTaxis.


/*------------------------------------------------*/
bool borradoTaxis(FILE *Taxis)
{
    int nroLicencia;
    bool bandEncontrado; //Variable para indicar si fue borrado o no.
    bandEncontrado = false; //Se inicializa en falso.
    RegTaxis reg;
    /*----- Se crea un archivo Temporal -----*/
    FILE *ArchTemp;
    ArchTemp = fopen("taxisTemp.dat","w+b"); //Se crea un archivo de respaldo.
    /*----- Se muestra un título ----*/
    system("CLS");
    printf("\n\t************************************************");
    printf("\n\t** **");
    printf("\n\t** B O R R A D O **");
    printf("\n\t** **");
    printf("\n\t************************************************");
    /*----- Se pide el ingreso del nro de licencia a buscar ----*/
    printf("\n\n\t Ingrese Nro de Licencia: ");
    scanf("%d", &nroLicencia);

    if (nroLicencia > 0 )
    {//Si es mayor a cero se busca, en otro caso sale.
        rewind(Taxis); //Ubica el puntero en el primer registro del archivo.
        fread(&reg, sizeof(reg), 1, Taxis); //Lee el primer registro.
        while(!feof(Taxis))
        { //Repetir hasta el último registro.
            if(nroLicencia != reg.nroLicencia)
            { //Si son diferente, Se guarda en el
                fwrite(&reg, sizeof(reg), 1, ArchTemp); //archivo temporal el registro leído.
            }
            else
            { //si son iguales
                bandEncontrado = true;//Pone en verdadero a la variable, indicando que
            } //fue encontrado y no guarda en archivo temporal el registro
            fread(&reg, sizeof(RegTaxis), 1, Taxis);//Continua leyendo.
        }
    }
    else
    {
        fclose(ArchTemp); //Cierra el archivo temporal.
    }
    
    if(bandEncontrado)
    {
        fclose(ArchTemp); //Cierro archivo Temporal.
        fclose(Taxis); //Cierro archivo Maestro.
        remove("taxis.dat"); //Borro el archivo Maestro.
        rename("taxisTemp.dat","taxis.dat"); //Cambio de nombre del Archivo Temporal.
        //Por el del maestro.
        mensaje("Nro de Licencia Encontrada, ha sido eliminado fisicamente");
    }
    else
    {
        mensaje("Nro de Licencia No Encontrada, No se realizo el borrado");
        fclose(ArchTemp); //Cierro archivo Temporal.
    }
    system("CLS");
    mensaje("F I N DEL B O R R A D O ");
    remove("taxisTemp.dat"); //Elimina el archivo temporal creado.
    return bandEncontrado;
} //Fin de la función borradoTaxis.


/*------------------------------------------------*/
void listarTaxis(FILE *Taxis){
 RegTaxis reg; //Registro logico.
/*----- Titulo del listado -----*/
 system("CLS");
 printf("\t*********************************************************\n");
 printf("\t** L I S T A D O DE T A X I S R E T I R A D O S **\n");
 printf("\t*********************************************************\n\n");
 printf("\t* Licencia \t Chofer\t \t Fecha **\n\n");
 printf("\t*********************************************************\n\n");
/*----- Listado de los Taxis -----*/
 rewind(Taxis); //Ubica el puntero en el primer registro del archivo.
 fread(&reg, sizeof(reg), 1, Taxis); //Leer el primer registro.
 if (feof(Taxis)){
    system("CLS");
    mensaje("El Archivo esta vacio\n No se Registro Informacion.");
 }

 else{
    
    while(!feof(Taxis)){ //Repite hasta el último registro.
        printf("\t %d ", reg.nroLicencia);
        printf("\t %s ", reg.ApeNomb );
        printf("\t %d/%d/%d ", reg.fec.dia, reg.fec.mes, reg.fec.anio);
        printf("\n");
        fread(&reg, sizeof(RegTaxis), 1, Taxis);//Continua leyendo.
    }
 }
 mensaje("F i n del L i s t a d o");
} //Fin de la función listarTaxis.
/*------------------------------------------------*/



/*------------------------------------------------*/
int menuPrincipal()
{
 int opc=0;
 system("CLS");
 printf("\t*************************************************\n");
 printf("\t** M E N U P R I N C I P A L **\n");
 printf("\t*************************************************\n");
 printf("\t** **\n");
 printf("\t** 1-> Registrar **\n");
 printf("\t** **\n");
 printf("\t*************************************************\n");
 printf("\t** **\n");
 printf("\t** 2-> Borrar **\n");
 printf("\t** **\n");
 printf("\t*************************************************\n");
 printf("\t** **\n");
 printf("\t** 3-> Listar Choferes **\n");
 printf("\t** **\n");
 printf("\t*************************************************\n");
 printf("\t** **\n");
 printf("\t** 4-> S A L I R del S I S T E M A **\n");
 printf("\t** **\n");
 printf("\t*************************************************\n\n");
 printf(" Seleccione Opcion: ");
 scanf("%d", &opc);
 return opc; //retorna el número de opción seleccionada.
} //Fin de la función menuPrincipal.


/*------------------------------------------------*/
void mensaje(char const *cadena)
{
printf("\n\n\n***********************************************************\n");
printf("\n %s ", cadena );
printf("\n\n***********************************************************\n\n\t");
system("PAUSE");
} //Fin de la función mensaje().



/*
Se necesita registrar los apellidos y nombres de N personas en un vector.  
SE PIDE:  
    
    -Usando una función sin Tipo, ingrese los datos solicitados al vector. 
    -Usando una función, listar los nombres de las personas registradas en el vector. La función no devuel ve valor. 
    -Usando una función, Buscar una determinada persona. Los datos serán ingresados en la función don de se deberá hacer la búsqueda. La función devuelve un valor indicando si fue o no encontrado, mos trar un mensaje indicando si fue hallada o no la persona en la función main. 
    -Usar una función para ordenar los datos de mayor a menor usando una variable Auxiliar y Listar los  datos ordenados. 
    -Realizar la eliminación de una persona y reagrupar el vector dejando la celda vacía como último ele mento del vector. En caso de no ser encontrada deberá ser indicado que no se encuentra atravesó de  un mensaje

Nota:  
    En este ejemplo se verán diferentes funciones para para trabajar con datos de tipo cadena (string) guardados  en un vector. 
    
    -Definición de un tipo de datos personal. 
    -Ingreso de datos. 
    -Ordenamiento de datos. 
    -Búsqueda de datos. 
    -Listados de datos. 
    -Eliminación de datos. Y reordenamiento de un vector. 
    -Listar los datos de las personas en mayúscula. 
*/


#include <stdio.h> // puts, gets, scanf, printf y otras funciones 
#include <stdlib.h> // system(..) y otras funciones. 
#include <string.h> // strcpy, strlwr, strupr, strlen, strcat, strcmp y otras funciones. 
/*--- Define un nuevo tipo de dato. De tipo global, Así se utiliza en todas las funciones que la necesite*/ typedef char ApellidoNombre[40]; //define un vector de 30 caracteres. Almacena apellido y nombre. 
/*-------- Declaracion de funciones -----------------*/ 
void CargarNombres(ApellidoNombre AyN[100], int N); 
void Listado(ApellidoNombre AyN[100], int N); 
int BuscarAyN(ApellidoNombre AyN[100], int N); //Devuelve 0 (no se encontro) , 1 ( fue Encontrada) 
void Ordenar(ApellidoNombre AyN[100], int N); //Ordena los datos ingresados. 
int Eliminar(ApellidoNombre AyN[100], int N); //Elimina un dato y ordena vector. 
void LimpiarPantalla(void); //Se utiliza para limpiar la pantalla 
main() 
{ 
    ApellidoNombre ListaDeApNom[ 100]; //define un vector de 100 caracteres. 
    int i, N, Resp=0, OkElim = 0; 
    
	printf("Cuantos Personas desea ingresar: "); 
    scanf("%d", &N); 
    CargarNombres(ListaDeApNom , N); //Llamada a la funcion, para registrar los apellidos y nombres 
    LimpiarPantalla(); 
    
	printf("\t...................Lisdado de Personas ..............\n"); 
    Listado( ListaDeApNom , N); //Lamada a la funcion, sin tipo, para listar los datos registrados 
    LimpiarPantalla(); 
    
	Resp = BuscarAyN( ListaDeApNom , N ); //Llamada a la funcion, con Tipo, busca apellido y nombre. 
    if(Resp == 1) 
    { 
        printf("El Apellido y Nombre Buscado, fue encontrado.....\n\n" ); 
    }
    else { 
        printf("El Apellido y Nombre Buscado, NO fue encontrado.....\n\n" ); 
    } 
	LimpiarPantalla(); 
    
	Ordenar(ListaDeApNom , N); //Llamada a la funcion para ordenar los datos.de z..a 

    printf("\n\n\n Listado de los datos Ordenados.........."); 
    Listado(ListaDeApNom , N); //Lamada a la funcion para listar los datos. 
    LimpiarPantalla(); 

    //Elimina y Reagrupa el vector de nombre. 
    OkElim = 0; 
    OkElim = Eliminar( ListaDeApNom , N); 
    LimpiarPantalla(); 

    if(OkElim == 1) 
    { 
        printf("\n\n\n Fue elimnado la persona, Se lista los que quedan.........."); 
        Listado(ListaDeApNom , N); //Lamada a la funcion para listar los datos. 
    }
    else { 
        printf("\n\n\n\t\t No se encontro la persona a eliminar..........\n"); 
    } 

    LimpiarPantalla(); 

} //Fin de main().


/////////////////////////////////////////

void CargarNombres(ApellidoNombre AyN[100], int N)
{
    _flushall(); //Función que limpia el buffers de entrada.
    int i;
    printf("\n\n\t\t...............Registracion de Apellidos y Nombres...........\n\n");
    for(i=0; i<N; i++)
        {
            printf("\t Ingrese Apellido y Nombre/s de la persona %d: ", i+1);
            gets(AyN[i]);
        } //Fin de la carga de Personas.
} //Fin de la función CargarNombres

/////////////////////////////////////////

void Listado(ApellidoNombre AyN[100], int N)
{
    int i;
    printf("\n");
    for(i=0; i<N; i++)
        {
            printf("\t");
            puts(AyN[i]);
        } //Fin del listado de Personas ingresadas.
} //Fin de la función


/////////////////////////////////////////

int BuscarAyN(ApellidoNombre AyN[100], int N)
{
    ApellidoNombre Buscar; //Define la variable Buscar del tipo ApellidoNombre.
    int i, Band=0; //Bandera tendrá 0 -> no fue hallado, 1-> cuando se encuentre.
    int res = 0; //Variable que contendrá el valor de comparación de las cadenas.
    system("CLS");
    printf("\n\n Ingrese el Apellido y Nombre de la persona a buscar: ");
    gets(Buscar);
    strlwr(Buscar);
    _flushall();
        for(i=0; i<N; i++) //For que inicia la búsqueda
        {
            res = strcmp(Buscar,AyN[i]); // Si devuelve cero la función strcmp(..);
            if(res == 0) //Fue encontrada, la bandera 1
                {
                    Band = 1;
                }
            } //Fin del listado de Personas ingresadas.
    return Band;
}

/////////////////////////////////////////

void Ordenar(ApellidoNombre AyN[100], int N)
{
    int i, j, res;
    ApellidoNombre Aux; //Creo una variable auxiliar del tipo apellido y nombre
    /*Convierte a minúscula el vector*/
    for(i=0; i< N; i++)
    {
        strlwr(AyN[i]) ; //Convierte el contenido del vector a minúscula.
    }

    /* Realiza el ordenamiento*/
    for(j=0; j < N; j++) //For que inicia el ordenamiento en N pasadas.
    {
        for(i=0; i < N-1; i++) //For que ordena en 1 pasada a la vez.
        {
            res = strcmp(AyN[i],AyN[i+1]); //Compara dos elemento consecutivo.
            if(res < 0) // entonces AyN[i] es mayor que AyN[i+1]
            {
                strcpy(Aux,AyN[i+1]);
                strcpy(AyN[i+1],AyN[i]);
                strcpy(AyN[i],Aux);
            }
        } //Fin del ciclo que ordena un elemento.
    } //fin del Ciclo de ordenamiento.
    
} //Fin de la función ordenar

/////////////////////////////////////////

int Eliminar(ApellidoNombre AyN[100], int N)
{
    char CadBus[40]; //Contendrá el apellido y nombre a buscar.
    char CadVacia[40];
    CadVacia[0]= '\0'; //Es una cadena vacía
    int i , j , ResComp, OkElim = 0;
    printf("\n\n Ingrese el Apellido y Nombre a Eliminar de la lista: ");
    gets(CadBus);
    strlwr(CadBus); //Convierte a minúsculas toda la cadena ingresada.
    /*Comienza la Búsqueda */
    for(i=0; i < N; i++)
    {
        ResComp = strcmp(CadBus , AyN[i]);
        if(ResComp == 0)
        {
            OkElim = 1 ; //Al ser encontrado la bandera se pone en 1.
            /*Reagrupa el vector*/
            for(j=i ; j < N-1; j++)
            {
                strcpy( AyN[j] , AyN[j+1]);
            }
        }
    }
    if(OkElim == 1)
    {
        strcpy( AyN[N-1] , CadVacia);
    }
    return OkElim;
}


/////////////////////////////////////////

void LimpiarPantalla(void)
{
    printf("\n\n");
    system("PAUSE");
    system("CLS");
}

/////////////////////////////////////////

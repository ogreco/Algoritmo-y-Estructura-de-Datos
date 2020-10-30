/*
Crear un archivo binario (Multiplo.Dat) e ingresar una serie indeterminada de números entero.
a) Deberá guardar en el archivo, solo aquellos valores que sean múltiplos de 3.
b) Deberá mostrar, luego del ingreso, los valores guardados y
c) Deberá mostrar, la cantidad de valores que no se guardaron.

Un ejemplo de apertura es el siguiente:
arch = fopen (“datos.dat”,”r+b”);
donde el segundo parámetro es el modo de apertura, que pueden ser:
• rb: Sólo lectura. El archivo debe existir, caso contrario retorna NULL
• wb: Solo escritura. Si no existe el archivo lo crea, caso contrario borra su contenido y lo abre vacío.
• ab: Sólo escritura. Si no existe el archivo lo crea, caso contrario no lo destruye. Los registros que se
graban lo hacen al final.
• r+b: Lectura y escritura. El archivo debe existir previamente.
• w+b: Lectura y escritura. Si no existe el archivo lo crea, caso contrario lo borra y lo abre vacío.
• a+b: Lectura y escritura. Si no existe el archivo lo crea, caso contrario no lo borra. Añade al final.



*/

#include <stdio.h>
#include <stdlib.h> 

main()

{
    FILE *archMultiplo; //Se crea un puntero de archive, para manejar los datos de un archivo.
    int valIngresado=0;
    int canNumNoGua =0;
    char opcSalida = 'N';  
    
    archMultiplo = fopen("Multiplo.dat", "w+b"); // Se abre el archivo, se asigna el puntero a la variable creada anteriormente.
    
	if(archMultiplo == NULL) // Si tuvo problema y no se abrió se muestra un mensaje y se cierra el programa.
    {   
        system("CLS"); 
        printf("\n\n Se produjo un ERROR al intentar abrir el archivo\n");
        printf("comuníquese con el administrador del Sistema. Gracias");
        system("PAUSE");
        exit(1);
    }


    do{  // hacer
    	printf("\nSolo se almaceneran aquellos valores que sean multiplos de 3"); 
    	
        printf("\nlngrese un Nro : ");   
        scanf("%d", &valIngresado);  
    
	    if ( valIngresado%3 == 0) //Determina si es múltiplo de 3
        {
            fwrite(&valIngresado, sizeof(valIngresado), 1, archMultiplo);  //Guarda el valor ingresado
        }else{
            canNumNoGua = canNumNoGua + 1;   //Cuenta los no guardados
        }  
    
	    printf("n\t Continua: (S)i - (N)o, Ingrese Opcion: "); //Pregunta si continua
        _flushall();
        scanf("%c", &opcSalida);   //recibe la repuesta por teclado.
    
	}while ((opcSalida == 'S') || (opcSalida == 's'));  //mientras “opcSalida” sea ‘S’ o ‘s’. 
    
    
    system("CLS");
    
	printf("\n\n\t\t LISTADO DEL ARCHIVO..............\n\n");
    rewind(archMultiplo);  //Ubica el puntero en el primer valor que tiene el archivo.
    
	fread(&valIngresado, sizeof(valIngresado), 1, archMultiplo); //Lee un valor.

    while ( !feof(archMultiplo) ) //Mientras no se fin de archivo hacer
    {   
        printf("%d - ",  valIngresado);
        fread(&valIngresado, sizeof(valIngresado), 1 , archMultiplo);
    } 
    
	fclose(archMultiplo); //cierra el archivo.
    
	printf("\n\n\t\t\t La cantidad de valores no Guardados es: %d \n\t\t", canNumNoGua);
    system("PAUSE");

}   




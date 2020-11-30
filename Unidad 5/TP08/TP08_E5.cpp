#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char frase[80];
char menu();
void combinar(FILE *arch1, FILE *arch2);
void joselwr(FILE *arch1);
void mariaupr(FILE *arch2);

main()
{
    FILE *arch1 = NULL, *arch2 = NULL;
    char opc;
    frase fraseX;

    do{
        opc = menu();
        switch (opc)
        {
        case 'a':
                arch1 = fopen("frases1.txt", "a+");
                arch2 = fopen("frases2.txt", "a+");
                if(arch1 == NULL || arch2 == NULL)
                {
                    printf("Error al crear el archivo");
                    exit(1);
                }
            break;

        case 'b':
                if(arch1 != NULL)
                 {
                    printf("Ingresar frase para Jose Luis: ");
                    _flushall();
                    gets(fraseX);
                    fprintf(arch1, "%s\n", fraseX);
                }
                else printf("Error al crear el archivo");
                break;

        case 'c':
                if(arch2 != NULL)
                {
                    printf("Ingresar frase para Maria Emilia: ");
                    _flushall();
                    gets(fraseX);
                    fprintf(arch2, "%s\n", fraseX);
                }
                else printf("Error al crear el archivo");
                break;
                
        case 'd':
                combinar(arch1, arch2);
                break;
            
        case 'e':
                joselwr(arch1);
                break;

        case 'f':
                mariaupr(arch2);
                break;
        }
        system("pause");
    }while(opc != 'h' && opc !='H');

    fclose(arch1);
    fclose(arch2);
}

char menu(){
	system("cls");
	printf("*********************VENTAS*************************\n");
	printf("\t a) Crear y/o abrir Archivos\n");
	printf("\t b) Cargar frases de Jose Luis\n");
	printf("\t c) Cargar frases de Maria Emilia\n");
	printf("\t d) Combinar ambos archivos\n");
	printf("\t e) Cargar frases de Jose Luis(Minusculas)\n");
    printf("\t f) Cargar frases de Maria Emilia(Mayusculas)\n");
    printf("\t g) Cargar frases combinadas\n");
	printf("\t h) Salir\n");
	printf("****************************************************\n");
	printf("ingrese la opcion deseada: \n");
	char opc;
	_flushall();
	scanf("%c", &opc);
	return opc;
}

void combinar(FILE *arch1, FILE *arch2)
{
	FILE *combinado = fopen("combinado.txt", "w+");
	fclose(arch1);
	fclose(arch2);

    arch1 = fopen("frases1.txt", "r");
    arch2 = fopen("frases2.txt", "r");
	bool b1 = true, b2 = true;

	int c = 0;
	frase lect1, lect2;
	fgets(lect1, 80, arch1);
	fgets(lect2, 80, arch2);
	while(b1 || b2)
    {
    	b1 = !feof(arch1); 
		b2 = !feof(arch2);
		if (b1){
		 fprintf(combinado, lect1);		
		 fgets(lect1, 80, arch1);
		}
		if (b2){
		 fprintf(combinado, lect2);	    
	     fgets(lect2, 80, arch2);	
		}
        
	}
	
	fclose(combinado);
    fclose(arch1);
    fclose(arch2);
    arch1 = fopen("frases1.txt", "a+");
    arch2 = fopen("frases2.txt", "a+");
}

void joselwr(FILE *arch1)
{
    system("cls");
    rewind(arch1);
    char lect1[80];

    while(!feof(arch1))
    {
        fgets(lect1, 80, arch1);
        printf("%s\n", strlwr(lect1));
    }
}

void mariaupr(FILE *arch2)
{
    system("cls");
    rewind(arch2);
    char lect1[80];

    while(!feof(arch2))
    {
        fgets(lect1, 80, arch2);
        printf("%s\n", strupr(lect1));
    }
}

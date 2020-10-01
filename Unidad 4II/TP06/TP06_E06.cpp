#include <stdlib.h>
#include <stdio.h>
#include <string.h>

main(){
	char cadena[120];
	gets(cadena);
	for(int i=strlen(cadena); i>=0; i--)
		printf("%c", cadena[i]);
	
}

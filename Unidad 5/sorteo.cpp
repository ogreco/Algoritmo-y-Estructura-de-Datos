#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char cadena[10];

main(){
	srand(time(NULL));
	cadena temas[4] = {"intro", "caracte", "requeri", "ejemplo"};
	cadena nombre[4] = {"damian", "julian", "gonzalo", "mauricio"};
	
	for (int i=0; i<4; i++){
		printf("%s -> %s\n", temas[i], nombre[rand()%4]);
	}
	
	
}

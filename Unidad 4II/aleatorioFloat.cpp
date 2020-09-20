#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
	float num;
	srand(time(NULL));
	num = rand()+ (float)1/(rand()%99);
	
	printf("%f", num);
}

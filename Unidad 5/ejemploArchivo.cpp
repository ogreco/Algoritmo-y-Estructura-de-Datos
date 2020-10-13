#include <stdio.h>

main(){
	int n;
	int x;
	FILE *miarchivo;
	
	miarchivo = fopen("numeros.dat", "w+b");
	if(miarchivo == NULL) printf("\nerror en la apertura del archivo");
	
	printf("Ingrese la cantidad de numeros: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("\nIngrese el numero: ");
		scanf("%d", &x);
		
		fwrite(&x, sizeof(int), 1, miarchivo);
	}
}

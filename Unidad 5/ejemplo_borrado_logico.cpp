#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct reg{
	int num;
	bool activo;
};

main(){
	FILE *arch = fopen("archivo.dat", "a+b");
	reg r;
	int c = 0;
	srand(time(NULL));
	
	while (c<5){
		r.activo = true;
		r.num = rand();
		fwrite(&r, sizeof(r), 1, arch);
		c++;
	}
	
	rewind(arch);
	
	fread(&r, sizeof(r), 1, arch);
	while(!feof(arch)){
		printf("%d\n", r.num);
		fread(&r, sizeof(r), 1, arch);
	}
	
	int numero;
	printf("ingrese el numero que desea eliminar: ");
	scanf("%d", &numero);
	
	bool b = false;
	rewind(arch);
	fread(&r, sizeof(r), 1, arch);
	while(!feof(arch) && !b){		
		if (r.num == numero){			
			r.activo = false;
			fseek(arch, -sizeof(r), SEEK_CUR);
			fwrite(&r, sizeof(r), 1, arch);			
			fread(&r, sizeof(r), 1, arch);
			b = true;
		}else
		fread(&r, sizeof(r), 1, arch);
	}
	
	printf("______________________________\n");
	rewind(arch);
	
	fread(&r, sizeof(r), 1, arch);
	while(!feof(arch)){
		if (r.activo) printf("%d\n", r.num);
		fread(&r, sizeof(r), 1, arch);
	}
	
	
}


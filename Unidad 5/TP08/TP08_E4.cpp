#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[45];
struct fecha{
	int dia, mes, anio;
};

struct venta{
	int nro_vendedor;
	cadena nombre_vendedor;
	int nro_factura;
	float importe;
	int forma_venta;
	fecha f_venta;
	bool borrado;
};

int dibujarMenu();
void carga(FILE *arch);
void listarVentasxMes(FILE *arch, int mes);
void cantidadVentasxMes(FILE *arch, int mes, int &contado, int &credito);
float TotalVentasxVendMes(FILE *arch, int mes, cadena nombre);
void listarVentas(FILE *arch);
void modificarFormaVenta(FILE *arch, int NumFactura, int numVendedor);
void bajaLogica(FILE *arch, int NumFactura, int numVendedor);
void listarBorrados(FILE *arch);
void borradoFisico(FILE *arch);
void ordenar(FILE *arch);

main(){
	FILE *arch = fopen("misventas.dat", "a+b");
	int mes;
	int contado = 0, credito = 0;
	cadena nombre;
	if (arch == NULL){
		printf("el archivo no se pudo crear! fin del programa");
		return 0;
	}
	
	int opc;
	do{
		int num=0, vend=0;
		opc = dibujarMenu();
		switch(opc){
			case 1:carga(arch);				 	 
					 break;
					 
			case 2:printf("ingrese un mes para visualizar sus ventas: ");					 
					 scanf("%d", &mes);
					 listarVentasxMes(arch, mes);					 
					 break;
					 
			case 3:printf("ingrese un mes para visualizar sus ventas: ");					 
					 scanf("%d", &mes);			
					 contado = 0, credito = 0;		 
					 cantidadVentasxMes(arch, mes, contado, credito);
					 printf("el total de ventas de contado es de %d y en credito es %d\n", contado, credito);					 
					 break;
					 
			case 4:printf("ingrese un mes para visualizar sus ventas: ");					 
					 scanf("%d", &mes);
					 printf("ingrese un nombre para visualizar sus ventas: ");					 
					 _flushall();
					 gets(nombre);					 
					 printf("el total de ventas de %s es de %f\n", nombre, TotalVentasxVendMes(arch, mes, nombre));					 
					 break;
			
			case 5:listarVentas(arch);					 
					 break;
		    
			case 6: printf("Ingrese el numero de vendedor: ");
				 	  scanf("%d", &vend);
				 	  printf("\nIngrese el numero de factura a modificar: ");
				 	  scanf("%d", &num);
				 	  modificarFormaVenta(arch, num, vend);
				 	  break;
  			
			  case 7:	printf("Ingrese el numero de vendedor: ");
			  	 	scanf("%d", &vend);
			  	 	printf("Ingrese la factura que desea dar de baja: ");
			  	 	scanf("%d", &num);
			  	 	bajaLogica(arch, num, vend);
			  	 	break;
			
			case 8: listarBorrados(arch);
				 	break;
				 	
			case 9: borradoFisico(arch);
				 	break;
			
			case 10: ordenar(arch);
				 	 break;
		}
		system("pause");
	}while(opc != 11);
	
	fclose(arch);
}

int dibujarMenu(){
	system("cls");
	printf("*********************VENTAS*************************\n");
	printf("\t 1) Carga de Ventas\n");
	printf("\t 2) Ventas en un mes\n");
	printf("\t 3) Cantidad de Ventas por tipo y por mes\n");
	printf("\t 4) Ventas por vendedor y por mes\n");
	printf("\t 5) Listado total de Ventas\n");
	printf("\t 6) Modificar forma de venta\n");
	printf("\t 7) Dar de baja un registro\n");
	printf("\t 8) Montrar registros dados de baja\n");
	printf("\t 9) Borrar fisicamente los registros con baja logica\n");
	printf("\t 10) Ordenar por numero de falctura\n");
	printf("\t 11) Salir\n");
	printf("****************************************************\n");
	printf("ingrese la opcion deseada: \n");
	int opc;
	scanf("%d", &opc);
	return opc;
}

void carga(FILE *arch){
	
	venta v;
	do{
		printf("ingrese numero de vendedor (1 , 2 , 3): ");
		scanf("%d", &v.nro_vendedor);	
	}while(v.nro_vendedor <1 || v.nro_vendedor>3);
	printf("ingrese el nombre del vendedor: ");
	_flushall();
	gets(v.nombre_vendedor);
	printf("ingrese el numero de factura de la venta: ");
	scanf("%d", &v.nro_factura);
	printf("ingrese el importe de la venta: ");
	scanf("%f", &v.importe);
	do{
		printf("ingrese la forma de venta. 1: Contado ; 2: Credito: ");
		scanf("%d", &v.forma_venta);
	}while(v.forma_venta!=1 && v.forma_venta!=2);
	
	printf("ingrese la fecha de la venta: ");
	scanf("%d/%d/%d", &v.f_venta.dia, &v.f_venta.mes, &v.f_venta.anio);
	v.borrado = false;
	
	fwrite(&v, sizeof(v), 1, arch);
	
}

void listarVentasxMes(FILE *arch, int mes){

	venta v;
	rewind(arch);
	fread(&v, sizeof(v), 1, arch);
	while(!feof(arch)){
		
		if(v.borrado == false){
			if (v.f_venta.mes == mes){
			   printf("Numero de Vendedor: %d\n", v.nro_vendedor);
			   printf("Nombre de Vendedor: %s\n", v.nombre_vendedor);
			   printf("Numero de factura: %d\n", v.nro_factura);
			   printf("Importe de la Venta: %f\n", v.importe);
			   printf("Forma de Venta: %d\n", v.forma_venta);
			   printf("Fecha de Venta: %d/%d/%d\n", v.f_venta.dia, v.f_venta.mes, v.f_venta.anio);
			   printf("\n");				
			}	
		}
		
		fread(&v, sizeof(v), 1, arch);
	}

}

void cantidadVentasxMes(FILE *arch, int mes, int &contado, int &credito){

	venta v;
	rewind(arch);
	fread(&v, sizeof(v), 1, arch);
	while(!feof(arch)){
		
		if(v.borrado == false){
			if (v.f_venta.mes == mes){
			   if (v.forma_venta == 1) contado++;
			   else credito++;
			}
		}
		
		fread(&v, sizeof(v), 1, arch);
	}

}

float TotalVentasxVendMes(FILE *arch, int mes, cadena nombre){

	
	float total = 0;
	venta v;
	rewind(arch);
	fread(&v, sizeof(v), 1, arch);
	while(!feof(arch)){
		
		if(v.borrado == false){
			
			if (v.f_venta.mes == mes && strcmp(v.nombre_vendedor, nombre) == 0){
			   total += v.importe;
			}	
		}
		
		fread(&v, sizeof(v), 1, arch);
	}
	return total;
	
}

void listarVentas(FILE *arch){	

	venta v;
	rewind(arch);
	fread(&v, sizeof(v), 1, arch);
	while(!feof(arch)){
		if(v.borrado == false){
			printf("Numero de Vendedor: %d\n", v.nro_vendedor);
			printf("Nombre de Vendedor: %s\n", v.nombre_vendedor);
			printf("Numero de factura: %d\n", v.nro_factura);
			printf("Importe de la Venta: %.2f\n", v.importe);
			printf("Forma de Venta: ");
			if(v.forma_venta == 1)printf("Contado\n");
			else printf("Credito\n");
			printf("Fecha de Venta: %d/%d/%d\n", v.f_venta.dia, v.f_venta.mes, v.f_venta.anio);	
			printf("\n");
		}
		
		fread(&v, sizeof(v), 1, arch);
	}

}

void modificarFormaVenta(FILE *arch, int NumFactura, int numVendedor){
	fclose(arch);
	arch = fopen("misventas.dat", "r+b");
	venta v;
	bool b=false;
	//rewind(arch);
	fread(&v, sizeof(v), 1, arch);
	while(!feof(arch)){
		
		if(v.nro_vendedor == numVendedor && v.borrado == false){
			
			if(v.nro_factura == NumFactura ){
				
		 		printf("\nForma de venta registrada: ");
				
				if(v.forma_venta == 1){
					printf("\nContado");	
				}
				else{
					printf("\nCredito");
				}
				do{
				   printf("\nIngrese la forma de venta. 1: Contado ; 2: Credito: ");
				   scanf("%d", &v.forma_venta);
				}while(v.forma_venta!=1 && v.forma_venta!=2);
				
				//int pos = ftell(arch);
				//fseek(arch, pos, SEEK_SET);
				fseek(arch,- sizeof(venta), SEEK_CUR);
				fwrite(&v, sizeof(venta), 1, arch);
				fseek(arch,sizeof(arch), SEEK_CUR);
				b=true;
			}
		}
		
		fread(&v, sizeof(v), 1, arch);
	}
	if(b==false){
		printf("El registro no existe.\n");
	}
	fclose(arch);
	arch = fopen("misventas.dat", "a+b");
}

void bajaLogica(FILE *arch, int NumFactura,int numVendedor){
	fclose(arch);
	arch = fopen("misventas.dat", "r+b");
	venta v;
	bool b=false;
	
	rewind(arch);

	fread(&v,sizeof(venta),1,arch);
	while(!feof(arch) && b == false){
		
		if(v.nro_vendedor == numVendedor){
			
			if(v.nro_factura == NumFactura && v.borrado == false){
			
				b=true;
				printf("Numero de factura: %d\n", v.nro_factura);
				printf("Numero de Vendedor: %d\n", v.nro_vendedor);
				printf("Nombre de Vendedor: %s\n", v.nombre_vendedor);
				printf("Importe de la Venta: %f\n", v.importe);
				printf("Forma de Venta: ");
	  				if(v.forma_venta == 1){
						printf("Contado");
					}
					else{
						printf("Credito");
					}
				printf("Fecha de Venta: %d/%d/%d\n", v.f_venta.dia, v.f_venta.mes, v.f_venta.anio);
			
				v.borrado = true;
            	
				fseek(arch,- sizeof(venta),SEEK_CUR); 
            	fwrite(&v,sizeof(venta),1,arch);
            	
				printf("Registro dado de baja");
				printf("\n");
	            system("pause");
            	b=true;
			}
		}
		
		else{
			fread(&v,sizeof(venta),1,arch);
		}
	}
	if(b == false){
		printf("\nEl registro no existe.\n");
	}
	fclose(arch);
	arch = fopen("misventas.dat", "a+b");
}

void listarBorrados(FILE *arch){

	venta v;
	rewind(arch);
	fread(&v, sizeof(venta), 1, arch);
	bool b=false;
	while(!feof(arch)){
		if(v.borrado == true){
			printf("\nRegistros dados de baja");
			printf("\n=======================\n");
			
			printf("Numero de Vendedor: %d\n", v.nro_vendedor);
			printf("Nombre de Vendedor: %s\n", v.nombre_vendedor);
			printf("Numero de factura: %d\n", v.nro_factura);
			printf("Importe de la Venta: %f\n", v.importe);
			printf("Forma de Venta: ");
			if(v.forma_venta == 1)printf("Contado\n");
			else printf("Credito\n");
			printf("Fecha de Venta: %d/%d/%d\n", v.f_venta.dia, v.f_venta.mes, v.f_venta.anio);	
			printf("\n");
			b=true;
		}
		fread(&v, sizeof(venta), 1, arch);
	}
	if(b==false){
		printf("No se encontro ningun registro.");
	}

}

void borradoFisico(FILE *arch){
	fclose(arch);
	arch = fopen("misventas.dat","r+b");
	FILE *aux = fopen("auxiliar.dat","wb");
	
	venta v;
	rewind(arch);
	bool b=false;
	fread(&v, sizeof(venta), 1, arch);
	while(!feof(arch)){
		
		if(v.borrado == false){
			fwrite(&v, sizeof(venta), 1, aux);
		}
		else
			b=true;
		fread(&v, sizeof(venta), 1, arch);	
		
	}
	
	if(b==true){
	printf("Registro/s daso/s de baja.");
	printf("\n");
	}
	
	fclose(arch);
	fclose(aux);
	remove("misventas.dat");
	rename("auxiliar.dat","misventas.dat");
	
	arch = fopen("misventas.dat", "a+b");
}

void ordenar(FILE *arch){
	
	//fclose(arch);
	//arch = fopen("misventas.dat","rb");

	rewind(arch);
	venta vector[100], v, aux;
	
	int i=0;
	
	fread(&v, sizeof(venta),1,arch);
	while(!feof(arch)){
		
		if(v.borrado == false){
	 		vector[i]=v;
			i++;	
		}
		fread(&v, sizeof(venta),1,arch);
	}
	
	int n=i;
	bool band;
	
	do{
		band = false;
		for(i=0; i<n-1; i++){
			
			if(vector[i].nro_factura > vector[i+1].nro_factura){
				
				aux = vector[i];
				vector[i] = vector[i+1];
				vector[i+1] = aux;
				band = true;
			}
			
		}
		
	}while(band == true);

	fclose(arch);
	arch = fopen("misventas.dat","w+b");
	rewind(arch);
	
	for(i=0; i<n; i++){
		v = vector[i];
		fwrite(&v,sizeof(venta),1,arch);
	}
	printf("\nArchivo ordenado con exito.\n\n");
	
	rewind(arch);
	fread(&v, sizeof(venta),1, arch);
	
	while(!feof(arch)){
		
		if(v.borrado == false){
			
			printf("Numero de Vendedor: %d\n", v.nro_vendedor);
			printf("Nombre de Vendedor: %s\n", v.nombre_vendedor);
			printf("Numero de factura: %d\n", v.nro_factura);
			printf("Importe de la Venta: %f\n", v.importe);
			printf("Forma de Venta: ");
			if(v.forma_venta == 1)printf("Contado\n");
			else printf("Credito\n");
			printf("Fecha de Venta: %d/%d/%d\n", v.f_venta.dia, v.f_venta.mes, v.f_venta.anio);
			printf("\n");
		}
		
		fread(&v, sizeof(venta),1, arch);
	}
	
	fclose(arch);
	arch = fopen("misventas.dat", "a+b");
}












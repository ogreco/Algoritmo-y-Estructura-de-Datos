#include <stdio.h>
#include <string.h>

typedef char cadena[32];

bool validarPass(cadena pass);
bool validarConsecutivasPass(cadena pass);

main(){
	cadena pass;
	
	do{
		printf("ingrese una password valido: ");
		_flushall();
		gets(pass);			
	}while(!validarPass(pass));
	
	printf("pass Valido!");
}

//"dA122dAoPFmk"

bool validarPass(cadena pass){
	int may = 0, min = 0, num = 0, otros = 0, numcons = 0;
	
	for(int i=0; i<strlen(pass); i++){
		if (pass[i] >='A' && pass[i] <='Z'){
			may++;
			numcons = 0;		
		} 
		else if (pass[i] >='a' && pass[i] <='z'){
				 min++;
				 numcons = 0;
			 }
			 else if (pass[i] >= '0' && pass[i] <='9'){
			 	num++;
				numcons++;	
			    }
			 	else otros++;
		if (numcons == 4) break;
	}
	
	return may>=1 && 
		   min>=1 && 
		   num>=1 && 
		   otros==0 && 
	       strlen(pass)>=6 && 
		   strlen(pass)<=32 && 
		   numcons<=3 && 
		   validarConsecutivasPass(pass);
}

bool validarConsecutivasPass(cadena pass){
	int letrasCons = 1;
	
	strlwr(pass);
	//aBuel123
	for(int i=0; i<strlen(pass); i++){
		if (pass[i] >='a' && pass[i] <='z'){
			if(i>0 && pass[i-1]>'9' && pass[i]==pass[i-1]+1) letrasCons++;
			//else letrasCons = 0;			
		}
		
		if (letrasCons == 2) break;
	}	
	return letrasCons < 2;
}

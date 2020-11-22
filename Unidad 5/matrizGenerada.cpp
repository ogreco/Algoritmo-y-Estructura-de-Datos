#include <stdio.h>


main(){
	int m[5][5];
	int num = 1;
	for(int i=0;i<5;i++)
		if (i%2==0) 
			for(int j=0;j<5;j++){
				m[i][j] = num;
				num++;
			} 	
		else 
			for(int j=4;j>=0;j--){
				m[i][j] = num;
				num++;
			}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

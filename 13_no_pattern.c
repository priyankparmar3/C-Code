/*
 * To make pattern of Numbers like
 *1
 *2
 *3
 *4
 *5
 *6 5 4 3 2 1
 */
#include<stdio.h>
int main(void){
	char i,j;
	for(i=1;i<=6;i++){
		for(j=6;j>0;j--){
			if(i==6)
				printf("%d\t",j);
			else if(j==6)
				printf("%d\t",i);		
		
		}
	printf("\n");
	}
	 return 0;
}

/* 
 * Program to Display the Pattern
 */
#include<stdio.h>
#define SIZE 5
int main(){
	char i,j;
	for(i=0;i<SIZE-1;i++){
		for(j=0;j<SIZE;j++){
			if(i<(SIZE/2)){
				if(j>=((SIZE/2) - i) && j<=((SIZE/2) + i))
					printf(" ");
				else
					printf("*");
			}
			else{
				if(j>=((SIZE/2) - (5 - i)) && j<=((SIZE/2) + (5 - i)))
					printf(" ");
				else
					printf("*");

			}
		}
		printf("\n");
	}
	return 0;
}

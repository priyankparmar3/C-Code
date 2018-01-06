/*
 * Program to calculate digits in a number
 */
#include<stdio.h>
int main(){
	int no,temp;
	char i,j;
	printf("Emter Number :");
	scanf("%d",&no);
	do{
		no=no/10;
		temp = no *10;
		printf("%d\n",temp);
	}while(no>9);
	printf("%d",no);
	return 0;
}

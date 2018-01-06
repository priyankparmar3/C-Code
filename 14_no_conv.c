/*
 * Program to convert 49.546 to 546.49
 */
#include<stdio.h>
int main(void){
	float no;
	float whole;	
	float dec;
	printf("Enter Number :");
	scanf("%f",&no);
	whole = (int)no;
	no = whole - no;
	while(whole>=1){
		whole/=10;
	}
	while((no/10)!=0.00){
		no/=10;
	}
	printf("Whole no is %f\n",whole);
	return 0;
}

/*
 * To implement Call by value and Call by reference
 */
#include<stdio.h>
#include<stdlib.h>
int add_val(int, int);
int add_ref(int*, int*);
int main(void){
	int a,b;
	int *ap,*bp;
	printf("Enter A and B :");
	scanf("%d %d",&a,&b);	
	ap = &a;
	bp = &b;
	printf("\nAddition by value :%d",add_val(a,b));
	printf("\nAddition by Reference is :%d",add_ref(ap,bp));
	return 0;
}
int add_val(int x,int y){
	return x+y;
}

int add_ref(int *x, int *y){
	return (*x+*y);
}

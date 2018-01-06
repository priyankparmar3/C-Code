/*
 * Addition of array using Recursion;
 */
#include<stdio.h>
int add(int*,int);
int main(void){
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	printf("\n Sum is %d", add(arr,10-1));
	return 0;
}

int add(int *a,int n){
	static int sum=0;
	if(n>=0){
		printf("\nThis is IF and sum is %d",sum);
		return sum+=add(a[n],--n);
	}
	else{
		printf("\nThis is ELSE and sum is %d",sum);
		return 0;
	}	
}


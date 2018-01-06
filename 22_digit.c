/*
 * Sample Program to print 5678 to 5678 678 78 8
 */
#include<stdio.h>
#include<math.h>
int main(void){
	int num=5678,no;
	char i;
	while(num!=0){
		printf("%d\t",num);
		i=0;
		no = num;
		while(no>9){
			no/=10;
			i++;
		}
		num = num - no*pow(10,i);
	}
	return 0;
}

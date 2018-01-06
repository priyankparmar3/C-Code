/*
 * Program for encryption
 */
#include<stdio.h>
#define MAX 1024
int main(){
	char str[MAX],i;
	printf("Enter String :");
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
		str[i] = str[i] + 2;
	printf("Encrypted String :%s\n",str);
	return 0;
}

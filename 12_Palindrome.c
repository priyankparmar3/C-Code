/*
 * Program to find the pelindrome string
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1024
int main(){
	char str[SIZE],i,j;
	printf("Enter String :");
	gets(str);
	j=strlen(str)-1;
	for(i=0;i<(strlen(str)/2);i++)
		if(i<j)
			if(str[i]!=str[j--]){
				printf("\nString is Not A Palindrome!!");
				exit(1);
			}
	printf("String is A Palindrome!!");
}

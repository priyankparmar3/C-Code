/*
 * To find lenght of string using pointer
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1024
int main(void){
	char str[SIZE],*ptr,len=0;
	/* input from user */
	printf("\nEnter input string :");
	gets(str);
	ptr=&str;
	/* calculating string lenght */
	while(*ptr++!='\0'){
		len++;
	}
	/* lenght output */
	printf("\nString length :%d", len);
	return 0;
}

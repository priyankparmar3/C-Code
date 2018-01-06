/*
 * To count the number of Characters and words 
 */
#include<stdio.h>
#include<string.h>
#define SIZE 1024
int main(void){
	char str[SIZE],i,no_word=1;
	printf("Enter String :");
	gets(str);
	for(i=0;i<strlen(str);i++)
		if(str[i]==' ')
			no_word++;

	printf("No of Words : %d",no_word);
	return 0;
}

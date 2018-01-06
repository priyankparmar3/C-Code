/*
 * Write a program to create a thread, thread routine should increment a number in infinite loop, main() should also increment a number and 
 * print the same.
 * and starting number will be given as input from command line.
 */
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *thread_function(void *args);	//thread function declaration

int main(int argc, int argv[]){
	if(argc == 2){
		int main_count = atoi((char*)argv[1]);
		pthread_t a_thread;
		if(pthread_create(&a_thread,NULL,thread_function,(void*)argv[1])!=0){
			perror("\nThread Creation Failed!!");
			exit(EXIT_FAILURE);
		}
		while(1)	
			printf("\nMain Count is %d",main_count++);
		pthread_join(a_thread,NULL);	
	}
	else {
		printf("\nOnly ONE Argument Allowed!!");
		exit(1);
	}
	return 0;
}

void *thread_function(void *args){	//thread function definition
	int thread_count = atoi((char*)args);	
	while(1)
		printf("\nThread Count is %d",thread_count++);
	pthread_exit(NULL);
}

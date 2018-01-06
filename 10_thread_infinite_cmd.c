/*
 * Write a program to create a thread, thread routine should increment a number in infinite loop.
 * starting number will be given as input from command line.
 */
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *thread_function(void *args);	// thread function declaration

int main(int argc, char *argv[]){
	if(argc==2){	// argc : count of command line argument; argv[]: command line input
		pthread_t a_thread;	//thread variable declaration
		if(pthread_create(&a_thread,NULL,thread_function,(void*)argv[1])!=0){
			perror("\nThread Creation Failed!!");
			exit(EXIT_FAILURE);
		}	//thread creation
		pthread_join(a_thread,NULL);	
	}
	else {
		printf("\nOnly ONE Argument Allowed!!");
		exit(1);
	}
	return 0;
}

void *thread_function(void *args){
	int count_t = atoi((char*)args); // Converting character command line argument to Integer
//	while(1)
		printf("%d\n",count_t++);
	pthread_exit(NULL);
}

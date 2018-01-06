/*
 * Incrementing main and thread variable inifinitely
 */
#include<stdio.h>
#include<pthread.h>

void *thread_function(void *args); 

int main(void){
	int main_count=0;
	pthread_t a_thread; 
	if(pthread_create(&a_thread,NULL,thread_function,NULL)!=0){	
		perror("\nThread Creation Failed!!");
	} 
	while(1)	 
		printf("\nMain Count is %d",main_count++);
	pthread_join(a_thread,NULL);
	return 0;
}

void *thread_function(void *args){ 
	int thread_count=0; 	
	while(1)	
		printf("\nThread Count is %d",thread_count++);
	pthread_exit(NULL);
}

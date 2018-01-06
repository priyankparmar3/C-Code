/*
 * Incrementing variable infinitely using thread function
 */
#include<stdio.h>
#include<pthread.h>

#define EXIT_FAILURE 	0

/* thread function declaration */
void *thread_function(void *args);

int main(void){
	pthread_t a_thread; //Thread variable declaration
	if(pthread_create(&a_thread,NULL,thread_function,NULL)!=0){	//Thread Creation
		perror("\nThread Creation Failed!!");
		exit(EXIT_FAILURE);
	} 
	pthread_join(a_thread,NULL);
	return 0;
}

/* thread function definition */
void *thread_function(void *args){ //Thread function
	int i=0;
	while(1)
		printf("%d\n",i++);
	pthread_exit(NULL);
}

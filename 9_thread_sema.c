/*
 * Changing the priority of the thread using SEMAPHORE
 */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
void *thread_a_function(void);
void *thread_b_function(void);
sem_t sem;
int main(void){
	pthread_t a_thread, b_thread;
	printf("\nI am in Main");
	sem_init(&sem,NULL,NULL);
	if(pthread_create(&a_thread,NULL,thread_a_function,NULL)!=0){
		perror("\nThread Creation Failed!!");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&b_thread,NULL,thread_b_function,NULL)!=0){
		perror("\mThread Creation Failed!!");
		exit(EXIT_FAILURE);
	}
	pthread_join(a_thread,NULL);
	pthread_join(b_thread,NULL);
	return 0;
}

void *thread_a_function(void){
	sem_wait(&sem);
	printf("\nI am in Thread A");
}
	
void *thread_b_function(void){
	printf("\nI am in Thread B");
	sem_post(&sem);
}

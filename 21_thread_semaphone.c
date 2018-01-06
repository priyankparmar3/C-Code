/*
 * Priority Inversion  using SEMAPHORE
 */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
void *thread_a_function(void);
void *thread_b_function(void);
void *thread_c_function(void);
void *thread_d_function(void);
sem_t sem1, sem2, sem3;  //Semaphore variable declaration
int main(void){
	pthread_t a_thread, b_thread, c_thread, d_thread;	//Thread variable declaration
	printf("\nI am in Main");
	sem_init(&sem1,NULL,NULL); //Initialisation of semaphore with value ZERO
	sem_init(&sem2,NULL,NULL);
	sem_init(&sem3,NULL,NULL);
	if(pthread_create(&a_thread,NULL,thread_a_function,NULL)!=0){
		perror("\nThread Creation Failed!!");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&b_thread,NULL,thread_b_function,NULL)!=0){
		perror("\nThread Creation Failed!!");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&c_thread,NULL,thread_c_function,NULL)!=0){
		perror("\nThread Creation Failed!!");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&d_thread,NULL,thread_d_function,NULL)!=0){
		perror("\mThread Creation Failed!!");
		exit(EXIT_FAILURE);
	}
	pthread_join(a_thread,NULL);
	pthread_join(b_thread,NULL);
	pthread_join(c_thread,NULL);
	pthread_join(d_thread,NULL);
	return 0;
}

void *thread_a_function(void){
	sem_wait(&sem3);
	printf("\nI am in Thread A");
}
	
void *thread_b_function(void){
	sem_wait(&sem2);
	printf("\nI am in Thread B");
	sem_post(&sem3);
}

void *thread_c_function(void){
	sem_wait(&sem1);
	printf("\nI am in Thread C");
	sem_post(&sem2);
}
	
void *thread_d_function(void){
	printf("\nI am in Thread D");
	sem_post(&sem1);
}

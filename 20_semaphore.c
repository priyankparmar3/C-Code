/* Procer - Consumer program using threads and semaphore (1 day)
 * - A queue will be shared among two threads 
 *        a. Producer thread 
 *        b. Consumer thread
 * - Producer thread will write a number in the queue
 * - Consumer should read the number from queue and print it on console only if the queue is not empty
 */
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define SIZE 1024
char message[SIZE];
void *producer_thread_function(void *args);
void *consumer_thread_function(void *args);
sem_t sem;
int main(void){
	pthread_t p_thread, c_thread;
	sem_init(&sem,NULL,NULL);
	if(pthread_create(&p_thread,NULL,producer_thread_function,NULL)!=0){
		perror("\nThread Creation Failed!!");
	}
	if(pthread_create(&c_thread,NULL,consumer_thread_function,NULL)!=0){
		perror("\nThread Creation Failed!!");
	}
	pthread_join(p_thread,NULL);
	pthread_join(c_thread,NULL);
	return 0;
}
	

void *producer_thread_function(void *args){
	printf("\nEnter Message :");
	gets(message);
	sem_post(&sem);
}
void *consumer_thread_function(void *args){
	sem_wait(&sem);
	printf("\nMessage is :%s",message);
}


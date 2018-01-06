 /* Understanding of mutex. Sample program demostrating usage of mutex (1 day)
  * - Write a program to create two threads. 
  * - One thread will write A to Z a file "temp.txt"
  * - Other thread will write a to z to the same file "temp.txt"
  * - Restriction is, A to Z or a to z should be continuous pattern, whichever is started first.
  * - Identify why and where mutex should be used. 
  * - If required, protect the critical region.
 */
#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<semaphore.h>
void *thread_function_write(void *args);
char cnt=0;
int fd;
pthread_mutex_t lock;
int main(void){
	pthread_t C_thread, S_thread;
	fd = creat("temp.txt",O_RDONLY|O_WRONLY); 
	system('chmod a+rwx temp.txt');
	if(pthread_create(&C_thread,NULL,thread_function_write,NULL)!=0){
		perror("\nThread Creation Failed!!");
	}
	if(pthread_create(&S_thread,NULL,thread_function_write,NULL)!=0){
		perror("\nThread Creation Failed!!");
	}
	pthread_join(C_thread,NULL);
	pthread_join(S_thread,NULL);
	return 0;
}

void *thread_function_write(void *args){
	cnt++;
	//Critical Section Start
	pthread_mutex_lock(&lock);
	if(cnt == 1){
		char str[26],i;
		open(fd, O_RDONLY|O_WRONLY);
		for(i=0;i<26;i++)
			write(fd, (char)(i+65), 26);
		/*for(i=0;i<26;i++)
			str[i] = i+65;
		 open(fd, O_RDONLY|O_WRONLY);
		 write(fd, str,26);
		 */
	}	
	if(cnt == 2){	
		char str[26],i;
		for(i=0;i<26;i++)
			str[i] = i+97;
		open(fd, O_RDONLY|O_WRONLY);
		write(fd, str,26);
	}
	pthread_mutex_unlock(&lock);
	//Critical Section End
}


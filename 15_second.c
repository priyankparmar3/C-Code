/*
 * To count the number of Hours, Minute and Seconds
 */
#include<stdio.h>
int main(void){
	int sec,hh=0,mm=0,ss=0;
	printf("Enter Seconds :");
	scanf("%d",&sec);
	hh = sec/3600;
	sec = sec-(hh*3600);
	mm = sec/60;
	ss = sec-(mm*60);
	printf("Time is %d : %d : %d\n",hh,mm,ss);
	return 0;
}

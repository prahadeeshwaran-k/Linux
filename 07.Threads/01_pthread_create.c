//Basic Thread example with two threads
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread1(void *);
void *thread2(void *);
int main()
{
	pthread_t t1,t2;
	printf("In main() process...\n");
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	printf("In main(), thread-1 id = %lu\n",t1);
	printf("In main(), thread-2 id = %lu\n",t2);
	printf("Infinite process...\n");
	while(1);
}

void *thread1(void *p)
{
	printf("In thread1...\n");
	sleep(5);
	//while(1);
	printf("thread1 exit\n");
}

void *thread2(void *p)
{
	printf("In thread2...\n");
	sleep(7);
	//while(1);
	printf("thread2 exit\n");
}


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *thread1(void *);
void *thread2(void *);
int main()
{
    pthread_t t1, t2;
    char *ptr;
    printf("In main() process...\n");
    pthread_create(&t1, 0, thread1, 0);
    pthread_create(&t2, 0, thread2, 0);
    pthread_join(t1, (void **)&ptr);//here it wait for the Thread 1 need to completed
    // untill main function in a block state
    // pthread_join(t2,(void **)&ptr);
    printf("in main(), ptr = %s\n", ptr);
    printf("main process is exit\n");
}

void *thread1(void *p)
{
    printf("in thread1 5 seconds delay\n");
    sleep(5);
    printf("thread-1 is exit\n");
    pthread_exit("Bye Bye thread-1");
}
void *thread2(void *p)
{
    printf("in thread2 7 seconds delay\n");
    sleep(7);
    printf("thread-2 is exit\n");
    pthread_exit("Bye Bye thread-2");
}
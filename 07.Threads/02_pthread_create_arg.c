//threads with passing arguments 
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread1(void *);
void *thread2(void *);

int main()
{
    pthread_t t1, t2;
    printf("In main() process...\n");
    pthread_create(&t1, 0, thread1, "Hello");
    pthread_create(&t2, 0, thread2, "Hai");
    sleep(3);
    printf("main process exit\n");
}

void *thread1(void *p)
{
    printf("In thread1, p = %s\n", (char *)p);
    sleep(1);
    printf("thread1 exit\n");
}

void *thread2(void *p)
{
    printf("In thread2, p = %s\n", (char *)p);
    sleep(2);
    printf("thread2 exit\n");
}
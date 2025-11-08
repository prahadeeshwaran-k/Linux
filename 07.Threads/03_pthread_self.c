//pthread with pthread_self() it return the pthread id
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *thread1(void *);
void *thread2(void *);
int main()
{
    //pthread is a unsigned long typedef
    pthread_t t1, t2;
    printf("In main() process...\n");
    pthread_create(&t1, 0, thread1, 0);
    pthread_create(&t2, 0, thread2, 0);
    printf("In main(), thread-1 id = %lu\n", t1);
    printf("In main(), thread-2 id = %lu\n", t2);
    while (3)
        ;
    printf("main() process exit\n");
}

void *thread1(void *p)
{
    size_t id = pthread_self();
    printf("In thread1(), id = %lu\n", id);
    sleep(1);
    printf("thread1 exit\n");
}

void *thread2(void *p)
{
    size_t id = pthread_self();
    printf("In thread2(), id = %lu\n", id);
    sleep(2);
    printf("thread2 exit\n");
}
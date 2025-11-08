#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *thread(void *);
int main()
{
    size_t stack;
    pthread_t t;
    pthread_attr_t v;
    pthread_attr_init(&v);                 // initializes with default attributes
    pthread_attr_getstacksize(&v, &stack); // get stack val from attr
    printf("thread stack value : %lu\n", stack);

    stack = stack - 1000;
    pthread_attr_setstacksize(&v, stack); // set stack val into attr
    printf("In main() process...\n");

    pthread_create(&t, &v, thread, 0);
    printf("In main(), thread id = %lu\n", t);
    printf("Infinite process...\n");
    while (1)
        ;
}
void *thread(void *p)
{
    printf("In thread process...\n");
    sleep(5);
    printf("thread exit\n");
}
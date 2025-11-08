//Race Condition Example (unsafe code)
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int S_Resource = 0;

void *thread1(void *arg)
{
    int i = 10;
    while (i--)
    {
        int temp = S_Resource;   // read
        usleep(1000);            // small delay → increases race condition
        temp = temp + 1;         // modify
        S_Resource = temp;       // write
        printf("T1 -> %d\n", S_Resource);
    }
    return NULL;
}

void *thread2(void *arg)
{
    int i = 10;
    while (i--)
    {
        int temp = S_Resource;   
        usleep(1000);            // small delay → increases race
        temp = temp + 1;
        S_Resource = temp;
        printf("T2 -> %d\n", S_Resource);
    }
    return NULL;
}

int main()
{
    pthread_t T1, T2;

    pthread_create(&T1, NULL, thread1, NULL);
    pthread_create(&T2, NULL, thread2, NULL);

    pthread_join(T1, NULL);
    pthread_join(T2, NULL);

    printf("FINAL = %d\n", S_Resource);

    return 0;
}

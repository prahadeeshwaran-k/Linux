#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t key = PTHREAD_MUTEX_INITIALIZER;
int S_Resource = 0;

void *thread1(void *arg)
{
    int i = 10;
    while (i)
    {
        pthread_mutex_lock(&key);   // 🔐 LOCK
        S_Resource++;
        printf("T1: %d\n", S_Resource);
        pthread_mutex_unlock(&key); // 🔓 UNLOCK
        i--;
    }
    return NULL;
}

void *thread2(void *arg)
{
    int i = 10;
    while (i)
    {
        pthread_mutex_lock(&key);   // 🔐 LOCK
        S_Resource++;
        printf("T2: %d\n", S_Resource);
        pthread_mutex_unlock(&key); // 🔓 UNLOCK
        i--;
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

    printf("Final Value = %d\n", S_Resource);
    return 0;
}

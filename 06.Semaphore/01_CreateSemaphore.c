#include <stdio.h>
#include <sys/sem.h>
int main()
{
    int id;
    id = semget(5, 3, IPC_CREAT | 0664);
    if (id < 0)
    {
        perror("semget");
        return 0;
    }
    printf("semaphore array created..\n");
    printf("id = %d\n", id);
}
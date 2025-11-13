#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
int main()
{
    int id;
    int *p;
    id = shmget(11, 20, IPC_CREAT | 0664);
    if (id < 0)
    {
        perror("shmget");
        return 0;
    }
    printf("segment created..\n");
    p = shmat(id, 0, 0);
    while (1)
    {
        printf("%d\n", *p);//it read only in the same memory location only
        sleep(1);
    }
    shmdt(p);
}
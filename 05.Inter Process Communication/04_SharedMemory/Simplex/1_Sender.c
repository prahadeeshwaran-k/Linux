#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
int main()
{
    int id;
    int *p, i = 0;
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
        *p = i++;
        sleep(1);
    }
    shmdt(p);
}
// Program to get a value from semaphore number = Index of the semaphore (GETVAL)
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
int main(int argc, char *argv[])
{
    int index, ret, id;
    if (argc != 2)
    {
        printf("./a.out semnum..\n");
        return 0;
    }
    id = semget(11, 3, IPC_CREAT | 0664);
    if (id < 0)
    {
        perror("semget");
        return 0;
    }
    index = atoi(argv[1]);
    ret = semctl(id, index, GETVAL);
    printf("ret = %d\n", ret);
}
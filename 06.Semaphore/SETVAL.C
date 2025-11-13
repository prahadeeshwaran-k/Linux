// Program to set a value from semaphore number (SETVAL)
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
int main(int argc, char *argv[])
{
    int index, val, id;
    if (argc != 3)
    {
        printf("./a.out semnum Semval\n");
        return 0;
    }
    id = semget(11, 3, IPC_CREAT | 0664);
    if (id < 0)
    {
        perror("semget");
        return 0;
    }
    index = atoi(argv[1]);
    val = atoi(argv[2]);
    semctl(id, index, SETVAL, val);
}
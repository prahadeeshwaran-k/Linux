#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sem.h>
int main()
{
    int fd = open("temp", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char s[] = "ABCDEFGHIJ";
    int i, id = semget(11, 3, IPC_CREAT | 0644);
    struct sembuf v;
    v.sem_num = 0; // 0th index of semaphore array.
    v.sem_op = 0; // it is binary semaphore.
    v.sem_flg = 0;
    
    //Meaning of the 1 in semop(id, &v, 1). How many semaphore operations should be executed?
    semop(id, &v, 1);//code waits here
    //It is used to perform operations on semaphores—usually to lock, unlock, 
    //or wait for a semaphore—allowing processes to synchronize access to shared resources.
    semctl(id, 0, SETVAL, 1);

    printf("entering into critical section of the code\n");
    printf("Process-1 writing the data into a file\n");
    for (i = 0; s[i]; i++)
    {
        write(fd, s + i, 1);
        sleep(1);
    }
    printf("Process-1 is completed to write the data in a file\n");
    semctl(id, 0, SETVAL, 0);
    close(fd);
}
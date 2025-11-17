#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sem.h>
int main()
{
    int fd = open("temp", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char s[] = "123456789";
    int i, id = semget(11, 3, IPC_CREAT | 0644);
    struct sembuf v;
    v.sem_num = 0; // 0th index of semaphore array.
    v.sem_op = 0;
    v.sem_flg = 0;

    semop(id, &v, 1);
    semctl(id, 0, SETVAL, 1);

    printf("entering into critical section of the code\n");
    printf("Process-2 writing the data into a file\n");
    for (i = 0; s[i]; i++)
    {
        write(fd, s + i, 1);
        sleep(1);
    }
    printf("Process-2 is completed to write the data in a file\n");
    semctl(id, 0, SETVAL, 0);
    close(fd);
}
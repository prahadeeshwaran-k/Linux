#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    char str1[20], str2[20];
    mkfifo("fifo1", 0664);
    mkfifo("fifo2", 0664);
    perror("mkfifo");
    printf("hi..\n");
    int fd1 = open("fifo1", O_WRONLY);
    int fd2 = open("fifo2", O_RDONLY);
    if ((fd1 < 0) || (fd2 < 0))
    {
        perror("open");
        return 0;
    }
    if (fork() == 0)
    {
        while (1)
        {
            scanf("%s", str1);
            write(fd1, str1, strlen(str1) + 1);
        }
    }
    else
    {
        while (1)
        {
            read(fd2, str2, sizeof(str2));
            printf("%s\n", str2);
        }
    }
}
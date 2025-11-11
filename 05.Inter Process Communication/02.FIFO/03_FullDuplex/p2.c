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
    int fd1 = open("fifo1", O_RDONLY);
    int fd2 = open("fifo2", O_WRONLY);
    if ((fd1 < 0) || (fd2 < 0))
    {
        perror("open");
        return 0;
    }


    if (fork() == 0)
    {
        while (1)
        {
            read(fd1, str1, sizeof(str1));
            printf("%s\n", str1);
        }
    }
    else
    {
        while (1)
        {
            scanf("%s", str2);
            write(fd2, str2, strlen(str2) + 1);
        }
    }
}

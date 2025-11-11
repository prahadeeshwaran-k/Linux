#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int fd;
    char str1[20], str2[20];
    mkfifo("fifo", 0664);
    perror("mkfifo");
    printf("hi..\n");
    fd = open("fifo",O_RDWR);
    if (fd < 0)
    {
        perror("open");
        return 0;
    }
    while (1)
    {
        read(fd, str1, sizeof(str1));
        printf("read = %s\n", str1);
        printf("write : ");
        scanf("%s", str2);
        write(fd, str2, strlen(str2) + 1);
        sleep(1);
    }
}

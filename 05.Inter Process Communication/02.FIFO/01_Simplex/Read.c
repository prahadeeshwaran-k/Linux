#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    int fd;
    char str[20];
    mkfifo("fifo", 0664);
    perror("mkfifo");
    printf("hi..\n");
    fd = open("fifo", O_RDONLY);//in there the execution is wait un-till the some other process in open the same FIFO in Write mode.
    if (fd < 0)
    {
        perror("open");
        return 0;
    }
    while (1)
    {
        int ret = read(fd, str, sizeof(str));
        printf("ret = %d\n", ret);
        printf("str = %s\n", str);
    }
}

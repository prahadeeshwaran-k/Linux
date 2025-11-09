#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int fd[2];
    pipe(fd);
    printf("fd[0]=%d fd[1]=%d\n", fd[0], fd[1]);
    if (fork() == 0)
    {
        char s1[20], s2[20];
        while (1)
        {
            read(fd[0], s1, sizeof(s1));
            printf("in child, reading the string : %s\n", s1);
            scanf("%s", s2);
            write(fd[1], s2, strlen(s2) + 1);
            sleep(1);
        }
    }
    else
    {
        char a[20], b[20];
        while (1)
        {
            printf("Enter the string in parent: ");
            scanf("%s", a);
            write(fd[1], a, strlen(a) + 1);
            sleep(1);
            read(fd[0], b, sizeof(b));
            printf("in parent, reading the string : %s\n", b);
        }
    }
}
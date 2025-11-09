/*
1. A pipe is a **unidirectional** data channel (one-way communication).

2. When a pipe is created, it gives **two file descriptors**:
    Fd[0] → used for reading
    Fd[1] → used for writing

3. A pipe is created in **kernel space**, but the processes using it run in **user space**.

4. Pipes allow communication only between **related processes**, such as a parent and its child process.

5. A process can get **blocked** in these situations:
       - When trying to read from an **empty pipe**
       - When trying to write to a **full pipe**

6. The default pipe buffer size in Linux is **64 KB (65,536 bytes)**.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int fd[2];
    pipe(fd); // it return 2 file descriptors read and write
    printf("fd[0]=%d fd[1]=%d\n", fd[0], fd[1]);
    
    if (fork() == 0)
    {
        char b[20];
        read(fd[0], b, sizeof(b));
        printf("in child reading the string : %s\n", b);
    }
    else
    {
        char a[20];
        printf("Enter the string in parent: ");
        scanf("%s", a); //here the basic linux File operarion are using.
        write(fd[1], a, strlen(a) + 1);
    }
}
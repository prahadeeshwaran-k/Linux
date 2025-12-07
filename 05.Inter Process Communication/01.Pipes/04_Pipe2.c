#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int count = 0;
    char ch = 'A';
    int fd[2];
    pipe2(fd, O_NONBLOCK);
    while (write(fd[1], &ch, 1) != -1)
        count++;

    printf("pipe size = %d\n", count);

    /*
    Without O_NONBLOCK (default)
    write() blocks (waits) when the pipe is full.
    The program freezes inside the loop and never exits.
    You will never reach printf and will not know the pipe size.

    With O_NONBLOCK
    write() returns -1 with errno = EAGAIN when the pipe is full.
    The loop stops.
    count will hold how many bytes were successfully written → effectively the pipe buffer size.
    */
}
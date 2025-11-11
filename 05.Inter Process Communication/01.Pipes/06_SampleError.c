#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>   // for srand(), rand()
#include <time.h>     // for time()
#include <fcntl.h>

int main()
{
    int p1[2];// !!note Important it create a 4 separate file descriptor 2 in  parent and 2 in child
    pid_t pid;
    // The problem is the code use the same pipe child to parent and parent to child.
    // solution is the we use 2 different pipes c -> p and p c -> c.

    if (pipe(p1) == -1)
    {
        perror("Pipe 1 creation failed");
        return 1;
    }

    pid = fork();

    if (pid == -1)
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0)
    {
        int x;
        read(p1[0], &x, sizeof(x));
        printf("Child process: Received %d\n", x);
        x *= 4;
        printf("Child process: Calculated %d\n", x);
        write(p1[1], &x, sizeof(x));
    }
    else
    {

        srand(time(NULL));
        int y = rand() % 10;
        printf("Parent process: Generated %d\n", y);
        write(p1[1], &y, sizeof(y));//problem it write and real immediately in the same execution 
        read(p1[0], &y, sizeof(y));//so the is no time to read by the child process 
        printf("Parent process: Result is %d\n", y);
        close(p1[0]);
    }

    return 0;
}

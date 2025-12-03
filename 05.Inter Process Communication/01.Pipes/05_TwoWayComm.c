#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>   // for srand(), rand()
#include <time.h>     // for time()
#include <fcntl.h>

int main()
{
    int p1[2];
    int p2[2];

    if (pipe(p1) == -1)
    {
        perror("Pipe 1 creation failed");
        return 1;
    }

    if (pipe(p2) == -1)
    {
        perror("Pipe 2 creation failed");
        return 1;
    }

    if (fork() == 0)
    {
        close(p2[1]);//not going to use, so closed pipes because of unidirection. 
        close(p1[0]);
        int x;
        read(p2[0], &x, sizeof(x));
        printf("Child process: Received %d\n", x);
        x *= 4;
        printf("Child process: Calculated %d\n", x);
        write(p1[1], &x, sizeof(x));
        close(p1[1]);
        close(p2[0]);
    }
    else
    {
        close(p2[0]);
        close(p1[1]);
        srand(time(NULL));
        int y = rand() % 10;
        printf("Parent process: Generated %d\n", y);
        write(p2[1], &y, sizeof(y));
        read(p1[0], &y, sizeof(y));
        printf("Parent process: Result is %d\n", y);
        close(p1[0]);
        close(p2[1]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void isr(int n)
{
    int st = 0;
    wait(&st);
    printf("st = %d\n", st);
    if (st == 0)
        printf("child is successful termination\n");
    else
    {
        printf("child is abnormal termination\n");
        printf("Your code should be here to repair\n");
    }
}

int main()
{
    if (fork() == 0)
    {
        printf("in child pid : %d\n", getpid());
        puts("child is running with 10 seconds delay\n");
        sleep(10);
        printf("child is exit..\n");
        exit(0);
    }
    else
    {
        puts("Parent process in infinite loop\n");
        signal(17, isr); // signal(SIGCHLD,isr);
        while (1){
            printf(".");
            fflush(stdout);
            sleep(1);
        }
    }
}


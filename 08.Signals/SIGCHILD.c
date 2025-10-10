#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void isr(int n)
{
    sleep(1);
    printf("\nin isr..., n = %d\n", n);
    printf("Parent process receives SIGCHLD signal\n");
}
int main()
{   
    //the child will become a zombie after it exits,
    //because the parent does not call wait() or waitpid() to collect its exit status
    if (fork() == 0)
    {
        printf("in child pid : %d\n", getpid());
        puts("child is running with 20 seconds delay\n");
        sleep(20);
        printf("child is exit..\n");
    }
    else
    {
        puts("Parent process in infinite loop\n");
        signal(17, isr);//SIGCHLD
        while (1)
            ;
    }
}
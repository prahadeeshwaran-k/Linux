#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void isr(int n)
{
    printf("in isr..\n");
}
/*
The flag SA_NOCLDWAIT is used with the sigaction() 
system call for the signal SIGCHLD (signal number 17).

It tells the kernel:
When any child terminates, don’t make it a zombie automatically clean it up (reap it).
*/

// SA_NOCLDSTOP | SA_NOCLDWAIT
/*
which tells the kernal to
*/
int main()
{
    if (fork() == 0)
    {
        printf("in child pid = %d\n", getpid());
        sleep(15);
        printf("child exit..\n");
    }
    else
    {
        struct sigaction v;
        v.sa_handler = isr;
        sigemptyset(&v.sa_mask);
        // v.sa_flags = 0;
        v.sa_flags = SA_NOCLDWAIT;
        sigaction(17, &v, 0);
        while (1)
            ;
    }
}

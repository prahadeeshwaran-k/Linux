#include <stdio.h>
#include <unistd.h>
#include <signal.h>
//if Flag is SA_NOCLDSTOP which means the ISR wont refuse suspended and resume but it only react terminated

/*the example shows how to configure sigaction so that a parent is only
interrupted for real child termination events, keeping it from reacting to temporary
stop/resume states.
*/

void isr(int n)
{
    printf("in isr..\n");
}

int main()
{
    if (fork() == 0)
    {
        printf("in child pid = %d\n", getpid());
        sleep(20);
        printf("child exit..\n");
    }
    else
    {
        struct sigaction v;
        v.sa_handler = isr;
        sigemptyset(&v.sa_mask);
        //v.sa_flags = 0;
        v.sa_flags = SA_NOCLDSTOP;
        sigaction(17, &v, 0);
        while (1)
            ;
    }
}


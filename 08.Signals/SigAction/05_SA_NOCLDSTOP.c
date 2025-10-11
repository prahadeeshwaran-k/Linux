#include <stdio.h>
#include <unistd.h>
#include <signal.h>
//if Flag is SA_NOCLDSTOP which means the ISR wont refuse suspended and resume but it only react terminated
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

/*
| Method                                      | Description             | Avoids Zombie?  |
| ------------------------------------------- | ----------------------- | --------------- |
| `wait()` or `waitpid()`                     | Manually reaps child    | ✅              |
| `signal(SIGCHLD, SIG_IGN)`                  | Ignores child status    | ✅              |
| `sigaction(SIGCHLD, handler, SA_NOCLDWAIT)` | Kernel auto-reaps child | ✅              |
*/
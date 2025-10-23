#include <stdio.h>
#include <unistd.h>
#include <signal.h>
/*
Runtime behavior

Program prints PID and “Infinite process…”.

When you hit Ctrl+C:

The handler runs: prints “In isr()…”, then does sleep(5), then prints “isr() is exit”.

During the handler, SIGQUIT is blocked (queued/deferred).

After the handler returns, the process goes back to the busy loop.

If you press *Ctrl+* during the 5-second handler sleep, SIGQUIT will be delivered after the handler returns (since you’ve masked it in sa_mask).
*/
void isr(int n)
{
    printf("In isr()...\n");
    sleep(5);
    printf("isr() is exit\n");
}
int main()
{
    struct sigaction v;
    v.sa_handler = isr;
    sigemptyset(&v.sa_mask);
    sigaddset(&v.sa_mask, 3);
    v.sa_flags = 0;
    sigaction(2, &v, 0);
    printf("Process ID: %d\n", getpid());
    printf("Infinite process...\n");
    while (1)
        ;
}
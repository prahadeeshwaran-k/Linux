#include <stdio.h>
#include <signal.h>
#include <unistd.h>
// SA_RESETHAND after it first execution it reset the Default argument.
void isr(int n)
{
    printf("in isr..\n");
    sleep(2);
}
int main()
{
    struct sigaction v;
    v.sa_handler = isr;
    sigemptyset(&v.sa_mask);
    v.sa_flags = 0;
    // v.sa_flags = SA_RESETHAND;
    sigaction(2, &v, 0);
    printf("Infinite process...\n");
    while (1)
        ;
}
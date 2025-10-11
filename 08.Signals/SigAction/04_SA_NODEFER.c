#include <stdio.h>
#include <signal.h>
#include <unistd.h>
//this is the isr each ISR is create a separate process
void isr(int n)
{
    printf("in isr()..., 5 seconds delay\n");
    sleep(5);
    printf("isr() is exit\n");
}

int main()
{
    struct sigaction v;
    v.sa_handler = isr;
    sigemptyset(&v.sa_mask);
    // v.sa_flags = 0;
    v.sa_flags = SA_NODEFER;
    sigaction(2, &v, 0);
    printf("Infinite process...\n");
    while (1)
        ;
}
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
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
#include <stdio.h>
#include <signal.h>
void isr(int)
{
    printf("In isr()...\n");
}
int main()
{
    //signal(2,SIG_DFL);
    signal(2,SIG_IGN);
    // signal(2,isr);
    void (*ptr)(int);
    // ptr = signal(2,SIG_DFL);
    ptr = signal(2, isr);
    if (ptr == SIG_DFL)
        printf("Default..\n");
    else if (ptr == SIG_IGN)
        printf("ignored..\n");
    else
        printf("Isr..\n");
}

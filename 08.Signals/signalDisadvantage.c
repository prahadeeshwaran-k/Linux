#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void isr(int)
{
    printf("In isr()...\n");
    sleep(5);//note if the we give the ctrl + c multiple time while in the sleep of isr it will never work
    printf("Out isr()...\n");
    printf("\n");
}
int main()
{
    //signal(2,SIG_DFL);
    signal(2,isr);

    while (1)
    {
        /* code */
    }
    
}

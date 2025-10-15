/*
    1) sigaction(num,&v,0)
        we are interested to set the new action of a signal but not interested to collect the old action.
    2) sigaction(num,0,&v)
        we are not  interested to set the new action but  interested to collect the old action.
    3) sigaction(num,&v1,&v2)
        we are  interested to set the new action and  collect the old action.
*/

// To change the action of a signal to isr using sigaction
#include <stdio.h>
#include <signal.h>

void isr(int n)
{
    printf("in isr..\n");
}
/*
struct sigaction {
    void     (*sa_handler)(int); //*This is a pointer to a simple signal-handling function.AKA user define ISR
    void     (*sa_sigaction)(int, siginfo_t *, void *); //*it provides extra information about the signal via a siginfo_t structure(advanced)
    sigset_t   sa_mask; //*Defines a set of signals to block during the execution of the handler.
    int        sa_flags; //*Controls how the signal is handled
    void     (*sa_restorer)(void); //*Rarely used, reserved for system’s internal use
};*/

int main()
{
    struct sigaction var;
    var.sa_handler = isr; 
    sigemptyset(&var.sa_mask); // Start with empty set
    var.sa_flags = 0;   
    sigaction(2, &var, 0);
    printf("Infinite process...\n");
    while (1)
        ;
}

/*
sigemptyset() note:So, by itself, it does nothing to the system or process —
it just prepares a signal set variable for later use.
*/
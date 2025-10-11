#include <stdio.h>
#include <unistd.h>
#include <signal.h>
/*
| Situation                   | What happens                                                        |
| --------------------------- | ------------------------------------------------------------------- |
| You press `Ctrl+C` (SIGINT) | `isr()` runs                                                        |
| While in `isr()`            | All signals except 3 (SIGQUIT) and 11 (SIGSEGV) are **blocked**     |
| After `isr()` exits         | The signal mask is automatically **restored** to normal (unblocked) |

Conclusion

During ISR: all signals blocked except 3 & 11
After ISR: signal mask restored, everything unblocked
*/
void isr(int n)
{
    printf("In isr()...\n");
    sleep(10);
    printf("isr() is exit\n");
}
int main()
{
    struct sigaction v;
    v.sa_handler = isr;
    sigfillset(&v.sa_mask);
    sigdelset(&v.sa_mask, 3);
    sigdelset(&v.sa_mask, 11);
    v.sa_flags = 0;
    sigaction(2, &v, 0);
    printf("Infinite process..., pid : %d\n", getpid());
    while (1)
        ;
}

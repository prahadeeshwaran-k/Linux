#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ISR(int signalNo) {
        printf("SIGINT default restored\n");
        signal(SIGINT, SIG_DFL);

        printf("SIGQUIT default restored\n");
        signal(SIGQUIT, SIG_DFL);
}

int main() {
    printf("Program Started\n");
    printf("PID: %d\n", getpid());

    printf("SIGINT Ignored\n");
    signal(SIGINT, SIG_IGN);
    printf("SIGQUIT Ignored\n");
    signal(SIGQUIT, SIG_IGN);

    signal(SIGALRM, ISR);
    alarm(10);
    for(int i = 0 ; i<10 ; i++){
        printf("T-%d\n",10-i);
        sleep(1);
    }

    while(1);
}
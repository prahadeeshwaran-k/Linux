#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ISR(int signalNo) {
    static int count1 = 0, count2 = 0;

    if(signalNo == SIGINT) { // Ctrl+C
        count1++;
    }
    if(signalNo == SIGQUIT) { // <Ctrl+\>
        count2++;
    }
    if(count1 >= 3) {
        printf("SIGINT default restored\n");
        signal(SIGINT, SIG_DFL);
    }
    if(count2 >= 4) {
        printf("SIGQUIT default restored\n");
        signal(SIGQUIT, SIG_DFL);
    }
}

int main() {
    printf("Program Started\n");
    printf("PID: %d\n", getpid());

    signal(SIGINT, ISR);
    signal(SIGQUIT, ISR);

    while(1) pause(); // Wait for signals
}


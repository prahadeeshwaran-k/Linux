#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main(){
    int i = 1;
    printf("alarm\n");

    i = alarm(10);
    printf("Return Value of Alarm(10): %d\n",i);

    sleep(3);
    i = alarm(4);
    printf("Return Value of Alarm(4): %d\n",i);

    i = alarm(0);
    printf("Return Value of Alarm(0): %d\n",i);
}
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main(){
    int i = 1;
    printf("alarm in 5 Seconds\n");

    alarm(5);
    printf("Hello...\n");
}
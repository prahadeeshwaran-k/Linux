#include <stdio.h>
#include<unistd.h>
int main(){
    printf("PID: %d | PPID: %d\n",getpid(),getppid());
    while(1){
        printf(".");
        fflush(stdout);
        sleep(2);
    }
}

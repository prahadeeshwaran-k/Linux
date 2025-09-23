#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    printf("THE NEW PROCESS\n");
    printf("PID: %d | PPID: %d\n",getpid(),getppid());
    return(0);
}
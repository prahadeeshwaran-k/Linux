// JOB CONCURRENCY
// Created by prahadeeshwaran on 9/21/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DELAY 60
int main() {
    int pid;
    if ((pid=fork()) == 0) {
        printf("Child Process\n");
        printf("Child PID: %d | PPID: %d\n",getpid(),getppid());
        for(int i = 0 ; i<DELAY ; i++){
            printf("T - %d\n",DELAY - i);
            sleep(1);
        }
        exit(0);
    }
    else{
        int status;
        printf("Parent Process :Wait for Child Process Finish\n");
        waitpid(pid,&status,WUNTRACED);
        if(status == 0){
            printf("Child is successful Termination\n");
        }else{
            printf("Child is Suspended or force Termination\n");
        }
        printf("Parent Process is finished\n");
    }
}

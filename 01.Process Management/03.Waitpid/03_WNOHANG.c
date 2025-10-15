//
// Created by prahadeeshwaran on 9/21/25.
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    //Child 1
    if(fork() ==0){
        printf("in child process\n");
        for(int i = 0; i<5 ; i++){
            printf("T-%d\n",5-i);
            sleep(1);
        }
        printf("child is ended\n");
    }
    //child 2
    else if(fork() ==0){
            printf("in child process\n");
            for(int i = 0; i<5 ; i++){
                printf("T-%d\n",5-i);
                sleep(1);
            }
            printf("child is ended\n");
    }
    else{
        int status;
        printf("in parent Process\n");
        waitpid(-1,&status,WNOHANG);
        printf("parent is ended\n");
        //After this Child Will Be Orphan Process
    }
}
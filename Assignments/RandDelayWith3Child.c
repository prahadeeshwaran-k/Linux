/*WAP to create 3 child process from the same parent. 
Use the rand() function to generate the delay between 1 to 10sec. 
Design a parent process in such a way that it should wait for 
all child process termination and display which process is completed in the order.*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX 10
#define MIX 1
#define DELAY rand()%(MAX - MIX + 1) +1

int main(){
    srand(getpid());
    int cPID[3];
    int Delay[3];
    for(int i = 0;i<3;i++){
        Delay[i] = DELAY;
    }
    int status;

    if((cPID[0] = fork())==0){
        printf("CHILD - 1 : %d Created & Delay of %d Sec\n",getpid(),Delay[0]);
        sleep(Delay[0]);
        printf("CHILD - 1 : %d Completed\n",getpid());
        exit(0);
    }
    else if((cPID[1] = fork())==0){
        printf("CHILD - 2 : %d Created & Delay of %d Sec\n",getpid(),Delay[1]);
        sleep(Delay[1]);
        printf("CHILD - 2 : %d Completed\n",getpid());
        exit(0);
    }
    else if((cPID[2] = fork())==0){
        printf("CHILD - 3 : %d Created & Delay of %d Sec\n",getpid(),Delay[2]);
        sleep(Delay[2]);
        printf("CHILD - 3 : %d Completed\n",getpid());
        exit(0);
    }
    else
    {
        printf("Waiting for all childs finish the process\n");
        while (wait(&status) != -1);

        for (int i = 0; i < 3; i++)
            printf("CHILD ID :%d\n",cPID[i]);
        
    }
    

}
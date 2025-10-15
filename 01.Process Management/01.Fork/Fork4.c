#include<stdio.h>
#include<unistd.h>

//in this code all the process is  running in the background;
//note (2^i);

int main(){
    printf("The Main Process\n");
    printf("Parent| PID = %d | PPID = %d\n",getpid(),getppid());    

    for(int i = 0;i<4;i++){
        if(fork() == 0)
            printf("i = %d | PID = %d | PPID = %d\n",i,getpid(),getppid());    
    }
    while (1);
}
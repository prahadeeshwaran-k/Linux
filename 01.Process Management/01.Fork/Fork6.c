#include<stdio.h>
#include<unistd.h>
// Single parent with multiple children
// Break the loop at parent code resulting single child for each parent.

int main(){
    printf("The Main Process\n");
    printf("Parent| PID = %d | PPID = %d\n",getpid(),getppid());    

    for(int i = 0;i<4;i++){
        if(fork() == 0){
            printf("i = %d | PID = %d | PPID = %d\n",i,getpid(),getppid());
            break;
            return 0;
        }
    }
    while (1);
}
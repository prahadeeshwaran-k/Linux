#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){

        if(fork()==0){
                printf("Child - Process\n");
                printf("Child:PID =  %d | Parent:PID = %d\n",getpid(),getppid());
                for(int i = 0; i<10;i++){
                    printf("T-%d\n",10-i);
                    sleep(1);
                }
		exit(0);
        }
	else{
	    int status;
            printf("waiting for parent process: \n");
            wait(&status);
	    if(status>>8 == 0){
	    	printf("child process successful termination\n");
	    }else{
	    	printf("child can't finish the process\n");
	    }
	    printf("Parent:PID = %d | Parent:PPID = %d\n",getpid(),getppid());
            for(int i = 0; i<5;i++){
                printf("T-%d\n",5-i);
            	sleep(1);
            }
	    printf("bye bye bye...\n");
	}
}


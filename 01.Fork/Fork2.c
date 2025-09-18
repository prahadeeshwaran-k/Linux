//print 0 to 5 in child process
//print 6 to 10 in main process

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){
    int id = fork();
    int n = 0;

    if(id == 0){// if id == 0 in child process
        n = 1;
    }else{
        n = 6;
    }

    if(id != 0){
        wait();
    }

    for (int i = n; i < n + 5 ; i++)
    {
        printf("%d ",i);
        fflush(stdout);
    }
    
    if(id != 0){
    printf("\n");
    }
    return 0;
    
}
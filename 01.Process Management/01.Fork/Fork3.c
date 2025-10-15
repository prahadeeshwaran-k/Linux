#include<stdio.h>
#include<unistd.h>

int main(){
    //From the parent process.
    //but in child the stdout also copy.
    
    printf("Hello...");
    if(fork() == 0)
        printf("From Child..."); 
    else
        printf("From Parent...");
    printf("Both...\n");
}
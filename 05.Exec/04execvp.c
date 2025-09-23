#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//The  exec() family of functions replaces the current process image with a new process image.
int main()
{
	printf("The first Process\n");
    printf("PID: %d | PPID: %d\n",getpid(),getppid());
    // The first ./Main tells the operating system where to find and load the executable file.
    // The second ./Main is the name of the program as it will be seen by the new process. 
    char *ap[] = {"ping","google.com",NULL};
    execvp("ping", ap);
	printf("In old Process Not Going to Execute.\n");
}
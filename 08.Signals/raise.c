#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main(){
    printf("hello... PID: %d\n",getpid());
    sleep(10);
    raise(SIGSEGV);
}
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    if(argc!=3)
    {
         printf("./kill sig_num PID\n");
         return 0;
     }
     if(kill(atoi(argv[2]),atoi(argv[1]))<0)
     perror("Kill");
}

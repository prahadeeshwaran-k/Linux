#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    int fd[2];
    int num;
    if(pipe(fd) == -1){
        printf("Error Opening The Pipe\n");
        return 0;
    }

    printf("Read: fd[0] = %d\nWrite: fd[1] = %d\n",fd[0],fd[1]);
    
    if(fork() == 0){
        //printf("The Child Process %d\n",getpid());
        int data;
        read(fd[0], &data, sizeof(int));
        printf("Output: %d\nInput: ",data);
        scanf("%d",&data);
        write(fd[1], &data, sizeof(int));

    }else{
        //printf("The Parent Process %d\n",getpid());
        printf("Input: ");
        scanf("%d",&num);
        write(fd[1], &num, sizeof(int));
        usleep(200);//with out sleep the below read() get the information on the same parent
        read(fd[0], &num, sizeof(int));
        printf("Output: %d\n",num);
    }
}
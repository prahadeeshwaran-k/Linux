#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define SIZE 256
char buffer[SIZE]  = {0};
char *shmptr = NULL;
int main(){

    int fd_shm =  shm_open("/shmspace", O_RDONLY, 0666);
    if(fd_shm == -1){
        perror("shm_open");
        exit(0);
    }

    shmptr= mmap(NULL, SIZE, PROT_READ, MAP_SHARED, fd_shm, 0);
    if( (shmptr = (char*)mmap(NULL,SIZE,PROT_READ | PROT_WRITE,MAP_SHARED,fd_shm,0)) == NULL){
        perror("mmap");
        exit(0);
    }

    while (1)
    {   
        scanf("%s",buffer);
        printf("Received Buffer: %s\n", shmptr);
    }
    
}

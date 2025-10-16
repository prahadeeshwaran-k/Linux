//write a program to know is the given files are linked or not b/w two files and what type of link
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char*argv[]){
    struct stat data1;
    struct stat data2;

    stat(argv[1],&data1);
    stat(argv[2],&data2);

    if(data1.st_ino != data2.st_ino){
        printf("No Link is Made Between %s and %s\n",argv[1],argv[2]);
    }

    if(data1.st_blocks == data2.st_blocks){
        printf("Hardlink: Based on Block Size\n");
    }else{
        printf("SoftLink: Based on Block Size\n");
    }

}
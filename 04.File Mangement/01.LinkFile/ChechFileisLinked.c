//write a program to know is the given files are linked or not b/w two files and what type of link
//./ChechFileisLinked HardLink/Original.txt HardLink/HardLink.txt
//./ChechFileisLinked SoftLink/Original.txt SoftLink/SoftLink.txt
//./ChechFileisLinked NoLink/Original.txt NoLink/data.txt

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char*argv[]){

    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    struct stat data1;
    struct stat data2;

    stat(argv[1],&data1);
    stat(argv[2],&data2);

    if(data1.st_ino != data2.st_ino){
        printf("No Link is Made Between %s and %s\n",argv[1],argv[2]);
        return 0;
    }

    struct stat data1_ls;
    struct stat data2_ls;

    lstat(argv[1],&data1_ls);
    lstat(argv[2],&data2_ls);

    if(data1_ls.st_ino == data2_ls.st_ino ){
        printf("\nHardlink: Based on Inode Size\n");
    }
    else if(data1_ls.st_ino != data2_ls.st_ino){
        printf("SoftLink: Based on Inode Size\n");
    }
    
    printf("Inode NUmber: %lu %lu\n\n",data1_ls.st_ino,data2_ls.st_ino);


    if(data1_ls.st_blocks == data2_ls.st_blocks){
        printf("Hardlink: Based on Block Size\n");
    }else if(data1_ls.st_blocks != data2_ls.st_blocks){
        printf("SoftLink: Based on Block Size\n");
    }

    printf("Block Size: %lu %lu\n",data1_ls.st_blocks,data2_ls.st_blocks);

}
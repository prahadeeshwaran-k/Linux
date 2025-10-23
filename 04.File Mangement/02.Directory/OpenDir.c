#include<stdio.h>
#include<dirent.h>
int main(int argc,char*argv[])
{
        if(argc != 2) {
        printf("Usage : ./OpenDir file\n");
        return 0;
        }

        DIR *dp;
        dp = opendir(argv[1]);

}
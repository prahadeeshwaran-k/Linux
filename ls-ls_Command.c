#include <stdio.h>
#include <dirent.h>

int main(int char, char*argv[]){
    if(argv != 2){
        printf("use: ./ls <FILE>\n");
        return 0;
    }
    DIR *dp;
    struct dirent*p;
    dp = opendir(argv[1]);
    
    if(dp = NULL){
        printf("NO DIRECTORY");
        return 0;
    }

    while (p = readdir(dp))
    {
        printf("%ld\t%ld\t%ld\t%ld\n");
    }
    
    
}
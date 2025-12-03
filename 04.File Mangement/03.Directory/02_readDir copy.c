#include <stdio.h>
#include <dirent.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./a.out file\n");
        return 0;
    }
    DIR *dp;
    struct dirent *p;
    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("opendir");
        return 0;
    }
    while (p = readdir(dp))
    {
        printf("%s \n", p->d_name);
        // printf("p->d_ino : %ld\n",p->d_ino);
        // printf("p->d_off : %ld\n",p->d_off);
        // printf("p->d_reclen : %ld\n",p->d_reclen);
    }
    printf("\n");
}
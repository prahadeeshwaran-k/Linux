#include <stdio.h>
#include <dirent.h>
int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                printf("Usage : ./a.out file\n");
                return 0;
        }

        DIR *dp;//This is the data type of directory stream objects.The actual structure is opaque to user.
        struct dirent *p;
        dp = opendir(argv[1]);
        if (dp == NULL)
        {
                printf("opendir");
                return 0;
        }
        while(p = readdir(dp))
                printf("%s \n", p->d_name);
        printf("\n");
}

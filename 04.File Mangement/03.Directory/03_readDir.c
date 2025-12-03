#include <stdio.h>
#include <dirent.h>
#include <string.h>

void Filepath(const char *dir)
{
    DIR *dp;
    struct dirent *p;
    dp = opendir(dir);

    if (dp == NULL)
        return;
    
    while ((p = readdir(dp)) != NULL)
    {
        // skip "." and ".." to avoid infinite recursion
        if (strcmp(p->d_name, ".") == 0 || strcmp(p->d_name, "..") == 0)
            continue;

        printf("%s \n", p->d_name);
        if (p->d_type == 4) { // d_type = 4 means it is a directory
            char path[256] = {0};
            strcat(path, dir);
            strcat(path, "/");
            strcat(path, p->d_name);
            Filepath(path);
        }
    }
    closedir(dp);
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./a.out file\n");
        return 0;
    }
    Filepath(argv[1]);
}
    
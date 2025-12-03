#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./a.out file\n");
        return 0;
    }
    struct stat v;
    if (stat(argv[1], &v) < 0)
    {
        perror("stat");
        return 0;
    }
    struct passwd *p1 = getpwuid(v.st_uid);
    struct group *p2 = getgrgid(v.st_gid);

    printf("v.st_mode   = %o\n", v.st_mode);
    printf("v.st_nlink  = %ld\n", v.st_nlink);
    printf("User name   = %s\n", p1->pw_name);
    printf("group name  = %s\n", p2->gr_name);
    printf("v.st_size   = %ld\n", v.st_size);
    printf("modify time = %s\n", ctime(&v.st_mtime));
}
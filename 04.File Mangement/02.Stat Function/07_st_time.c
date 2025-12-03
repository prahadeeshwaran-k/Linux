#include <stdio.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <time.h>
int main(int argc, char *argv[])
{
   struct stat v;
   if (argc != 2)
   {
      printf("./a.out filename..\n");
      return 0;
   }
   stat(argv[1], &v);
   printf("atime = %lu\n", v.st_atime);
   printf("mtime = %lu\n", v.st_mtime);
   printf("ctime = %lu\n", v.st_ctime);

   printf("atime = %s\n", ctime(&v.st_atime));
   printf("mtime = %s\n", ctime(&v.st_mtime));
   printf("ctime = %s\n", ctime(&v.st_ctime));
}


// struct stat
// {
//       dev_t st_dev;         /* ID of device containing file */
//       ino_t st_ino;         /* inode number */
//       mode_t st_mode;       /* protection */
//       nlink_t st_nlink;     /* number of hard links */
//       uid_t st_uid;         /* user ID of owner */
//       gid_t st_gid;         /* group ID of owner */
//       dev_t st_rdev;        /* device ID (if special file) */
//       off_t st_size;        /* total size, in bytes */
//       blksize_t st_blksize; /* blocksize for filesystem I/O */
//       blkcnt_t st_blocks;   /* number of 512B blocks allocated */
// };

// struct timespec st_atim;  /* time of last access */
// struct timespec st_mtim;    /* time of last modification */
// struct timespec st_ctim;    /* time of last status change */
// st_atime - is changed by file accesses.st_mtime - is changed by file modifications
// st_ctime - is changed by writing or by setting inode information

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
      struct stat v;
      if (argc != 2)
      {
            printf("use: ./ a.out <file name>\n");
            return 0;
      }
      if (stat(argv[1], &v) < 0)
      {
            perror("stat");
            return 0;
      }
      printf("v.st_size  : %ld\n", v.st_size);   // size of file content
      printf("v.st_ino   : %ld\n", v.st_ino);     // inode number
      printf("v.st_mode  : %o\n", v.st_mode);   // protection
      printf("v.st_nlink : %ld\n", v.st_nlink);  //  by Default nlink is 1 because of one hard link ,number of hard links
      printf("v.st_blocks: %ld\n", v.st_blocks);// number of 512B blocks allocated
      //Note:
      //In $stat command : 1 block 1024 bytes = size = (number blocks)*1024
      //In stat() function : 1 block 512 bytes = size = (number blocks)*512
}
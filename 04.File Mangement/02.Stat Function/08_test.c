/*
regular file : 100000
directory file : 40000
blockdevice file : 60000
chardevice file : 20000
fifo special file : 10000
link file : 120000
socket file : 140000
*/
#include<stdio.h>
#include<sys/stat.h>
int main()
{
	printf("regular file : %o\n",S_IFREG);
	printf("directory file : %o\n",S_IFDIR);
	printf("blockdevice file : %o\n",S_IFBLK);
	printf("chardevice file : %o\n",S_IFCHR);
	printf("fifo special file : %o\n",S_IFIFO);
	printf("link file : %o\n",S_IFLNK);
	printf("socket file : %o\n",S_IFSOCK);
}

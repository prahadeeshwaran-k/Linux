#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("Usage : ./a.out file1 file2\n");
		return 0;
	}
	struct stat v1,v2;
	if(stat(argv[1],&v1) < 0)
	{
		perror("stat");
		return 0;
	}
	if(stat(argv[2],&v2) < 0)
	{
		perror("stat");
		return 0;
	}
	if(v1.st_ino == v2.st_ino)
	{
		lstat(argv[1],&v1);
		lstat(argv[2],&v2);
		if(v1.st_ino == v2.st_ino)
		printf("Hard Link...\n");
		else
		printf("Soft Link...\n");
	}
	else
	printf("No link...\n");
}

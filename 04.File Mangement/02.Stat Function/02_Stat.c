#include<stdio.h>
#include<sys/stat.h>
int main()
{
	struct stat v1,v2,v3;
	stat("file.txt",&v1);
	stat("file1.txt",&v2);
      
	printf("v1.st_ino = %ld\n",v1.st_ino);
	printf("v2.st_ino = %ld\n",v2.st_ino);
}
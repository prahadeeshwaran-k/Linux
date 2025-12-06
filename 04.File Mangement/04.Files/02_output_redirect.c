#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{	
	// stdin  -> 0
	// stdout -> 1
	// stderr -> 2
	close(1);
	int fd = open("data.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	printf("Embedded Systems\n");
	printf("Vector India\n");
	printf("fd = %d\n",fd);
}

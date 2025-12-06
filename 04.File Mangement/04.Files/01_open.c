#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("temp", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
	{
		printf("fd = %d\n", fd);
		perror("open");
	}
	printf("fd = %d\n", fd);
	close(fd);
}

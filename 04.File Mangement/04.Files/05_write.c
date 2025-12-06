#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd = open("data.c",O_WRONLY|O_TRUNC|O_CREAT,0664);
	if(fd < 0) {
	perror("open");
	return 0;
	}
	
	char ch = 'A';
	int x = 1234;
	float f = 22.7;
	char s[20] = "Vector";

	write(fd,&ch,sizeof(char));
	write(fd,&x,sizeof(int));
	write(fd,&f,sizeof(float));
	write(fd,s,strlen(s)+1);

	close(fd);
}

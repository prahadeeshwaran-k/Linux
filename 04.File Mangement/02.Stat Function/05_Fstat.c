#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	//fstat is a system call in Linux/Unix that retrieves information about an open file.
	int i,fd = open("sample",O_RDONLY);

	if(fd < 0) {
	perror("open");
	return 0;
	}
	char ch;
	struct stat v;
	//normal stat("file.txt", &buf) input->File name
	fstat(fd,&v);//same like stat but it we passed a File descriptor given by the open 
	printf("v.st_size = %ld\n",v.st_size);

	for(i=0;i<v.st_size;i++)
	{
		read(fd,&ch,1);
		putchar(ch);
	}
	close(fd);
}

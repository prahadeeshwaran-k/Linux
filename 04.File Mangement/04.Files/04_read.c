#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd = open("data.c",O_RDONLY,0664);
	if(fd < 0) {
	perror("open");
	return 0;
	}
	
	char ch;
	int x;
	float f;
	char s[20];

	read(fd,&ch,sizeof(char));
	read(fd,&x,sizeof(int));
	read(fd,&f,sizeof(float));
	read(fd,s,sizeof(s));

	close(fd);

	printf("ch = %c\n",ch);
	printf("x = %d\n",x);
	printf("f = %f\n",f);
	printf("s = %s\n",s);
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	char ch;
	int x;
	float f;
	char s[20];
	printf("Enter the char,int,float & string\n");
	close(0);
	int fd = open("sample", O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd < 0)
	{
		perror("open");
		return 0;
	}
	scanf("%c%d%f%s", &ch, &x, &f, s);
	printf("ch = %c x = %d f = %f s = %s\n", ch, x, f, s);
}

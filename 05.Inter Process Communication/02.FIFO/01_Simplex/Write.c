#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
     int fd;   char str[20];
     mkfifo("fifo",0664);
     perror("mkfifo");
     printf("hi..\n");
     fd = open("fifo",O_WRONLY);
     if(fd < 0)  {
     perror("open");
     return 0;
     }
     while(1)
     {
          printf("Enter the string : ");
          scanf("%s",str);
          write(fd,str,strlen(str)+1);
     }
}
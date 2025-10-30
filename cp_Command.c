#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>

int main(int argc,char* argv[]){
	int fd = open(argv[1],O_RDONLY);
	
	if(fd<0){
		perror("OPEN");
		return 0;
	}

	struct stat var;
	fstat(fd,&var);
	printf("Size of %s file = %ld\n",argv[1],var.st_size);
	char*buffer = (char*)malloc(sizeof(char)*var.st_size);
	for(int i = 0; i<var.st_size;i++){
		read(fd, &buffer[i], 1);
	}

	int fdcp = open(argv[2],O_WRONLY|O_CREAT|O_APPEND,0664);
	for(int i = 0; i<var.st_size;i++){
                write(fdcp, &buffer[i], 1);
        }

}
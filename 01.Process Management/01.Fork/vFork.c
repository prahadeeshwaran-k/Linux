#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int val = 10;
	printf("in Parent val = %d\n",val);
	if(vfork()==0){
        val = 96;               // modifies stack variable shared with parent
        printf("in Child val = %d\n",val);
        sleep(5);               // child is holding parent suspended
		printf("child is exit..\n");
		exit(0);   // must be _exit , not exit. a classic trap with vfork()
	}
	else
	{
		int stat;
		printf("in Parent val = %d\n",val);
		printf("in parent, 3 seconds delay ,PID: %d\n",getpid());
		sleep(2);
		printf("parent is exit..\n");
		exit(0);
	}
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s <SIGNALNUM> <PID>\n", argv[0]);
		return 1;
	}
	int sig = atoi(argv[1]);
	pid_t pid = atoi(argv[2]);

	if (sig <= 0 || sig > 64)
	{
		fprintf(stderr, "Invalid signal number: %d\n", sig);
		return 1;
	}

	int val = kill(pid, sig);
	if (val == -1)
	{
		perror("kill -1");
	}
	else
	{
		if (val == 0)
			printf("Sent signal %d to process %d successfully.\n", sig, pid);
		else
		{
			if (errno == EPERM)
				printf("Process exist, No Permission to sent signal\n");
			else if (errno == ESRCH)
				printf("Process does not exist\n");
			else
				perror("kill r0");
		}
	}

	return 0;
}

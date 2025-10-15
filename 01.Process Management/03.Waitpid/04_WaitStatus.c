#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status, result;
    pid_t child_pid;

    printf("Parent PID: %d\n", getpid());

    child_pid = fork();

    if (child_pid == 0)
    {
        // --- Child Process ---
        printf("Child PID: %d\n", getpid());
        sleep(20);
        exit(0);
    }
    else
    {
        // --- Parent Process ---
        while (1)
        {
            result = waitpid(child_pid, &status, WNOHANG | WUNTRACED | WCONTINUED);

            if (result == -1)
            {
                perror("waitpid");
                break;
            }

            if (result == 0)
            {
                // child still running
                sleep(1);
                continue;
            }

            // child changed state
            if (WIFEXITED(status))
                printf("Normal Termination with Exit Status %d\n", WEXITSTATUS(status));
            else if (WIFSIGNALED(status))
                printf("Signal Termination by Signal %d\n", WTERMSIG(status));
            else if (WIFSTOPPED(status))
                printf("Stopped by Signal %d\n", WSTOPSIG(status));
            else if (WIFCONTINUED(status))
                printf("Continued after Signal SIGCONT\n");

            sleep(5);
        }

        printf("Parent exiting...\n");
    }

    return 0;
}

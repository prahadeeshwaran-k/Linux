#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
  if (fork() == 0)
  {
    printf("child pid : %d\n", getpid());
    printf("in child, 10seconds delay\n");
    sleep(20);
    printf("child is exit..\n");
    exit(0);
  }
  else
  {
    int stat;
    // waitpid(-1,&stat,0);
    waitpid(-1, &stat, 0);                  // parent is blocked untill child is
    printf("in parent, stat = %d\n", stat); // suspend or terminate.
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define DELAY 20
int main() {
  if (fork() == 0) {
    printf("child pid : %d\n", getpid());
    printf("in child, 10seconds delay\n");
    for(int i = 0 ; i<DELAY ; i++){
        printf("T - %d\n",DELAY - i);
        sleep(1);
    }

    printf("child is exit..\n");
    exit(0);
  } else {
    int status;
    waitpid(-1, &status, WCONTINUED); // parent is blocked untill, child is
    // if chiled suspended dont execute the next line in parent wait if child resume then move down
    // and child will contuine the task in some other process
    printf("in parent, stat = %d\n", status); // resume from suspend or terminate.
  }
}

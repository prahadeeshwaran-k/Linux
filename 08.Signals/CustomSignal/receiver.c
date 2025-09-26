#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function
void handle_sigusr1(int sig) {
    printf("\n[Receiver] Got SIGUSR1! Performing custom action...\n");
    fflush(stdout);
}

int main() {
    // Print the process id
    printf("Process ID: %d\n", getpid());

    // Register signal handler for SIGUSR1
    signal(SIGUSR1, handle_sigusr1);

    const char* message = "Hello World";

        // Message printing loop
        while (1) {
            printf("\r              ");
            printf("\r%s", message);
            fflush(stdout);
            sleep(1);
            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                sleep(1);
            }
        }

    return 0;
}

#include <stdio.h>    // For printf and fflush
#include <signal.h>   // For signal handling (signal, SIGTSTP)
#include <unistd.h>   // For pause

/**
 * @brief Signal handler function for SIGTSTP (Ctrl+Z).
 * * This function is called when the process receives the SIGTSTP signal.
 * It prints a message and re-registers itself to handle future SIGTSTP signals.
 * * @param sig_num The signal number that was caught (will be SIGTSTP).
 */
void handle_sigtstp(int sig_num) {
    // Note: printf is not strictly async-signal-safe,
    // but it's commonly used in simple examples.
    // write() would be safer, but more complex.
    printf("\nCaught Ctrl+Z (SIGTSTP)! Not stopping. %d\n",sig_num);
    
    // Flush stdout to ensure the message is printed immediately,
    // as printf is bufferend.
    fflush(stdout);

    // Re-register the signal handler.
    // On some older systems, the signal handler is reset to default
    // after being called once. This line ensures it remains active.
    signal(SIGTSTP, handle_sigtstp);
}

int main() {
    // Register the handle_sigtstp function as the handler for SIGTSTP.
    // signal() returns SIG_ERR on failure.
    if (signal(SIGTSTP, handle_sigtstp) == SIG_ERR) {
        perror("Failed to register SIGTSTP handler");
        return 1;
    }

    printf("Program is running. Press Ctrl+Z to test.\n");
    printf("Press Ctrl+C (SIGINT) to quit.\n");

    // Use an infinite loop with pause() to wait for signals.
    // pause() causes the process to sleep until a signal is delivered
    // whose action is to terminate the process or call a handler.
    while (1) {
        pause();
    }

    // This part is unreachable
    return 0;
}
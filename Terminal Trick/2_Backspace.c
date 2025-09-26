#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *msg = "Temporary Text";
    printf("%s", msg);
    fflush(stdout);
    sleep(2);

    // Erase character by character
    for (int i = 0; i < strlen(msg); i++) {
        printf("\b \b");  // backspace, print space, backspace again
        fflush(stdout);
        usleep(100000);  // animation effect
    }

    printf("Replaced!\n");
    return 0;
}

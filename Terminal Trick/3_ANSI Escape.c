#include <stdio.h>
#include <unistd.h>

int main() {
    printf("This will vanish in 2s...");
    fflush(stdout);
    sleep(2);

    // Move cursor to beginning of line and clear it
    printf("\33[2K\r");  
    fflush(stdout);

    printf("Now replaced text!\n");
    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Hello World!");
    fflush(stdout);
    sleep(2);

    // Move cursor to beginning of line and overwrite with spaces
    printf("\r            \r");  // same number of spaces as characters
    fflush(stdout);

    sleep(1);
    printf("New Text!\n");
    return 0;
}


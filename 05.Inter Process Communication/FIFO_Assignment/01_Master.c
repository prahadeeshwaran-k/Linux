#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Process 1\n\n");

    char file[25];
    char target, replace;
    char name[50] = "cat ";

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(file, argv[1]);

    // Create FIFO
    if (mkfifo("FIFO", 0664) == -1)
        perror("mkfifo");

    // Open FIFO for writing
    int FD = open("FIFO", O_WRONLY);
    if (FD < 0) {
        perror("open FIFO");
        return 1;
    }

    write(FD, file, strlen(file) + 1);

    strncat(name, argv[1], strlen(argv[1]));
    system(name);

    printf("\nEnter The Target letter: ");
    scanf(" %c", &target);
    write(FD, &target, sizeof(char));

    printf("Enter The Replace letter: ");
    scanf(" %c", &replace);
    write(FD, &replace, sizeof(char));

    close(FD);

    printf("\nAfter replacement:\n");
    system(name); 
    return 0;
}

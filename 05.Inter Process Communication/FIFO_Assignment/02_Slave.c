#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{   
    printf("Process 2\n");

    char file[25];
    char target, replace, ch;

    // Create FIFO if not exists
    if (mkfifo("FIFO", 0664) == -1)
        perror("mkfifo");

    // Open FIFO for reading
    int FD = open("FIFO", O_RDONLY);
    if (FD < 0) {
        perror("open FIFO");
        return 1;
    }

    // Read file name and chars
    read(FD, file, sizeof(file));
    printf("File Name: %s\n", file);
    read(FD, &target, sizeof(char));
    printf("Target:  %c\n", target);
    read(FD, &replace, sizeof(char));
    printf("Replace: %c\n\n", replace);
    close(FD);

    // Open the actual text file
    int FileFD = open(file, O_RDWR);
    if (FileFD < 0) {
        perror("open file");
        return 1;
    }

    // Replace all occurrences
    while (read(FileFD, &ch, sizeof(char)) > 0) {
        if (ch == target) {
            lseek(FileFD, -1, SEEK_CUR);
            write(FileFD, &replace, sizeof(char));
        }
    }

    close(FileFD);
    printf("Completed\n");
    return 0;
}

/*
 * client.c : Simplex POSIX shared memory writer
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>

#define SHM_NAME "/simplex_shm"
#define SEM_NAME "/simplex_sem"

struct shared_memory {
    char message[256];
};

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    int shm_fd;
    struct shared_memory *shm;
    sem_t *sem;
    char buf[256];

    shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
    if (shm_fd == -1) error("shm_open");

    shm = mmap(NULL, sizeof(*shm),
               PROT_READ | PROT_WRITE,
               MAP_SHARED, shm_fd, 0);
    if (shm == MAP_FAILED) error("mmap");

    sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) error("sem_open");

    while (1) {
        printf("Enter message: ");
        fgets(buf, sizeof(buf), stdin);

        buf[strcspn(buf, "\n")] = 0;     // remove newline
        strcpy(shm->message, buf);       // write to shared memory

        sem_post(sem);                   // notify server
    }
}

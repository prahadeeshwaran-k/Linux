/*
 * server.c : Simplex POSIX shared memory reader
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

    // Create shared memory
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) error("shm_open");

    ftruncate(shm_fd, sizeof(struct shared_memory));

    shm = mmap(NULL, sizeof(*shm),
                PROT_READ | PROT_WRITE,
                MAP_SHARED, shm_fd, 0);
    if (shm == MAP_FAILED) error("mmap");

    // Create semaphore (initial value 0)
    sem = sem_open(SEM_NAME, O_CREAT, 0666, 0);
    if (sem == SEM_FAILED) error("sem_open");

    printf("Server waiting for messages...\n");

    while (1) {
        sem_wait(sem);                     // wait for client
        printf("Received: %s\n", shm->message);
    }
}

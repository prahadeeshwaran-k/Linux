// init.c
#include <stdio.h>
#include <sys/sem.h>

int main() {
    int id = semget(55, 1, IPC_CREAT | 0664);
    if (id < 0) { perror("semget"); return 0; }

    // SET semaphore value = 3 (3 seats available)
    semctl(id, 0, SETVAL, 3);

    printf("Semaphore initialized to 3\n");
    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

typedef struct {
    volatile int turn;   // 0 = sender’s turn, 1 = receiver’s turn
    int value;
} shm_t;


int main() {
    int id, first_time_init = 0;
    shm_t *p;

    // Try to create new shared memory
    id = shmget(11, sizeof(shm_t), IPC_CREAT | 0664);
    first_time_init = 1;

    if (id < 0) {
        perror("shmget");
        return 1;
    }

    p = (shm_t *)shmat(id, 0, 0);
    if (first_time_init) {
        p->turn = 0;   // sender starts
        p->value = 0;
    }

    int i = 0;
    while (i < 100) {               // write 100 values
        while (p->turn != 0) ;     // wait until it's sender's turn
        p->value = i++;
        printf("Sender wrote: %d\n", p->value);
        p->turn = 1;               // give turn to receiver
        sleep(1);
    }

    shmdt(p);
    return 0;
}

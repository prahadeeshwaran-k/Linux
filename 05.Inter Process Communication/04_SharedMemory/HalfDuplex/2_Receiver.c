#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

typedef struct {
    volatile int turn;   // 0 = sender’s turn, 1 = receiver’s turn
    int value;
} shm_t;

int main() {
    int id;
    shm_t *p;

    id = shmget(11, sizeof(shm_t), 0664); //Sender only create receiver only open it
    p = (shm_t *)shmat(id, 0, 0);
    if (p == (void *)-1) {
        perror("shmat");
        return 1;
    }

    while (1) {
        while (p->turn != 1) ;    // wait until it's receiver's turn
        printf("Receiver read: %d\n", p->value);
        p->turn = 0;              // give turn back to sender
        sleep(1);
    }

    shmdt(p);
    return 0;
}

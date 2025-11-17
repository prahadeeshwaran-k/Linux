// user.c
#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>

int main() {
    int id = semget(55, 1, 0664);

    struct sembuf v;

    // sem_op = -1 → request 1 resource
    v.sem_num = 0;
    v.sem_op = -1;     // TAKE resource
    v.sem_flg = 0;

    printf("Process %d waiting for resource...\n", getpid());

    semop(id, &v, 1);  // will block if semval < 1

    printf("Process %d GOT the resource!\n", getpid());

    sleep(5);          // simulate usage

    // sem_op = +1 → release resource
    v.sem_op = +1;

    semop(id, &v, 1);  // increase semval

    printf("Process %d RELEASED the resource.\n", getpid());
    return 0;
}

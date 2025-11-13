/*
Meaning: If no message is available, don’t block — return immediately with an error.
1.If no message of type 1 is present, msgrcv() will not wait; it returns -1 immediately.
2.Without IPC_NOWAIT, it would block until a message arrives.
2.Without IPC_NOWAIT, it would block until a message arrives.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

#define KEY 1234

struct msgbuf {
    long mtype;
    char mtext[50];
};

int main() {
    struct msgbuf msg;
    int msgid = msgget(KEY, IPC_CREAT | 0666);

    // Try to receive message of type 1
    if (msgrcv(msgid, &msg, sizeof(msg.mtext), 1, IPC_NOWAIT) == -1) {
        perror("No message available (IPC_NOWAIT)");
    } else {
        printf("Received: %s\n", msg.mtext);
    }

    return 0;
}

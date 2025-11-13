/*
Meaning: If message is larger than msgsz, it truncates it instead of failing.
1.Without MSG_NOERROR, this would fail with E2BIG error because message > 10 bytes.
2.With MSG_NOERROR, message is truncated safely to 10 bytes.
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

    // Send a long message
    msg.mtype = 1;
    strcpy(msg.mtext, "This is a very long message that exceeds buffer size");
    msgsnd(msgid, &msg, sizeof(msg.mtext), 0);

    struct msgbuf recv;
    // Try to receive only 10 bytes
    if (msgrcv(msgid, &recv, 10, 1, MSG_NOERROR) != -1) {
        recv.mtext[10] = '\0';
        printf("Received (truncated with MSG_NOERROR): %s\n", recv.mtext);
    } else {
        perror("msgrcv");
    }

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

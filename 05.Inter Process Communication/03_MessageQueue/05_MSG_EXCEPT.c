/*
Meaning: Receive the first message whose type is not equal to msgtyp.
1.Here, msgtyp = 1 and MSG_EXCEPT means “get the first message that’s not type 1”
2.So the program will read "Message type 2".
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#define MSG_EXCEPT 020000
#define KEY 1234

struct msgbuf {
    long mtype;
    char mtext[50];
};

int main() {
    struct msgbuf msg;
    int msgid = msgget(KEY, IPC_CREAT | 0666);

    // Send two messages
    msg.mtype = 1;
    strcpy(msg.mtext, "Message type 1");
    msgsnd(msgid, &msg, sizeof(msg.mtext), 0);

    msg.mtype = 2;
    strcpy(msg.mtext, "Message type 2");
    msgsnd(msgid, &msg, sizeof(msg.mtext), 0);

    // Try to receive message NOT of type 1
    msgrcv(msgid, &msg, sizeof(msg.mtext), 1, MSG_EXCEPT);

    printf("Received (MSG_EXCEPT): %s\n", msg.mtext);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

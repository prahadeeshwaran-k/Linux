#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

struct msgbuf
{
    long mtype;
    char message[25]; // This holds the message
} msg;

int main()
{
    char input[25];
    int msgid = msgget(61, IPC_CREAT | 0664);
    msg.mtype = 1;

    if (msgid < 0)
    {
        perror("msgget");
        return 0;
    }

    printf("Message Queue ID = %d\n", msgid);
    while(1)
    {
        int result = msgrcv(msgid, &msg, sizeof(msg.message) + 1,0,0); // it returns 0 on success, -1 on failure
        if (result == -1) {
            perror("msgrcv");
            break;
        }
        printf("Received (type %ld): %s\n", msg.mtype, msg.message);
        printf("%d\n", result);//note the result is the number of message sent.
    }
}
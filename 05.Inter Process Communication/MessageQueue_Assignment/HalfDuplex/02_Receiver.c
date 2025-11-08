//Simple HalfDuplex Communication Receiver
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

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
    while (1)
    {
        //wait for the receives the message.
        int result = msgrcv(msgid, &msg, sizeof(msg.message) + 1,0,0); // it returns 0 on success, -1 on failure
        if (result == -1) {
            perror("msgrcv");
            break;
        }
        printf("Received (type %ld): %s\n", msg.mtype, msg.message);
        printf("%d\n", result);//note the result is number of received data

        for (int i = 0; i < strlen(msg.message); i++) {
            msg.message[i] = toupper(msg.message[i]);
        }

        //send the message
        result = msgsnd(msgid, &msg, strlen(input) + 1, 0);
        printf("Sentback :%d\n", result);
        
    }
}
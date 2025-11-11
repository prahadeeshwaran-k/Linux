//Simple HalfDuplex Communication Receiver
#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
#include <unistd.h>

struct msgbuf
{
    long mtype;
    char message[25]; // This holds the message
};

struct msgbuf msg, msg2;

int main()
{
    char input[25];
    int msgid = msgget(61, IPC_CREAT | 0664);
    msg.mtype = 1;

    int msgid2 = msgget(69, IPC_CREAT | 0664);
    msg2.mtype = 1;

    printf("Message Queue ID = %d\n", msgid);

    if (fork()==0)
    {
        while (1)
        {
            // send the message
            printf("Enter the Message = ");
            scanf(" %s", input);
            strcpy(msg2.message, input);
            int result = msgsnd(msgid2, &msg2, strlen(input) + 1, 0); // it returns 0 on success, -1 on failure
            msg2.mtype++;
        }
    }else{
        while (1)
    {
        //wait for the receives the message.
        int result = msgrcv(msgid, &msg, sizeof(msg.message) + 1,0,0); // it returns 0 on success, -1 on failure
        if (result == -1) {
            perror("msgrcv");
            break;
        }
        printf("Received (type %ld): %s\n", msg.mtype, msg.message);    
    }
    }
    
    
}

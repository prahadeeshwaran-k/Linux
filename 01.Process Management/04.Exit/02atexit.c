#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void fun1();
void fun2();
int main()
{
        printf("before function\n");
        atexit(fun1);
        printf("after fun1\n");
        atexit(fun2);
        printf("main function exit...\n");
        _exit(0);//it’s a system call
        //All the Buffers/streams are not flushed out but process termination immediately
}
void fun1()
{
        printf("in fun1 function...\n");
        printf("Hello...\n");
}
void fun2()
{
        printf("in fun2 function...\n");
        printf("hi...\n");
}

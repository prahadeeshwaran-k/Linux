#include<stdio.h>
#include<unistd.h>

int main(){
    int id = fork();
    printf("Hello\n");
}
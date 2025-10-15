#include <setjmp.h> //for setjump and longjump
#include <stdio.h>
#include <unistd.h>
jmp_buf jump;
int main(){
    printf("The Main Program\n");
    int val = setjmp(jump); // for the 1st time it return 0;
    printf("Long Jump Return Value: %d\n",val);
    printf("Delay\n");
    for(int i = 0, t = 2;i<2;i++){
        printf("T-%d\n",t-i);
        sleep(1);
    }
    //Only Execute for the 1st Time only
    if(val == 0){
        longjmp(jump,7);//this 7 is going to return in the 7th line setjump(jump);
    }
    printf("Never Gonna Give You Up\n"); //Never Execute;
 }

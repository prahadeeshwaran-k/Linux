#include <stdio.h>
#include <setjmp.h>

// NOTE :this is my mistake -> typedef int(*Function)(int,int);
typedef int Function(int,int);
Function add,sub,div,mul;
jmp_buf jump;



int main(){
    int a,b,result;
    char op;
    int val = setjmp(jump);
    if(val == 1)
        printf("Error Multiplication with 0 \n\n");
    if(val == 2)
        printf("Error Division by 0 \n\n");
    do{
        printf("Enter A : ");
        scanf("%d",&a);
        printf("Enter B : ");
        scanf("%d",&b);
        printf("Operation : ");
        scanf(" %c",&op);

        switch(op){
            case '+':{
                printf("ADDITION %d + %d = %d\n\n",a,b,add(a,b));
                break;
            }
            case '-':{
                printf("SUBTRACTION %d - %d = %d\n\n",a,b,sub(a,b));
                break;
            }
            case '*':{
                printf("MULTIPLY %d * %d = %d\n\n",a,b,mul(a,b));
                break;
            }
            case '/':{
                printf("DIVIDE %d / %d = %d\n\n",a,b,div(a,b));
                break;
            }
            default:{
                printf("Not a valid operation: %c\n\n",op);
            }

        }
    }while (1);
}

int add(int a,int b){
    return a+b;
}

int sub(int a,int b){
    return a-b;
}

int mul(int a,int b){
    if(a == 0 || b == 0)
        longjmp(jump,1);
    return a*b;
}

int div(int a,int b){
    if(b == 0)
        longjmp(jump,2);
    return a/b;
}

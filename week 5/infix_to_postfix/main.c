#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void infix_postfix (char infix[],char postfix[]);
int main() {

    char inf[100];
    char pos[100];
    printf("enter infix to convrt:");
    scanf("%s",inf);
    infix_postfix(inf,pos);
    printf("postfix is %s",pos);
    getchar();


    return 0;
}
int is_digit (char c)
{
    return (c>='0'&&c<='9');
}

int precedent (char op1,char op2)
{
 int prec1,prec2;
    switch (op1) {
        case '+':
        case '-':
            prec1=1;
        break;

        case'*':
        case'/':
            prec1=2;
        break;
        case'^':
            prec1=3;
            break;
        default:
            prec1=0;

    }

    switch (op2) {
        case '+':
        case '-':
            prec2=1;
            break;

        case'*':
        case'/':
            prec2=2;
            break;
        case'^':
            prec2=3;
            break;
        default:
            prec2=0;

    }
    return prec1>=prec2;
}

void infix_postfix (char infix[],char postfix[])
{
    char ch,op;
    int i,j;
    Stack s;
    create_stack(&s);
    for ( i = 0,j=0 ; ch=(infix[i])!='\0' ; ++i) {
        if(is_digit(ch))
        {
            postfix[j++]=ch;
        }
        else
        {
            if(!stack_empty(&s))
            {
                stack_top(&op,&s);
                while(!stack_empty(&s) && precedent(op,ch))
                {
                    pop(&op,&s);
                    postfix[j++]=ch;
                    if(!stack_empty(&s))
                    {
                        stack_top(&op,&s);
                    }
                }
                push(ch,&s);
            }
        }
    }
    while (!stack_empty(&s))
    {
        pop(&op,&s);
        postfix[j++]=op;
    }
    postfix[j]='\0';
}

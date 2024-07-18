#include <stdio.h>
#include "stack.h"
void display (stackentry e)
{
    printf("elements is %d\n",e);
}

int main() {

    Stack s;
    create_stack(&s);

    if(!stack_full(&s))
    {
        push(4,&s);
        push(10,&s);
        push(3,&s);
        push(7,&s);
        push(2,&s);
    }

    int e=2;
    if(!stack_empty(&s))
    {
        pop(&e,&s);
    }

    traverse(&s,&display);
    int size= stack_size(&s);
    printf("%d",size);


    return 0;
}

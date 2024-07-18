#include <stdio.h>
#include "linked_stack.h"

void display (stack_entry e)
{
    printf("Element is %d\n",e);
}
int main() {
   Stack s;
    create_stack(&s);

    if(!stack_full(&s))
    {
        push(10,&s);
        push(20,&s);
        push(30,&s);
        push(40,&s);
        push(50,&s);

    }

    int e=50;
    pop(&e,&s);

    traverse(&s,&display);
    return 0;
}

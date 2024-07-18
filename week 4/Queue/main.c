#include <stdio.h>
#include "Queue.h"

void display(Queue_entry e)
{
    printf("The elements are %d\n ",e);
}
int main() {

    Queue q;
    create_queue(&q);

    if(!Queue_full(&q))
    {
        append(5,&q);
        append(10,&q);
        append(15,&q);
        append(20,&q);
        append(25,&q);
    }

    int e=5;
    serve(&e,&q);
    traverse_queue(&q,&display);

    return 0;
}

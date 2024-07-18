#include <stdio.h>
#include "Queue_linkedbased.h"

void display (Queue_Entry e)
{
    printf("elements are %d\n",e);
}
int main() {

    Queue q;
    creat_queue(&q);

    append_queue(2,&q);
    append_queue(4,&q);
    append_queue(6,&q);
    append_queue(8,&q);

    int e=2;
    serve(&e,&q);


    return 0;
}

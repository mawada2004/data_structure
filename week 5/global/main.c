#include <stdio.h>
#include "stack.h"
#include "Queue.h"

int main() {
    Queue q;
    creat_queue(&q);

    for (int i = 0; i < 5; ++i) {
        serve(&i,&q);
    }

    int Size=queue_size(&q);
    printf("%d",Size);


    return 0;
}

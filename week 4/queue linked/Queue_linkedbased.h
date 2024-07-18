//
// Created by Lenovo on 7/17/2024.
//

#ifndef UNTITLED1_QUEUE_LINKEDBASED_H
#define UNTITLED1_QUEUE_LINKEDBASED_H

typedef int Queue_Entry;

typedef struct queuenode{
    Queue_Entry entry;
    struct queuenode *next;

}Queuenode;

typedef struct queue{
   Queuenode *front;
   Queuenode *rear;
   int size;

}Queue;

void creat_queue(Queue *pq);
void append_queue(Queue_Entry e,Queue *pq);
void serve (Queue_Entry *pe,Queue *pq);
int queue_empty(Queue *pq);
int queue_full(Queue *pq);
int queue_size (Queue *pq);
void queue_clear(Queue *pq);
#endif //UNTITLED1_QUEUE_LINKEDBASED_H

//
// Created by Lenovo on 7/18/2024.
//

#ifndef UNTITLED2_QUEUE_H
#define UNTITLED2_QUEUE_H

#define max 10
typedef int Queue_entry;
typedef struct Queue
{
    int rear;
    int front ;
    int size;
    Queue_entry entry[max];
}Queue;

void create_queue(Queue *pq);
void append (Queue_entry e,Queue *pq);
void serve (Queue_entry *pe,Queue *pq);
int Queue_empty (Queue *pq);
int Queue_full (Queue *pq);
int Queue_size (Queue *pq);
void clear_queue (Queue *pq);
void traverse_queue (Queue *pq,void(*pf)(Queue_entry));
#endif //UNTITLED2_QUEUE_H

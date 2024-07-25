//
// Created by Lenovo on 7/24/2024.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H

#include "Global.h"

#if LIMITED_MEMORY == LINKED_BASED

// Linked list based queue

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

#elif LIMITED_MEMORY == ARRAY_BASED
// Array based queue
#define max 100
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

#endif //LIMITED_MEMORY
#endif //UNTITLED_QUEUE_H

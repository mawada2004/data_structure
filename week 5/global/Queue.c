//
// Created by Lenovo on 7/24/2024.
//
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include "Global.h"

#if LIMITED_MEMORY == LINKED_BASED

// Linked list based queue implementation
void creat_queue(Queue *pq)
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}

void append_queue(Queue_Entry e,Queue *pq)
{
    Queuenode *pn=(Queuenode*)malloc(sizeof (Queuenode));
    pn->next=NULL;
    pn->entry=e;

    if (!pq->rear)
    {
        pq->front=pn;
    }
    else
    {
        pq->rear->next=pn;
    }

    pq->rear=pn;
    pq->size++;
}

void serve (Queue_Entry *pe,Queue *pq)
{
   Queuenode *pn=pq->front;
   *pe =pn->entry;
    pq->front=pn->next;
    free(pn);
    if(!pq->front)
    {
        pq->rear=NULL;
    }
    pq->size--;
}

int queue_empty(Queue *pq)
{
    return !pq->front;
}

int queue_full(Queue *pq)
{
    return 0;
}

int queue_size (Queue *pq)
{
    return pq->size;
}

void queue_clear(Queue *pq)
{
    Queuenode *pn=pq->front;
    Queuenode *qn=pq->rear;

    while(pn)
    {
        qn=pn->next;
        free(pn);
        pn=qn;
    }
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}
#elif LIMITED_MEMORY_Q == ARRAY_BASED

// Array based queue implementation
void create_queue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}

void append (Queue_entry e,Queue *pq)
{
    pq->rear=(pq->rear+1)%max;
    pq->entry[pq->rear]=e;
    pq->size++;
}

void serve (Queue_entry *pe,Queue *pq)
{
    *pe=pq->entry[pq->front];
    pq->front=(pq->front+1)%max;
    pq->size--;
}

int Queue_empty (Queue *pq)
{
    return !pq->size;
}

int Queue_full (Queue *pq)
{
    return (pq->size==max);
}

int Queue_size (Queue *pq)
{
    return pq->size;
}

void clear_queue (Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}

void traverse_queue (Queue *pq,void(*pf)(Queue_entry))
{
    int pos, s;
    for(pos=pq->front,s=0;s<pq->size;s++)
    {
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%max;
    }
}
#endif
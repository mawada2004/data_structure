//
// Created by Lenovo on 7/18/2024.
//
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

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
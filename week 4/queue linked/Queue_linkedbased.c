//
// Created by Lenovo on 7/17/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "Queue_linkedbased.h"

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
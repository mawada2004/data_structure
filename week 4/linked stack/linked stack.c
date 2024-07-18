//
// Created by Lenovo on 7/18/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "linked_stack.h"

void create_stack (Stack *ps)
{
    ps->top=NULL;
    ps->size=0;
}

void push (stack_entry e,Stack *ps)
{
    StackNode *pn =(StackNode *)malloc(sizeof(StackNode));
    pn->entry=e;
    pn->next=ps->top;
    ps->top=pn;
    ps->size++;
}

void pop (stack_entry *pe,Stack *ps)
{
    StackNode *pn;
    *pe=ps->top->entry;
    pn=ps->top;
    ps->top=ps->top->next;
    free(pn);
    ps->size--;
}

int stack_empty (Stack *ps)
{
    return ps->top==NULL;
}

int stack_full (Stack *ps)
{
    return 0;
}

void clear_stack (Stack *ps)
{
    StackNode *pn=ps->top;
    StackNode *qn=ps->top;
    while(pn)
    {
        pn=pn->next;
        free(qn);
        qn=pn;
    }
    ps->top=NULL;
    ps->size=0;
}

int size (Stack *ps)
{
    return ps->size ;
}

void traverse (Stack *ps,void(*pf)(stack_entry))
{
    StackNode *pn=ps->top;
    while(pn)
{
     (*pf)(pn->entry);
     pn=pn->next;
  }
}
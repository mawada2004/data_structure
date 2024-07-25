//
// Created by Lenovo on 7/24/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "Global.h"

#if LIMITED_MEMORY == LINKED_BASED

// Linked list based stack implementation

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

#elif LIMITED_MEMORY == ARRAY_BASED

// Array based stack implementation
void create_stack (Stack *ps)
{
    ps->top=0;
}

void push (stackentry e,Stack *ps)
{
    ps->entry[ps->top]=e;
    ps->top++;
}

void pop (stackentry *pe,Stack *ps)
{
    ps->top--;
    *pe=ps->entry[ps->top];
}

int stack_full (Stack *ps)
{
    if(ps->top==max_stack)
        return 1;
    else
        return 0;
}

int stack_empty (Stack *ps)
{
    if (ps->top==0)
        return 1;
    else
        return 0;
}

void stack_top (stackentry *pe,Stack *ps)
{
    *pe=ps->entry[ps->top-1];
}

int stack_size (Stack *ps)
{
    return ps->top;
}

void clear_stack (Stack *ps)
{
    ps->top=0;
}

void traverse (Stack *ps,void (*pf)(stackentry) )
{
    for(int i=ps->top;i>0;i--)
    {
        (*pf)(ps->entry[i-1]);
    }
}

#endif // LIMITED_MEMORY
//
// Created by Lenovo on 7/18/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
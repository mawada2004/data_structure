//
// Created by Lenovo on 7/24/2024.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H
#include "Global.h"


#if LIMITED_MEMORY == LINKED_BASED

// Linked list based stack
typedef int stack_entry;

typedef struct stacknode
{
    struct stacknode *next;
    stack_entry entry;
}StackNode;

typedef struct stack
{
    StackNode *top;
    int size;
}Stack;

void create_stack (Stack *ps);
void push (stack_entry e,Stack *ps);
void pop (stack_entry *pe,Stack *ps);
int stack_empty (Stack *ps);
int stack_full (Stack *ps);
void clear_stack (Stack *ps);
int size (Stack *ps);
void traverse (Stack *ps,void(*pf)(stack_entry));

#elif LIMITED_MEMORY == ARRAY_BASED
// Array based stack
# define max_stack 10
typedef int stackentry;

typedef struct stack
{
    int top;
    stackentry entry[max_stack];
}Stack;

void create_stack (Stack *ps);
void push (stackentry e,Stack *ps);
void pop (stackentry *pe,Stack *ps);
int stack_full (Stack *ps);
int stack_empty (Stack *ps);
void stack_top (stackentry *pe,Stack *ps);
int stack_size (Stack *ps);
void clear_stack (Stack *ps);
void traverse (Stack *ps,void (*pf)(stackentry) );

#endif // LIMITED_MEMORY


#endif //UNTITLED_STACK_H

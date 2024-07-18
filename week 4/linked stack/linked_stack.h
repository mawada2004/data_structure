//
// Created by Lenovo on 7/18/2024.
//

#ifndef UNTITLED2_LINKED_STACK_H
#define UNTITLED2_LINKED_STACK_H

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

#endif //UNTITLED2_LINKED_STACK_H

//
// Created by Lenovo on 7/18/2024.
//

#ifndef UNTITLED1_STACK_H
#define UNTITLED1_STACK_H

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

#endif //UNTITLED1_STACK_H

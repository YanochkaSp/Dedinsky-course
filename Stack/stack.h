#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Stack
{
    int* data;
    int size;
    int capacity;
};

void StackCtor (Stack* pStk, int initCapacity);

void StackPush (Stack *pStk, int el);

int StackPop (Stack *pStk);

void StackDtor (Stack *pStk);

void StackPrinter (Stack *pStk);

#endif
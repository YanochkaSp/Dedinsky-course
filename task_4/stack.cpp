#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[])
{
    Stack stk = {0};
    StackCtor (&stk, 5);
    StackPush (&stk, 10);
    int x = StackPop (&stk);
    printf("%d", x);
    StackPrinter (&stk);
    StackDtor (&stk);
}

void StackCtor (Stack* pStk, int initCapacity)
{
    pStk -> data = (int*)calloc(initCapacity, sizeof(int));
    pStk -> size = 0;
    pStk -> capacity = initCapacity;
}

void StackPush (Stack *pStk, int el)
{
    if (pStk -> size == pStk -> capacity)     
    {
        pStk -> data = (int*)realloc (pStk -> data, 2 * pStk -> capacity * sizeof(int)); // проверка на == NULL, сделать доп переменную
        pStk -> capacity *= 2; 
    }
    *(pStk -> data + pStk -> size) = el;
    ++ pStk -> size;
}

int StackPop (Stack *pStk)
{
    if (pStk -> size == 0)
    {
        return -1; // вывести код ошибки, для этого ввести параметр
    }
    -- pStk -> size;
    int el = *(pStk -> data + pStk -> size);
    return el;
}

void StackDtor (Stack *pStk)
{
    free (pStk -> data);
    pStk -> data = NULL;
    pStk -> size = 0;
    pStk -> capacity = 0;
}

void StackPrinter (Stack *pStk)
{
    for (int i = 0; i < pStk -> size; ++i)
    {
        printf("StackPrinter(): \n%d\n", pStk -> data[i]);
    }
}
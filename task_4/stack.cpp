#include "stack.h"

void StackCtor (struct Stack* pStk, int initCapacity)
{
    pStk -> data = (int*)calloc(initCapacity, sizeof(int));
    pStk -> size = 0;
    pStk -> capacity = initCapacity;
}

void StackPush (struct Stack *pStk, int el)
{
    if (pStk -> size == pStk -> capacity)     
    {
        pStk -> data = (int*)realloc (pStk -> data, 2 * pStk -> capacity * sizeof(int)); 
        if (pStk -> data == NULL)
        {
            printf("Memory allocation error\n");
            return;
        }
        pStk -> capacity *= 2; 
    }
    *(pStk -> data + pStk -> size) = el;
    ++ pStk -> size;
}

int StackPop (struct Stack *pStk)
{
    if (pStk -> size == 0)
    {
        printf("errno: %d\n", errno); // вывод кода ошибки
    }
    -- pStk -> size;
    int el = *(pStk -> data + pStk -> size);
    return el;
}

void StackDtor (struct Stack *pStk)
{
    free (pStk -> data);
    pStk -> data = NULL;
    pStk -> size = 0;
    pStk -> capacity = 0;
}

void StackPrinter (struct Stack *pStk)
{
    printf("StackPrinter():\n");
    for (int i = 0; i < pStk -> capacity; ++i)
    {
        printf("%d) [%d]\n", i, pStk -> data[i]);
    }
}
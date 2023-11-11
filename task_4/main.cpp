#include "stack.h"

int main(int argc, char* argv[])
{
    Stack stk = {0};
    printf ("Which stack capacity do you want:\n");
    int cap = 0;
    scanf ("%d", &cap);
    StackCtor (&stk, cap);
    StackPrinter (&stk);

    for (int i = 0; i < cap; ++i)
    {
        printf ("Write a number you want to push:\n");
        int num = 0;
        scanf ("%d", &num);
        StackPush (&stk, num);
        printf("Pushing number [%d]\n", num);
        StackPrinter (&stk);
    }
    

    for (int i = 0; i < cap; ++i)
    {
        int x = StackPop (&stk);
        printf("StackPop(): [%d]\n", x);
    }
    
    printf("StackDtor(): destructing stack");
    StackDtor (&stk);
}
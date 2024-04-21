//рекурсивный спуск
#include <stdio.h>

#define SYNTAX_ERROR() SyntaxError(__func__, __LINE__)

int GetG (const char* str);
int GetE ();
int GetT ();
int GetP ();
int GetN ();
void SyntaxError (const char* func, const int line);

const char* s = NULL;

int main(int argc, char* argv[])
{
    const char* expression = argv[1];
    int result = GetG(expression);

    printf("Result: %d\n", result);

    return 0;
}

int GetG (const char* str)
{
    s = str;
    int val = GetE();
    if (*s == '$') 
        s++;
    else 
    {
        SYNTAX_ERROR();
        printf("1\n");
    }
        


    return val;
}

int GetE ()
{
    int val = GetT();
    while (*s == '+' || *s == '-')
    {
        char op = *s;
        s++;
        int val2 = GetT();
        if (op == '+')
            val += val2;
        else
            val -= val2;
    }
    return val;
}

int GetT ()
{
    int val = GetP();
    while (*s == '*' || *s == '/')
    {
        char op = *s;
        s++;
        int val2 = GetP();
        if (op == '*')
            val *= val2;
        else
            val /= val2;
    }
    return val;
}

int GetP ()
{
    if (*s == '(')
    {
        s++;
        int val = GetE();
        if (*s == ')')        
            s++;
        else 
        {
            SYNTAX_ERROR();
            printf("2\n");
        }
            
        return val;
    }
    else
        return GetN();
}

int GetN ()
{
    int val = 0;
    const char* olds = s;
    while ('0' <= *s && *s <= '9')
    {
        val = val*10 + (*s - '0');
        s++;
    }
    if (olds == s)
    {
        SYNTAX_ERROR();
        printf("3\n");
    }
        
    return val;
}

void SyntaxError (const char* func, const int line)
{
    printf("Syntax Error: %s:%d\n", func, line);
}
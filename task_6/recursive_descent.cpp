//рекурсивный спуск
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int type;
    double value;
    struct Node* left;
    struct Node* right;
} Node;

Node* GetG (const char* str);
Node* GetE ();
Node* GetT ();
Node* GetP ();
Node* GetN ();
void SyntaxError ();
Node* CreateNode (int type, double value, Node* left, Node* right);

const char* s = NULL;

// func (sqrt, sin, ...), pow (^), -(унарный минус) , x
// 2^2^3 = 256 or 2^(2^(3))

enum types
{
    NUM,
    OP
};

int main(int argc, char* argv[])
{
    const char* expression = argv[1];
    int result = GetG(expression)->value;

    printf("Result: %d\n", result);

    return 0;
}

Node* GetG (const char* str)
{
    s = str;
    Node* val = GetE();
    if (*s == '$') 
        s++;
    else 
    {
        SyntaxError();
    }      
    return val;
}

Node* GetE ()
{
    Node* val = GetT();
    while (*s == '+' || *s == '-')
    {
        char op = *s;
        s++;
        Node* val2 = GetT();
        if (op == '+')
            val = CreateNode(OP, '+', val, val2);
        else
            val = CreateNode(OP, '-', val, val2);
    }
    return val;
}

Node* GetT ()
{
    Node* val = GetP();
    while (*s == '*' || *s == '/')
    {
        char op = *s;
        s++;
        Node* val2 = GetP();
        if (op == '*')
            val = CreateNode(OP, '*', val, val2);
        else
            val = CreateNode(OP, '/', val, val2);
    }
    return val;
}

Node* GetP ()
{
    if (*s == '(')
    {
        s++;
        Node* val = GetE();
        if (*s == ')') 
            s++;
        else 
        {
            SyntaxError();
        }          
        return val;
    }
    else
        return GetN();
}

Node* GetN ()
{
    double val = 0;
    const char* oldS = s;
    while ('0' <= *s && *s <= '9')
    {
        val = val*10 + (*s - '0');
        s++;
    }
    if (oldS == s)
    {
        SyntaxError();
    }
        
    return CreateNode (NUM, val, NULL, NULL);
}

void SyntaxError ()
{
    printf("Syntax Error\n");
    // exit(0);
}

Node* CreateNode (int type, double value, Node* left, Node* right)
{
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    newNode->type=type;
    newNode->value=value;
    newNode->left=left;
    newNode->right=right;
    return newNode;
}
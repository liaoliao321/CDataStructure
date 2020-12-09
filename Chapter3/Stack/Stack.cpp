#include <cstdlib>
#include "stdio.h"
#include "./Stack.h"
#define size 7

int main()
{
    char array[size] = {'b', 'a', 'x', 'q', 'w', 't','k'};
    Stack *stack;
    initStack(stack);

    char *p = array;
    int i;
    for (i = 0; i < size; i++)
    {
        push(stack, *p);
        p++;
    }
    printStack(stack);
    return true;
}

bool isEmpty(Stack *&stack)
{
    return stack->top == -1;
}
bool upOverflow(Stack *&stack)
{
    return stack->top == MaxSize - 1;
}
bool downOverflow(Stack *&stack)
{
    return stack->top == -1;
}
void initStack(Stack *&stack)
{
    stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
}
void destroyStack(Stack *&stack)
{
    free(stack);
}
bool push(Stack *&stack, ElemType e)
{
    if (upOverflow(stack))
        return false;
    stack->top++;
    stack->data[stack->top] = e;
    return true;
}
bool pop(Stack *&stack, ElemType e)
{
    if (downOverflow(stack))
        return false;
    e = stack->data[stack->top];
    stack->top--;
    return true;
}
bool getTop(Stack *&stack, ElemType e)
{
    if (downOverflow(stack))
        return false;

    e = stack->data[stack->top];
    return true;
}

void printStack(Stack *&s)
{

    int i;
    char *p = s->data;
    printf("bottom > ");
    for (i = 0; i < size; i++)
    {
        printf("%c -> ", *p);
        p++;
    }
    printf(" < top \n");
}
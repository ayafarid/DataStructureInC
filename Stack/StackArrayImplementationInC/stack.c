#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "stack.h"
void CreateStack(stack *ps)
{
    ps->top = 0;
}
int Push(StackEntry e, stack *ps)
{
    if (ps->top == MAXSTACK)
    {
        return 0;
    }
    else
    {
        ps->e[ps->top++] = e;
        return 1;
    }
}
int StackFull(stack *ps)
{
    if (ps->top == MAXSTACK)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Pop(StackEntry *e, stack *ps)
{
    if (ps->top == 0)
    {
        *e=-1;
        printf("stack is empty!\n");
        return 0;
    }
    else
    {
        ps->top--;
        *e = (int)ps->e[ps->top];
        return 1;
    }
}
int StackEmpty(stack *ps)
{
    if (ps->top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int StackTop(StackEntry *e, stack *ps)
{
    if (ps->top == 0)
    {
        *e=-1;
        printf("stack is empty!\n");
        return 0;
    }
    else
    {
        *e = ps->e[ps->top - 1];
        return 1;
    }
}
int StackSize(stack *ps)
{
    return ps->top;
}
void ClearStack(stack *ps)
{
    ps->top = 0;
}
void TraverseStack(stack *ps, void (*pf)(StackEntry))
{
    for (int i = ps->top; i > 0; i--)
        (*pf)(ps->e[i - 1]);
}

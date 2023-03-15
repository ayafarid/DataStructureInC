#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "Stack.h"

#ifdef CASTACk

// Array Stack

void CreateStack(Stack *ps)
{
    ps->top = 0;
}
int Push(StackEntry e, Stack *ps)
{
    if (ps->top == MAXSTACk)
    {
        printf("stack is fulln");
        return 0;
    }
    else
    {
        ps->entry[ps->top++] = e;
        return 1;
    }
}
int StackFull(Stack *ps)
{
    if (ps->top == MAXSTACk)
    {
        printf("stack is full");
        return 1;
    }
    else
    {
        return 0;
    }
}
int Pop(StackEntry *e, Stack *ps)
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
        *e = (int)ps->entry[ps->top];
        return 1;
    }
}
int StackEmpty(Stack *ps)
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
int StackTop(StackEntry *e, Stack *ps)
{
    if (ps->top == 0)
    {
        *e=-1;
        printf("stack is empty!\n");
        return 0;
    }
    else
    {
        *e = ps->entry[ps->top - 1];
        return 1;
    }
}
int StackSize(Stack *ps)
{
    return ps->top;
}
void ClearStack(Stack *ps)
{
    ps->top = 0;
}
void TraverseStack(Stack *ps, void (*pf)(StackEntry))
{
    for (int i = ps->top; i > 0; i--)
        (*pf)(ps->entry[i - 1]);
}
// LINKED STACK 
#else
void CreateStack(Stack *ps)
{
    ps->top = NULL;
    ps->size = 0;
}
int Push(StackEntry e, Stack *ps)
{
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}
int Pop(StackEntry *pe, Stack *ps)
{
    if (ps->top == NULL)
    {
        printf("stack is empty\n");
        return 0;
    }
    else
    {
        StackNode *pn;
        *pe = ps->top->entry;
        pn = ps->top;
        ps->top = ps->top->next;
        ps->size--;
        free(pn);
        return 1;
    }
}
int StackEmpty(Stack *ps)
{
    if (ps->top == NULL)
    {
        printf("stack is empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
int StackFull(Stack *ps)
{
    printf("stack is not full\n");
    return 0;
}
void ClearStack(Stack *ps)
{
    StackNode *pn = ps->top;

    while (pn)
    {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->size = 0;
}
void TraverseStack(Stack *ps, void (*pf)(StackEntry))
{
    StackNode *pn = ps->top;
    while (pn)
    {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}
int StackSize(Stack *ps)
{
    //   int x;
    //   StackNode *pn=ps->top;
    //   for(x=0; pn; pn=pn->next)
    //     x++;
    //   return x;
    return ps->size;
}
int StackTop(StackEntry *e,Stack* ps){
    if(ps->top==NULL){
        printf("stack is empty\n");
        return -1;
    }else{
        *e=ps->top->entry;
        return 1;
    }
}
#endif

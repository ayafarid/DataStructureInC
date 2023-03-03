#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "stack.h"
void CreateStack(stack *ps)
{
    ps->top = NULL;
    ps->size = 0;
}
int Push(StackEntry e, stack *ps)
{
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}
int Pop(StackEntry *pe, stack *ps)
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
int StackEmpty(stack *ps)
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
int StackFull(stack *ps)
{
    printf("stack is not full\n");
    return 0;
}
void ClearStack(stack *ps)
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
void TraverseStack(stack *ps, void (*pf)(StackEntry))
{
    StackNode *pn = ps->top;
    while (pn)
    {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}
int StackSize(stack *ps)
{
    //   int x;
    //   StackNode *pn=ps->top;
    //   for(x=0; pn; pn=pn->next)
    //     x++;
    //   return x;
    return ps->size;
}
int StackTop(StackEntry *e,stack* ps){
    if(ps->top==NULL){
        printf("stack is empty\n");
        return -1;
    }else{
        *e=ps->top->entry;
        return 1;
    }
}


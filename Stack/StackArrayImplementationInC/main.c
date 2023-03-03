#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "stack.h"
void print(StackEntry e);
int main()
{
    stack s;
    StackEntry e;
    CreateStack(&s);
    e=1;
    Push(e, &s);
    print(e);
    Pop(&e, &s);
    e=2;
    Push(e, &s);
    print(e);
    Pop(&e, &s);
    StackTop(&e, &s);
    print(e);
    Push(e, &s);
    Push(e, &s);
    Push(e, &s);
    Push(e, &s);
    Push(e, &s);
    Push(e, &s);
    int x;
    x = StackSize(&s);
    printf("%d\n", x);
    ClearStack(&s);
    TraverseStack(&s, &print);
}
void print(StackEntry e)
{
    printf("StackEntry = %d\n",e);
}
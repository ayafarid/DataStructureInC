#include "global.h"
#define MAXSTACK 5
typedef struct Stack
{
    int top;
    StackEntry e[MAXVERTEX];
} stack;
void CreateStack(stack *);
int Push(StackEntry, stack *);
int StackFull(stack *);
int Pop(StackEntry *, stack *);
int StackEmpty(stack *);
int StackTop(StackEntry *,stack *);
int StackSize(stack *);
void ClearStack(stack *);
void TraverseStack(stack *, void(*)(StackEntry));
//How to write the function StackTop in the user level? (e.g., if you do not have the source code of the implementation)
/*
void StackTop(StackEntry *pe, Stack *ps){
  Pop(pe, ps);
  Push(*pe, ps);
}
*/
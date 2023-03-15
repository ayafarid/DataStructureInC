#include "..\Global.h"
#define LIMITED_MEMORY ARRAY
#define ARRAY 1
#define LINKED 2
#if LIMITED_MEMORY == ARRAY
#define CASTACk
#else 
#define LINKED
#endif
#ifdef CASTACk 
/**
* Array Stack implementation
**/
typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACk];
}Stack;
#else 
typedef struct stacknode{
	StackEntry entry;
	struct stacknode *next;
}StackNode;
typedef struct  Stack
{
    StackNode * top;
	int size;
}Stack;
#endif
void CreateStack(Stack *);
int Push(StackEntry, Stack *);
int StackFull(Stack *);
int Pop(StackEntry *, Stack *);
int StackEmpty(Stack *);
int StackTop(StackEntry *,Stack *);
int StackSize(Stack *);
void ClearStack(Stack *);
void TraverseStack(Stack *, void(*)(StackEntry));


typedef int  StackEntry;
typedef struct stacknode{
	StackEntry entry;
	struct stacknode *next;
}StackNode;
typedef struct  Stack
{
    StackNode * top;
	int size;
}stack;
void CreateStack(stack *);
int Push(StackEntry ,stack*);
int Pop(StackEntry *, stack *);
int StackEmpty(stack*);
int StackFull(stack*);
void ClearStack(stack *);
void TraverseStack(stack *, void(*)(StackEntry));
int	StackSize(stack *ps);
int StackTop(StackEntry *,stack*);


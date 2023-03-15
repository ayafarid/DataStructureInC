#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Stack\stack.h"
#include "Queue\queue.h"
void printS(StackEntry e);
void printQ(QueueEntry e);

int main()
{
    Stack s;
    StackEntry es;
    CreateStack(&s);
    es=1;
    Push(es, &s);
    printS(es);
    Pop(&es, &s);
    es=2;
    Push(es, &s);
    printS(es);
    Pop(&es, &s);
    StackTop(&es, &s);
    printS(es);
    Push(es, &s);
    Push(es, &s);
    Push(es, &s);
    Push(es, &s);
    Push(es, &s);
    Push(es, &s);
    int x;
    x = StackSize(&s);
    printf("%d\n", x);
    ClearStack(&s);
    TraverseStack(&s, &printS);
    Queue q;
    CreateQueue(&q);
    QueueEntry e=10;
    Enqueue(&q,e);
    e=20;
    Enqueue(&q,e);
    e=30;
    Enqueue(&q,e);
    Dequeue(&e,&q);
    printQ(e);
    Dequeue(&e,&q);
    e=10;
    Enqueue(&q,e);
    e=20;
    Enqueue(&q,e);
    e=30;
    Enqueue(&q,e);
    TraverseQueue(&q,&printQ);
    x=QueueSize(&q);
    printf("%d\n",x);
}
void printS(StackEntry e)
{
    printf("StackEntry = %d\n",e);
}
void printQ(QueueEntry e)
{
    printf("QueueEntry = %d\n",e);
}
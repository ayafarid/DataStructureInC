#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Stack\stack.h"
#include "Queue\queue.h"
#include "APPS\MathimaticsAppSatck.h"
void printS(StackEntry e);
void printQ(QueueEntry e);

int main()
{
    char infix[8]="1+2*3+4";
    char postfix[8];
    InfixToPostfix(infix,postfix);
    printf("%s\n",postfix);
    double res=EvaluatePostfix(postfix);
    printf("%f\n",res);
    Stack s;
    StackEntry es;
    CreateStack(&s);
    es.etype=1;
    es.info.age=12;
    Push(es, &s);
    printS(es);
    int x;
    x = StackSize(&s);
    printf("Stack Size=%d\n", x);
    ClearStack(&s);
    printf("All Elements:\n");
    TraverseStack(&s, &printS);
    Queue q;
    CreateQueue(&q);
    QueueEntry e;
    e.etype=3;
    e.info.par='a';
    Enqueue(&q,e);
    e.info.par='b';
    Enqueue(&q,e);
    e.info.par='c';
    Enqueue(&q,e);
    Dequeue(&e,&q);
    printQ(e);
    Dequeue(&e,&q);
    printf("All Elements:\n");
    TraverseQueue(&q,&printQ);
    x=QueueSize(&q);
    printf("Queue Size=%d\n",x);
}
void printS(StackEntry e)
{
    switch (e.etype)
    {
    case 1:
        printf("Stack Entry Double valeu=%.2f\n",e.info.age);
        break;
    case 2:
        printf("Stack Entry Int valeu=%d\n",e.info.year);
        break;
    case 3:
        printf("Stack Entry Char valeu=%c\n",e.info.par);
        break;
    default:
        break;
    }
}
void printQ(QueueEntry e)
{
    switch (e.etype)
    {
    case 1:
        printf("Queue Entry Double valeu=%.2f\n",e.info.age);
        break;
    case 2:
        printf("Queue Entry Int valeu=%d\n",e.info.year);
        break;
    case 3:
        printf("Queue Entry Char valeu=%c\n",e.info.par);
        break;
    default:
        break;
    }
}
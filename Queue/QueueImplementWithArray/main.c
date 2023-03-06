#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "queue.h"
void print(QueueEntry e);
int main(){
    queue q;
    CreateQueue(&q);
    QueueEntry e=10;
    Enqueue(&q,e);
    e=20;
    Enqueue(&q,e);
    e=30;
    Enqueue(&q,e);
    Dequeue(&e,&q);
    print(e);
    Dequeue(&e,&q);
    e=10;
    Enqueue(&q,e);
    e=20;
    Enqueue(&q,e);
    e=30;
    Enqueue(&q,e);
    TraverseQueue(&q,&print);
    int x=QueueSize(&q);
    printf("%d\n",x);

}
void print(QueueEntry e)
{
    printf("QueueEntry = %d\n",e);
}
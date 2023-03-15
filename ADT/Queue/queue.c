#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "queue.h"

#ifdef ACQUEUE
void CreateQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
void Enqueue(Queue *pq, QueueEntry e)
{
    if (!QueueFull(pq))
    {
        pq->entry[((pq->rear += 1) % MAXQUEUE)] = e;
        pq->size++;
    }
}
void Dequeue(QueueEntry *e, Queue *pq)
{
    if (!QueueEmpty(pq))
    {
        *e = pq->entry[pq->front];
        pq->front = (pq->front + 1) % MAXQUEUE;
        pq->size--;
    }
}
int QueueEmpty(Queue *pq)
{
    return !(pq->size);
}
int QueueFull(Queue *pq)
{
    return pq->size == MAXQUEUE;
}
int QueueSize(Queue *pq)
{
    return pq->size;
}
void ClearQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry))
{
    int pos, s;
    if(!QueueEmpty(pq))
    for (pos = pq->front, s = 0; s < pq->size; s++)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}
#elif LINKED
void CreateQueue(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
void Enqueue(Queue *pq, QueueEntry e)
{
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    pn->entry = e;
    pn->next = NULL;
    if (pq->front == NULL)
    {
        pq->front = pn;
    }
    else
    {
        pq->rear->next = pn;
    }
    pq->rear = pn;
    pq->size++;
}
void Dequeue(QueueEntry *e, Queue *pq)
{
    QueueNode *pn = pq->front;
    *e = pn->entry;
    pq->front = pn->next;
    free(pn);
    if (pq->front == NULL)
        pq->rear = NULL;
    pq->size--;
}
int QueueEmpty(Queue * pq){
    return pq->size==0;
}
int QueueFull(Queue * pq){
    return pq->size==MAXQUEUE;
}
int QueueSize(Queue * pq){
    return pq->size;
}
void ClearQueue(Queue * pq){
    while (pq->front)
    {
        pq->rear=pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size=0;
}
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry)){
    QueueNode*pn;
    for(pn=pq->front;pn;pn=pn->next){
        (*pf)(pn->entry);
    }
}
#endif

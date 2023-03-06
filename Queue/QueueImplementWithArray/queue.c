#include "queue.h"
void CreateQueue(queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
void Enqueue(queue *pq, QueueEntry e)
{
    if (!QueueFull(pq))
    {
        pq->entry[((pq->rear += 1) % MAXQUEUE)] = e;
        pq->size++;
    }
}
void Dequeue(QueueEntry *e, queue *pq)
{
    if (!QueueEmpty(pq))
    {
        *e = pq->entry[pq->front];
        pq->front = (pq->front + 1) % MAXQUEUE;
        pq->size--;
    }
}
int QueueEmpty(queue *pq)
{
    return !(pq->size);
}
int QueueFull(queue *pq)
{
    return pq->size == MAXQUEUE;
}
int QueueSize(queue *pq)
{
    return pq->size;
}
void ClearQueue(queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
void TraverseQueue(queue *pq, void (*pf)(QueueEntry))
{
    int pos, s;
    if(!QueueEmpty(pq))
    for (pos = pq->front, s = 0; s < pq->size; s++)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}

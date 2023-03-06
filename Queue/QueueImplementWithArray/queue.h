#include "global.h"
typedef struct Queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}queue;
void CreateQueue(queue*);
void Enqueue(queue*,QueueEntry);
void Dequeue(QueueEntry*,queue*);
int QueueEmpty(queue*);
int QueueFull(queue*);
int QueueSize(queue*);
void ClearQueue(queue*);
void TraverseQueue(queue* ,void(*)(QueueEntry));
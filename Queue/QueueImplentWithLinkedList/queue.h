#include "global.h"
typedef struct queuenode{
    QueueEntry entry;
    struct queuenode*next;
    
}QueueNode;
typedef struct queue{
    QueueNode * front;
    QueueNode* rear;
    int size;
}Queue;
void CreateQueue(Queue*);
void Enqueue(Queue*,QueueEntry);
void Dequeue(QueueEntry*,Queue*);
int QueueEmpty(Queue*);
int QueueFull(Queue*);
int QueueSize(Queue*);
void ClearQueue(Queue*);
void TraverseQueue(Queue* ,void(*)(QueueEntry));

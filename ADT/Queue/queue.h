#include "..\global.h"
#define LIMITED_MEMORY ARRAY
#define ARRAY 1
#define LINKED 2
#if LIMITED_MEMORY == ARRAY
#define ACQUEUE
#else 
#define LINKED
#endif
#ifdef ACQUEUE
typedef struct Queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}Queue;
#else
typedef struct queuenode{
    QueueEntry entry;
    struct queuenode*next;
    
}QueueNode;
typedef struct queue{
    QueueNode * front;
    QueueNode* rear;
    int size;
}Queue;
#endif
void CreateQueue(Queue*);
void Enqueue(Queue*,QueueEntry);
void Dequeue(QueueEntry*,Queue*);
int QueueEmpty(Queue*);
int QueueFull(Queue*);
int QueueSize(Queue*);
void ClearQueue(Queue*);
void TraverseQueue(Queue* ,void(*)(QueueEntry));
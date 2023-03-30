#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data1;
typedef struct qNode{
    int val;
    struct qNode* next;
}qNode;

typedef struct Queue{
    qNode* qFront;
    qNode* qRear;
}Queue;

Queue* createQueue();
void enQueue(Queue* q, Data1 v);
Data1 deQueue(Queue* q);
int isqEmpty(Queue* q);
void deleteQueue(Queue* q);
void printQueue(Queue* q);
Data1 peekQueue(Queue* queue);

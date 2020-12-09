//
// Created by ivan on 2020/12/8.
//

#ifndef DATASTRUCTURE_QUEUE
#define DATASTRUCTURE_QUEUE
#define MaxSize 50
typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front,rear;
} Queue;

void initQueue(Queue * & q);
void destroyQueue(Queue * & q);
bool isFull(Queue * & q);
bool isEmpty(Queue * & q);
bool enQueue(Queue * & q, ElemType e);
bool deQueue(Queue * & q, ElemType &e);
void printQueue(Queue * & q);
#endif //DATASTRUCTURE_QUEUE

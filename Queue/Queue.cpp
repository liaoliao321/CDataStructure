#include <cstdlib>
#include "stdio.h"
#include "Queue.h"
#define size 7
int main()
{
    int array[7] = {4, 1, 3, 5, 7, 8, 9};
    int *p = array;
    Queue *queue;
    initQueue(queue);
    int i = 0;

    for (i = 0; i < size; i++)
    {
        enQueue(queue, *p);
        p++;
    }
    printQueue(queue);

    ElemType e;
    deQueue(queue, e);
    deQueue(queue, e);
    deQueue(queue, e);
    deQueue(queue, e);
    deQueue(queue, e);
    deQueue(queue, e);
    deQueue(queue, e);
    printQueue(queue);

    
    return 0;
}
bool isEmpty(Queue *&q)
{
    return q->front == q->rear;
}

bool isFull(Queue *&q)
{
    return q->front == MaxSize - 1;
}

void initQueue(Queue *&q)
{
    q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = 0;
}

void destroyQueue(Queue *&q)
{
    free(q);
}

bool enQueue(Queue *&q, ElemType e)
{
    if (isFull(q))
        return false;

    q->data[q->rear] = e;
    q->rear++;
    return true;
}
bool deQueue(Queue *&q, ElemType &e)
{
    if (isFull(q))
        return false;

    q->front++;
    e = q->data[q->front];
    return true;
}

void printQueue(Queue *&q)
{

    if (isEmpty(q))
    {
        printf("Queue is empty.");
        return;
    }

    int i;
    printf("front >>> ");
    for (i = q->front; i <= q->rear - 1; i++)
    {
        printf("%d - >", q->data[i]);
    }
    printf("  <<< rear\n");
}
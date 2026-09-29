#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_CAPACITY 30

typedef struct
{
    int values[QUEUE_CAPACITY];
    int front;
    int rear;
} OrderQueue;

void queueStart(OrderQueue *q);
int queueEmpty(OrderQueue *q);
void addToQueue(OrderQueue *q, int orderId);
int removeFromQueue(OrderQueue *q);
void displayQueue(OrderQueue *q);

#endif

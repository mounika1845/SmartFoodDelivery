#include <stdio.h>
#include "queue.h"

void queueStart(OrderQueue *q)
{
    q->front = 0;
    q->rear = -1;
}

int queueEmpty(OrderQueue *q)
{
    return q->front > q->rear;
}

void addToQueue(OrderQueue *q, int orderId)
{
    if (q->rear == QUEUE_CAPACITY - 1)
    {
        printf("Queue is full.\n");
        return;
    }

    q->values[++q->rear] = orderId;
}

int removeFromQueue(OrderQueue *q)
{
    if (queueEmpty(q))
    {
        return -1;
    }

    return q->values[q->front++];
}

void displayQueue(OrderQueue *q)
{
    int i;

    if (queueEmpty(q))
    {
        printf("Delivery queue is empty.\n");
        return;
    }

    printf("\n===== NORMAL DELIVERY QUEUE =====\n");

    for (i = q->front; i <= q->rear; i++)
    {
        printf("%d", q->values[i]);

        if (i < q->rear)
            printf(" -> ");
    }

    printf("\n");
}

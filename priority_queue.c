#include <stdio.h>
#include "priority_queue.h"

void priorityStart(PriorityQueue *pq)
{
    pq->count = 0;
}

void addPriorityOrder(
    PriorityQueue *pq,
    int id,
    int level)
{
    int position;

    if (pq->count == PRIORITY_CAPACITY)
    {
        printf("Priority queue is full.\n");
        return;
    }

    position = pq->count;

    while (position > 0 &&
           pq->items[position - 1].level < level)
    {
        pq->items[position] =
            pq->items[position - 1];

        position--;
    }

    pq->items[position].id = id;
    pq->items[position].level = level;

    pq->count++;
}

int takePriorityOrder(PriorityQueue *pq)
{
    int id;
    int i;

    if (pq->count == 0)
        return -1;

    id = pq->items[0].id;

    for (i = 1; i < pq->count; i++)
    {
        pq->items[i - 1] =
            pq->items[i];
    }

    pq->count--;

    return id;
}

void showPriorityQueue(PriorityQueue *pq)
{
    int i;

    printf("\n===== PRIORITY DELIVERY =====\n");

    if (pq->count == 0)
    {
        printf("No priority orders.\n");
        return;
    }

    for (i = 0; i < pq->count; i++)
    {
        printf("Order %d | Priority %d\n",
               pq->items[i].id,
               pq->items[i].level);
    }
}

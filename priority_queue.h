#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define PRIORITY_CAPACITY 30

typedef struct
{
    int id;
    int level;
} PriorityOrder;

typedef struct
{
    PriorityOrder items[PRIORITY_CAPACITY];
    int count;
} PriorityQueue;

void priorityStart(PriorityQueue *pq);
void addPriorityOrder(PriorityQueue *pq, int id, int level);
int takePriorityOrder(PriorityQueue *pq);
void showPriorityQueue(PriorityQueue *pq);

#endif

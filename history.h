
#ifndef HISTORY_H
#define HISTORY_H

#define HISTORY_LIMIT 50

typedef struct
{
    int orderId;
    int next;
} HistoryNode;

void historyStart(void);

void addCompletedOrder(int orderId);

void showCompletedOrders(void);

int completedOrderCount(void);

#endif

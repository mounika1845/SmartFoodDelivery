
#include <stdio.h>
#include "history.h"

HistoryNode history[HISTORY_LIMIT];

int historyHead;
int historyCount;

void historyStart(void)
{
    int i;

    historyHead = -1;
    historyCount = 0;

    for (i = 0; i < HISTORY_LIMIT; i++)
    {
        history[i].orderId = 0;
        history[i].next = -1;
    }
}

void addCompletedOrder(int orderId)
{
    int newPosition;
    int current;

    if (historyCount == HISTORY_LIMIT)
    {
        printf("Completed order history is full.\n");
        return;
    }

    newPosition = historyCount;

    history[newPosition].orderId = orderId;
    history[newPosition].next = -1;

    if (historyHead == -1)
    {
        historyHead = newPosition;
    }
    else
    {
        current = historyHead;

        while (history[current].next != -1)
        {
            current = history[current].next;
        }

        history[current].next = newPosition;
    }

    historyCount++;
}

void showCompletedOrders(void)
{
    int current;

    printf("\n========== COMPLETED DELIVERIES ==========\n");

    if (historyHead == -1)
    {
        printf("No completed deliveries yet.\n");
        return;
    }

    current = historyHead;

    while (current != -1)
    {
        printf("Order %d", history[current].orderId);

        if (history[current].next != -1)
        {
            printf(" -> ");
        }

        current = history[current].next;
    }

    printf(" -> NULL\n");
}

int completedOrderCount(void)
{
    return historyCount;
}

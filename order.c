#include <stdio.h>
#include "order.h"

Order orderList[ORDER_LIMIT];
int orderTotal = 0;

void prepareOrders(void)
{
    Order sample[] =
    {
        {101, 1, 1, "Pizza", 2, "Preparing"},
        {102, 4, 2, "Biryani", 5, "Ready"},
        {103, 3, 3, "Burger", 3, "Preparing"},
        {104, 2, 4, "Meals", 4, "Ready"}
    };

    int count = sizeof(sample) / sizeof(sample[0]);
    int i;

    for (i = 0; i < count; i++)
    {
        orderList[i] = sample[i];
    }

    orderTotal = count;
}

void printOrders(void)
{
    int i;

    printf("\n========== ORDERS ==========\n");

    for (i = 0; i < orderTotal; i++)
    {
        printf("Order %d | Food: %-10s | Priority: %d | %s\n",
               orderList[i].orderId,
               orderList[i].item,
               orderList[i].priority,
               orderList[i].state);
    }
}

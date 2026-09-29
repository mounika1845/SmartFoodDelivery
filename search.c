
#include <stdio.h>
#include "search.h"
#include "order.h"

int searchOrderById(int id)
{
    int i;

    for (i = 0; i < orderTotal; i++)
    {
        if (orderList[i].orderId == id)
        {
            return i;
        }
    }

    return -1;
}

void searchAndDisplayOrder(int id)
{
    int position;

    position = searchOrderById(id);

    if (position == -1)
    {
        printf("\nOrder %d was not found.\n", id);
        return;
    }

    printf("\n========== ORDER FOUND ==========\n");

    printf("Order ID       : %d\n",
           orderList[position].orderId);

    printf("Restaurant ID  : %d\n",
           orderList[position].restaurantId);

    printf("Customer ID    : %d\n",
           orderList[position].customerId);

    printf("Food Item      : %s\n",
           orderList[position].item);

    printf("Priority       : %d\n",
           orderList[position].priority);

    printf("Status         : %s\n",
           orderList[position].state);
}

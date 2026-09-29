
#include <stdio.h>
#include "storage.h"
#include "order.h"

void saveOrdersToFile(void)
{
    FILE *file;
    int i;

    file = fopen("orders.txt", "w");

    if (file == NULL)
    {
        printf("Unable to create orders.txt.\n");
        return;
    }

    fprintf(file,
            "ORDER_ID,RESTAURANT_ID,CUSTOMER_ID,ITEM,PRIORITY,STATUS\n");

    for (i = 0; i < orderTotal; i++)
    {
        fprintf(file,
                "%d,%d,%d,%s,%d,%s\n",
                orderList[i].orderId,
                orderList[i].restaurantId,
                orderList[i].customerId,
                orderList[i].item,
                orderList[i].priority,
                orderList[i].state);
    }

    fclose(file);

    printf("\nOrder data saved successfully to orders.txt\n");
}

void loadOrdersFromFile(void)
{
    FILE *file;
    char line[200];

    file = fopen("orders.txt", "r");

    if (file == NULL)
    {
        printf("\nNo previous order file found.\n");
        return;
    }

    printf("\nPrevious order file found.\n");

    if (fgets(line, sizeof(line), file) != NULL)
    {
        printf("File header: %s", line);
    }

    fclose(file);
}

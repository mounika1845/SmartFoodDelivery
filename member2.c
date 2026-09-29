#include <stdio.h>

#include "order.h"
#include "queue.h"
#include "priority_queue.h"

int main(void)
{
    OrderQueue normal;
    PriorityQueue urgent;

    int choice;
    int removed;

    prepareOrders();

    queueStart(&normal);
    priorityStart(&urgent);

    addToQueue(&normal, 101);
    addToQueue(&normal, 103);
    addToQueue(&normal, 104);

    addPriorityOrder(&urgent, 101, 2);
    addPriorityOrder(&urgent, 102, 5);
    addPriorityOrder(&urgent, 103, 3);
    addPriorityOrder(&urgent, 104, 4);

    do
    {
        printf("\n================================\n");
        printf(" SMART FOOD DELIVERY - MEMBER 2\n");
        printf("================================\n");
        printf("1. Show Orders\n");
        printf("2. Show Normal Queue\n");
        printf("3. Show Priority Queue\n");
        printf("4. Deliver Normal Order\n");
        printf("5. Deliver Priority Order\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printOrders();
                break;

            case 2:
                displayQueue(&normal);
                break;

            case 3:
                showPriorityQueue(&urgent);
                break;

            case 4:
                removed = removeFromQueue(&normal);

                if (removed == -1)
                    printf("No normal order available.\n");
                else
                    printf("Delivered normal order: %d\n",
                           removed);
                break;

            case 5:
                removed = takePriorityOrder(&urgent);

                if (removed == -1)
                    printf("No priority order available.\n");
                else
                    printf("Delivered priority order: %d\n",
                           removed);
                break;

            case 0:
                printf("\nMember 2 module closed.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}


#include <stdio.h>

#include "restaurant.h"
#include "customer.h"
#include "order.h"
#include "queue.h"
#include "priority_queue.h"
#include "graph.h"
#include "eta.h"

#include "search.h"
#include "history.h"
#include "storage.h"


void restaurantCustomerSection()
{
    int option;

    while (1)
    {
        printf("\n");
        printf("====================================\n");
        printf("     RESTAURANT & CUSTOMER MODULE\n");
        printf("====================================\n");
        printf("1. View Restaurants\n");
        printf("2. View Customers\n");
        printf("3. View Both\n");
        printf("0. Return to Main Menu\n");
        printf("------------------------------------\n");
        printf("Choose an option: ");

        scanf("%d", &option);

        if (option == 1)
        {
            showRestaurants();
        }
        else if (option == 2)
        {
            showCustomers();
        }
        else if (option == 3)
        {
            showRestaurants();
            showCustomers();
        }
        else if (option == 0)
        {
            break;
        }
        else
        {
            printf("\nInvalid option.\n");
        }
    }
}


void deliverySection(
    OrderQueue *normal,
    PriorityQueue *urgent)
{
    int option;
    int orderId;

    while (1)
    {
        printf("\n");
        printf("====================================\n");
        printf("          DELIVERY MODULE\n");
        printf("====================================\n");
        printf("1. View All Orders\n");
        printf("2. View Normal Queue\n");
        printf("3. View Priority Queue\n");
        printf("4. Deliver Normal Order\n");
        printf("5. Deliver Priority Order\n");
        printf("0. Return to Main Menu\n");
        printf("------------------------------------\n");
        printf("Choose an option: ");

        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printOrders();
                break;

            case 2:
                displayQueue(normal);
                break;

            case 3:
                showPriorityQueue(urgent);
                break;

            case 4:
                orderId = removeFromQueue(normal);

                if (orderId == -1)
                {
                    printf("\nThere are no normal orders waiting.\n");
                }
                else
                {
                    printf("\nNormal order %d has been delivered.\n",
                           orderId);

                    addCompletedOrder(orderId);
                }
                break;

            case 5:
                orderId = takePriorityOrder(urgent);

                if (orderId == -1)
                {
                    printf("\nThere are no priority orders waiting.\n");
                }
                else
                {
                    printf("\nPriority order %d has been delivered.\n",
                           orderId);

                    addCompletedOrder(orderId);
                }
                break;

            case 0:
                return;

            default:
                printf("\nInvalid option.\n");
        }
    }
}


void roadNetworkSection()
{
    printf("\n");
    printf("====================================\n");
    printf("        DELIVERY ROAD NETWORK\n");
    printf("====================================\n");

    printRoadMap();
}


void shortestPathSection()
{
    int source;
    int destination;

    int route[LOCATION_COUNT];
    int routeSize;

    int distance;
    int i;

    printf("\n");
    printf("====================================\n");
    printf("       SHORTEST DELIVERY ROUTE\n");
    printf("====================================\n");

    printf("Location numbers:\n");
    printf("0 - A\n");
    printf("1 - B\n");
    printf("2 - C\n");
    printf("3 - D\n");
    printf("4 - E\n");
    printf("5 - F\n");

    printf("\nStarting location: ");
    scanf("%d", &source);

    printf("Destination location: ");
    scanf("%d", &destination);

    if (source < 0 || source >= LOCATION_COUNT ||
        destination < 0 || destination >= LOCATION_COUNT)
    {
        printf("\nInvalid location number.\n");
        return;
    }

    distance = shortestRoute(
        source,
        destination,
        route,
        &routeSize
    );

    if (distance == -1)
    {
        printf("\nNo route was found between the selected locations.\n");
        return;
    }

    printf("\nRoute found: ");

    for (i = 0; i < routeSize; i++)
    {
        printf("%c", 'A' + route[i]);

        if (i != routeSize - 1)
        {
            printf(" -> ");
        }
    }

    printf("\nTotal distance: %d km\n", distance);
    printf("Method used: Dijkstra's Algorithm\n");
}


void etaSection()
{
    float distance;
    float speed;
    int minutes;

    printf("\n");
    printf("====================================\n");
    printf("          DELIVERY ETA\n");
    printf("====================================\n");

    printf("Distance in km: ");
    scanf("%f", &distance);

    printf("Average speed in km/h: ");
    scanf("%f", &speed);

    minutes = estimateMinutes(distance, speed);

    if (minutes == -1)
    {
        printf("\nPlease enter valid distance and speed values.\n");
        return;
    }

    printf("\nEstimated delivery time: %d minutes\n",
           minutes);

    printf("Calculation: Distance / Speed x 60\n");
}


void dashboardSection(
    OrderQueue *normal,
    PriorityQueue *urgent)
{
    int normalWaiting;
    int priorityWaiting;
    int completed;

    normalWaiting = 0;

    if (!queueEmpty(normal))
    {
        normalWaiting =
            normal->rear - normal->front + 1;
    }

    priorityWaiting = urgent->count;

    completed = completedOrderCount();

    printf("\n");
    printf("====================================\n");
    printf("         DELIVERY DASHBOARD\n");
    printf("====================================\n");

    printf("Restaurants       : %d\n", restaurantTotal);
    printf("Customers         : %d\n", customerTotal);
    printf("Total Orders      : %d\n", orderTotal);
    printf("Normal Pending    : %d\n", normalWaiting);
    printf("Priority Pending  : %d\n", priorityWaiting);
    printf("Completed         : %d\n", completed);

    printf("====================================\n");
}


void searchOrderSection()
{
    int orderId;

    printf("\n");
    printf("====================================\n");
    printf("            SEARCH ORDER\n");
    printf("====================================\n");

    printf("Enter Order ID: ");
    scanf("%d", &orderId);

    searchAndDisplayOrder(orderId);
}


void completedDeliverySection()
{
    printf("\n");
    printf("====================================\n");
    printf("       COMPLETED DELIVERIES\n");
    printf("====================================\n");

    showCompletedOrders();
}


void fileStorageSection()
{
    printf("\n");
    printf("====================================\n");
    printf("          FILE STORAGE\n");
    printf("====================================\n");

    saveOrdersToFile();
}


int main()
{
    OrderQueue normalQueue;
    PriorityQueue urgentQueue;

    int choice;

    loadRestaurants();
    loadCustomers();
    prepareOrders();

    createRoadMap();

    queueStart(&normalQueue);

    /*
       Normal orders
    */
    addToQueue(&normalQueue, 101);
    addToQueue(&normalQueue, 103);

    priorityStart(&urgentQueue);

    /*
       Priority orders
    */
    addPriorityOrder(&urgentQueue, 102, 5);
    addPriorityOrder(&urgentQueue, 104, 4);

    /*
       Start completed delivery history
    */
    historyStart();

    /*
       Check whether saved order file exists
    */
    loadOrdersFromFile();

    do
    {
        printf("\n\n");
        printf("================================================\n");
        printf("          SMART FOOD DELIVERY SYSTEM\n");
        printf("================================================\n");
        printf("1. Restaurant & Customer Management\n");
        printf("2. Order & Delivery Management\n");
        printf("3. Delivery Road Network\n");
        printf("4. Find Shortest Delivery Route\n");
        printf("5. Calculate Delivery ETA\n");
        printf("6. Delivery Dashboard\n");
        printf("7. Search Order\n");
        printf("8. Completed Deliveries\n");
        printf("9. Save Orders to File\n");
        printf("0. Exit\n");
        printf("================================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                restaurantCustomerSection();
                break;

            case 2:
                deliverySection(
                    &normalQueue,
                    &urgentQueue
                );
                break;

            case 3:
                roadNetworkSection();
                break;

            case 4:
                shortestPathSection();
                break;

            case 5:
                etaSection();
                break;

            case 6:
                dashboardSection(
                    &normalQueue,
                    &urgentQueue
                );
                break;

            case 7:
                searchOrderSection();
                break;

            case 8:
                completedDeliverySection();
                break;

            case 9:
                fileStorageSection();
                break;

            case 0:
                printf("\nSmart Food Delivery System closed.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

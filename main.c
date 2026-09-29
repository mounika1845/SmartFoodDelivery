```c
#include <stdio.h>

#include "restaurant.h"
#include "customer.h"
#include "order.h"
#include "queue.h"
#include "priority_queue.h"
#include "graph.h"
#include "eta.h"


/* ---------------------------------------------------------
   Display the information handled by Member 1
   --------------------------------------------------------- */
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


/* ---------------------------------------------------------
   Delivery operations handled by Member 2
   --------------------------------------------------------- */
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
                    printf("\nNormal order %d has been selected for delivery.\n",
                           orderId);
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
                    printf("\nPriority order %d has been selected for delivery.\n",
                           orderId);
                }
                break;

            case 0:
                return;

            default:
                printf("\nInvalid option.\n");
        }
    }
}


/* ---------------------------------------------------------
   Member 3: display the delivery network
   --------------------------------------------------------- */
void roadNetworkSection()
{
    printf("\n");
    printf("====================================\n");
    printf("        DELIVERY ROAD NETWORK\n");
    printf("====================================\n");

    printRoadMap();
}


/* ---------------------------------------------------------
   Member 3: shortest path operation
   --------------------------------------------------------- */
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


/* ---------------------------------------------------------
   Member 4: ETA
   --------------------------------------------------------- */
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


/* ---------------------------------------------------------
   Member 4: project status
   --------------------------------------------------------- */
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

    completed =
        orderTotal - normalWaiting - priorityWaiting;

    if (completed < 0)
    {
        completed = 0;
    }

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


/* ---------------------------------------------------------
   Main application
   --------------------------------------------------------- */
int main()
{
    OrderQueue normalQueue;
    PriorityQueue urgentQueue;

    int choice;


    /* Load project information */
    loadRestaurants();
    loadCustomers();
    prepareOrders();

    /* Create the delivery map */
    createRoadMap();

    /* Prepare normal delivery queue */
    queueStart(&normalQueue);

    addToQueue(&normalQueue, 101);
    addToQueue(&normalQueue, 103);
    addToQueue(&normalQueue, 104);


    /* Prepare priority delivery queue */
    priorityStart(&urgentQueue);

    addPriorityOrder(&urgentQueue, 101, 2);
    addPriorityOrder(&urgentQueue, 102, 5);
    addPriorityOrder(&urgentQueue, 103, 3);
    addPriorityOrder(&urgentQueue, 104, 4);


    /* Main program loop */
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

            case 0:
                printf("\nSmart Food Delivery System closed.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 0);


    return 0;
}

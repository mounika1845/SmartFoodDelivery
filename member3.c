#include <stdio.h>
#include "graph.h"

static void printRoute(
    int route[],
    int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%c", 'A' + route[i]);

        if (i != count - 1)
            printf(" -> ");
    }

    printf("\n");
}

int main(void)
{
    int source;
    int destination;

    int route[LOCATION_COUNT];
    int routeSize;

    int totalDistance;

    createRoadMap();

    printf("====================================\n");
    printf(" SMART FOOD DELIVERY - MEMBER 3\n");
    printf("====================================\n");

    printRoadMap();

    printf("\nLocations:\n");
    printf("A B C D E F\n");

    printf("\nEnter source location (0-5): ");
    scanf("%d", &source);

    printf("Enter destination location (0-5): ");
    scanf("%d", &destination);

    if (source < 0 || source >= LOCATION_COUNT ||
        destination < 0 || destination >= LOCATION_COUNT)
    {
        printf("Invalid location.\n");
        return 0;
    }

    totalDistance =
        shortestRoute(
            source,
            destination,
            route,
            &routeSize
        );

    if (totalDistance == -1)
    {
        printf("\nNo route available.\n");
    }
    else
    {
        printf("\n========== RESULT ==========\n");

        printf("Source      : %c\n",
               'A' + source);

        printf("Destination : %c\n",
               'A' + destination);

        printf("Shortest Route: ");

        printRoute(route, routeSize);

        printf("Distance    : %d km\n",
               totalDistance);

        printf("Algorithm   : Dijkstra's Algorithm\n");
    }

    return 0;
} 

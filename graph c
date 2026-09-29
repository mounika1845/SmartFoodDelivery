#include <stdio.h>
#include "graph.h"

int roadMap[LOCATION_COUNT][LOCATION_COUNT];

static void connectLocations(
    int first,
    int second,
    int distance)
{
    roadMap[first][second] = distance;
    roadMap[second][first] = distance;
}

void createRoadMap(void)
{
    int i;
    int j;

    for (i = 0; i < LOCATION_COUNT; i++)
    {
        for (j = 0; j < LOCATION_COUNT; j++)
        {
            roadMap[i][j] = 0;
        }
    }

    connectLocations(0, 1, 4);
    connectLocations(0, 2, 7);
    connectLocations(1, 2, 3);
    connectLocations(1, 3, 5);
    connectLocations(2, 3, 2);
    connectLocations(2, 4, 6);
    connectLocations(3, 5, 4);
    connectLocations(4, 5, 3);
}

void printRoadMap(void)
{
    int i;
    int j;

    printf("\n========== DELIVERY ROAD MAP ==========\n");

    for (i = 0; i < LOCATION_COUNT; i++)
    {
        for (j = i + 1; j < LOCATION_COUNT; j++)
        {
            if (roadMap[i][j] > 0)
            {
                printf("%c <-> %c : %d km\n",
                       'A' + i,
                       'A' + j,
                       roadMap[i][j]);
            }
        }
    }
}

int shortestRoute(
    int source,
    int target,
    int route[],
    int *routeSize)
{
    int distance[LOCATION_COUNT];
    int visited[LOCATION_COUNT];
    int previous[LOCATION_COUNT];

    int i;
    int j;
    int current;
    int best;

    for (i = 0; i < LOCATION_COUNT; i++)
    {
        distance[i] = NO_PATH;
        visited[i] = 0;
        previous[i] = -1;
    }

    distance[source] = 0;

    for (i = 0; i < LOCATION_COUNT; i++)
    {
        current = -1;
        best = NO_PATH;

        for (j = 0; j < LOCATION_COUNT; j++)
        {
            if (!visited[j] &&
                distance[j] < best)
            {
                best = distance[j];
                current = j;
            }
        }

        if (current == -1)
            break;

        visited[current] = 1;

        for (j = 0; j < LOCATION_COUNT; j++)
        {
            if (roadMap[current][j] > 0 &&
                !visited[j])
            {
                int newDistance;

                newDistance =
                    distance[current] +
                    roadMap[current][j];

                if (newDistance < distance[j])
                {
                    distance[j] = newDistance;
                    previous[j] = current;
                }
            }
        }
    }

    if (distance[target] == NO_PATH)
    {
        *routeSize = 0;
        return -1;
    }

    *routeSize = 0;
    current = target;

    while (current != -1)
    {
        route[*routeSize] = current;
        (*routeSize)++;

        current = previous[current];
    }

    for (i = 0; i < *routeSize / 2; i++)
    {
        int temporary;

        temporary = route[i];

        route[i] =
            route[*routeSize - i - 1];

        route[*routeSize - i - 1] =
            temporary;
    }

    return distance[target];
}

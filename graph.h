#ifndef GRAPH_H
#define GRAPH_H

#define LOCATION_COUNT 6
#define NO_PATH 99999

extern int roadMap[LOCATION_COUNT][LOCATION_COUNT];

void createRoadMap(void);

int shortestRoute(
    int source,
    int target,
    int route[],
    int *routeSize
);

void printRoadMap(void);

#endif

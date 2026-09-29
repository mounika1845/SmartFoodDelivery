#include <stdio.h>
#include "restaurant.h"

Restaurant restaurantList[REST_LIMIT];
int restaurantTotal = 0;

void loadRestaurants(void)
{
    Restaurant data[] =
    {
        {1, "Pizza Hub", "Location A"},
        {2, "Spice Kitchen", "Location B"},
        {3, "Burger Point", "Location C"},
        {4, "Biryani House", "Location D"}
    };

    int count = sizeof(data) / sizeof(data[0]);
    int i;

    for (i = 0; i < count; i++)
    {
        restaurantList[i] = data[i];
    }

    restaurantTotal = count;
}

void showRestaurants(void)
{
    int i;

    printf("\n===== RESTAURANTS =====\n");

    for (i = 0; i < restaurantTotal; i++)
    {
        printf("ID: %d | %s | %s\n",
               restaurantList[i].id,
               restaurantList[i].name,
               restaurantList[i].area);
    }
}

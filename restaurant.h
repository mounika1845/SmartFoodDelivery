#ifndef RESTAURANT_H
#define RESTAURANT_H

#define REST_LIMIT 20

typedef struct
{
    int id;
    char name[40];
    char area[30];
} Restaurant;

extern Restaurant restaurantList[REST_LIMIT];
extern int restaurantTotal;

void loadRestaurants(void);
void showRestaurants(void);

#endif

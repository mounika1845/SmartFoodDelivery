#ifndef ORDER_H
#define ORDER_H

#define ORDER_LIMIT 30

typedef struct
{
    int orderId;
    int restaurantId;
    int customerId;
    char item[40];
    int priority;
    char state[25];
} Order;

extern Order orderList[ORDER_LIMIT];
extern int orderTotal;

void prepareOrders(void);
void printOrders(void);

#endif

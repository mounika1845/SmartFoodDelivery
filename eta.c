#include <stdio.h>
#include "eta.h"

int estimateMinutes(
    float distance,
    float speed)
{
    float hours;

    if (distance < 0 || speed <= 0)
        return -1;

    hours = distance / speed;

    return (int)(hours * 60 + 0.5f);
}

void showDeliverySummary(
    int total,
    int pending,
    int delivering,
    int completed)
{
    printf("\n========== DELIVERY DASHBOARD ==========\n");

    printf("Total Orders       : %d\n", total);
    printf("Pending Orders     : %d\n", pending);
    printf("Out for Delivery   : %d\n", delivering);
    printf("Completed Orders   : %d\n", completed);
}

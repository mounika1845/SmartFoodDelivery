#include <stdio.h>
#include "restaurant.h"
#include "customer.h"

int main(void)
{
    int choice;

    loadRestaurants();
    loadCustomers();

    do
    {
        printf("\n==============================\n");
        printf(" SMART FOOD DELIVERY - MEMBER 1\n");
        printf("==============================\n");
        printf("1. Display Restaurants\n");
        printf("2. Display Customers\n");
        printf("3. Display Both\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                showRestaurants();
                break;

            case 2:
                showCustomers();
                break;

            case 3:
                showRestaurants();
                showCustomers();
                break;

            case 0:
                printf("\nMember 1 module closed.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}

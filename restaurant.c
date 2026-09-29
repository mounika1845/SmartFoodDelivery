#include <stdio.h>
#include "customer.h"

Customer customerList[CUSTOMER_LIMIT];
int customerTotal = 0;

void loadCustomers(void)
{
    Customer data[] =
    {
        {1, "Mounika", "Location A"},
        {2, "Ananya", "Location C"},
        {3, "Rahul", "Location D"},
        {4, "Kiran", "Location F"}
    };

    int count = sizeof(data) / sizeof(data[0]);
    int i;

    for (i = 0; i < count; i++)
    {
        customerList[i] = data[i];
    }

    customerTotal = count;
}

void showCustomers(void)
{
    int i;

    printf("\n===== CUSTOMERS =====\n");

    for (i = 0; i < customerTotal; i++)
    {
        printf("ID: %d | %s | %s\n",
               customerList[i].id,
               customerList[i].name,
               customerList[i].area);
    }
}

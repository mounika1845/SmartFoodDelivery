#ifndef CUSTOMER_H
#define CUSTOMER_H

#define CUSTOMER_LIMIT 20

typedef struct
{
    int id;
    char name[40];
    char area[30];
} Customer;

extern Customer customerList[CUSTOMER_LIMIT];
extern int customerTotal;

void loadCustomers(void);
void showCustomers(void);

#endif

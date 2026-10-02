#include "header.h"

void list(struct address *addr)
{
    printf("------------------------------------------------------------\n");
    printf("                     CONTACT LIST\n");
    printf("------------------------------------------------------------\n\n");

    if (addr->count == 0)
    {
        printf("No contacts found.\n");
        printf("------------------------------------------------------------\n");
        return;
    }

    printf("-------------------------------------------------------------------------------\n");

    printf("%-8s %-20s %-15s %-25s\n",
           "Index",
           "Name",
           "Phone",
           "Email");

    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < addr->count; i++)
    {
        printf("%-8d %-20s %-15s %-25s\n",
               i + 1,
               addr->c[i].name,
               addr->c[i].phone,
               addr->c[i].email);
    }

    printf("-------------------------------------------------------------------------------\n");

    printf("Total Contacts: %d\n", addr->count);
}
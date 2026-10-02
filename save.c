#include "header.h"

void save(struct address *addr)
{
    FILE *fp = fopen("data.txt", "w");

    if (fp == NULL)
    {
        printf("Error: Unable to open data.txt\n");
        return;
    }

    /*
     * Header
     */
    fprintf(fp, "%-10s%-20s%-20s%-20s\n",
            "index",
            "Name",
            "Phone",
            "Email");

    /*
     * Save all contacts
     */
    for (int i = 0; i < addr->count; i++)
    {
        fprintf(fp, "%-10d%-20s%-20s%-20s\n",
                i + 1,
                addr->c[i].name,
                addr->c[i].phone,
                addr->c[i].email);
    }

    fclose(fp);

    printf("Contacts saved successfully!\n");
}
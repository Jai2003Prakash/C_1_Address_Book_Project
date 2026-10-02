#include "header.h"

void initialization(struct address *addr)
{
    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("No saved contacts found.\n");
        printf("Starting with an empty Address Book.\n");
        return;
    }

    char line[200];

    /* Skip the header line */
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        int index;
        char name[50];
        char phone[20];
        char email[100];

        /*
         * Read old space-aligned format.
         * Name can contain spaces.
         */
        if (sscanf(line,
                   "%d %49[^0-9] %19s %99s",
                   &index,
                   name,
                   phone,
                   email) != 4)
        {
            continue;
        }

        /* Remove trailing spaces from name */
        int len = strlen(name);

        while (len > 0 && name[len - 1] == ' ')
        {
            name[len - 1] = '\0';
            len--;
        }

        if (addr->count >= MAX_CONTACTS)
        {
            break;
        }

        strcpy(addr->c[addr->count].name, name);
        strcpy(addr->c[addr->count].phone, phone);
        strcpy(addr->c[addr->count].email, email);

        addr->count++;
    }

    fclose(fp);

    printf("Contacts loaded successfully!\n");
    printf("Total contacts loaded: %d\n", addr->count);
}
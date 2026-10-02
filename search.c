#include "header.h"

void search_list(struct address *addr, int *searched_index, int *del_ch)
{
    int choice = 0;

    *searched_index = -1;

    /* Clear previous search results */
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        del_ch[i] = 0;
    }

    printf("------------------------------------------------------------\n");
    printf("                   SEARCH CONTACT\n");
    printf("------------------------------------------------------------\n");

    printf("1. Search by Name\n");
    printf("2. Search by Phone Number\n");
    printf("3. Search by Email\n");

    while (1)
    {
        printf("Enter Your Choice: ");

        if (scanf("%d", &choice) == 1 &&
            choice >= 1 && choice <= 3)
        {
            while (getchar() != '\n')
                ;
            break;
        }

        printf("Invalid Entry\n");
        while (getchar() != '\n')
            ;
    }

    switch (choice)
    {
    case 1:
    {
        char name[20];

        name_validation(name);

        search_name(addr, name, searched_index, del_ch);

        break;
    }

    case 2:
    {
        char phone[20];

        phone_validation(phone);

        search_phone(addr, phone, searched_index);

        printf("--------------------------------------------------------------------------\n");

        if (*searched_index != -1)
        {
            printf("%-10s %-20s %-20s %-20s\n",
                   "Index",
                   "Name",
                   "Phone",
                   "Email");

            printf("%-10d %-20s %-20s %-20s\n",
                   *searched_index + 1,
                   addr->c[*searched_index].name,
                   addr->c[*searched_index].phone,
                   addr->c[*searched_index].email);
        }
        else
        {
            printf("                           Not Found\n");
        }

        printf("--------------------------------------------------------------------------\n");

        break;
    }

    case 3:
    {
        char email[20];

        email_validation(email);

        search_email(addr, email, searched_index);

        printf("--------------------------------------------------------------------------\n");

        if (*searched_index != -1)
        {
            printf("%-10s %-20s %-20s %-20s\n",
                   "Index",
                   "Name",
                   "Phone",
                   "Email");

            printf("%-10d %-20s %-20s %-20s\n",
                   *searched_index + 1,
                   addr->c[*searched_index].name,
                   addr->c[*searched_index].phone,
                   addr->c[*searched_index].email);
        }
        else
        {
            printf("                           Not Found\n");
        }

        printf("--------------------------------------------------------------------------\n");

        break;
    }
    }
}

/* Search contact by name */
void search_name(struct address *addr,
                 char *name,
                 int *searched_index,
                 int *del_ch)
{
    int found = 0;

    *searched_index = -1;

    printf("--------------------------------------------------------------------------\n");

    printf("%-10s %-20s %-20s %-20s\n",
           "Index",
           "Name",
           "Phone",
           "Email");

    for (int i = 0; i < addr->count; i++)
    {
        if (strcmp(addr->c[i].name, name) == 0)
        {
            printf("%-10d %-20s %-20s %-20s\n",
                   i + 1,
                   addr->c[i].name,
                   addr->c[i].phone,
                   addr->c[i].email);

            found = 1;
            *searched_index = i;
            del_ch[i] = 1;
        }
    }

    if (!found)
    {
        printf("                           Not Found\n");
    }

    printf("--------------------------------------------------------------------------\n");
}

/* Search contact by phone number */
void search_phone(struct address *addr,
                  char *phone,
                  int *searched_index)
{
    *searched_index = -1;

    for (int i = 0; i < addr->count; i++)
    {
        if (strcmp(addr->c[i].phone, phone) == 0)
        {
            *searched_index = i;
            return;
        }
    }
}

/* Search contact by email */
void search_email(struct address *addr,
                  char *email,
                  int *searched_index)
{
    *searched_index = -1;

    for (int i = 0; i < addr->count; i++)
    {
        if (strcmp(addr->c[i].email, email) == 0)
        {
            *searched_index = i;
            return;
        }
    }
}
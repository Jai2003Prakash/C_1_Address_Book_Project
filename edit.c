#include "header.h"

void edit_contact(struct address *addr, int *searched_index)
{
    int choice = 0;
    int del_ch[MAX_CONTACTS] = {0};
    int match_count = 0;

    *searched_index = -1;

    printf("------------------------------------------------------------\n");
    printf("                     EDIT CONTACT\n");
    printf("------------------------------------------------------------\n");

    printf("Search the contact you want to edit.\n");

    search_list(addr, searched_index, del_ch);

    /* Count matching contacts */
    for (int i = 0; i < addr->count; i++)
    {
        if (del_ch[i] == 1)
        {
            match_count++;
        }
    }

    /* If multiple contacts have the same name */
    if (match_count > 1)
    {
        while (1)
        {
            printf("Multiple contacts found.\n");
            printf("Enter the contact index to edit: ");

            if (scanf("%d", searched_index) == 1 &&
                *searched_index >= 1 &&
                *searched_index <= addr->count &&
                del_ch[*searched_index - 1] == 1)
            {
                while (getchar() != '\n')
                    ;

                *searched_index = *searched_index - 1;
                break;
            }

            printf("Invalid index.\n");
            while (getchar() != '\n')
                ;
        }
    }

    if (*searched_index == -1)
    {
        printf("Contact not found.\n");
        return;
    }

    printf("\nWhat do you want to edit?\n");
    printf("1. Edit Name\n");
    printf("2. Edit Phone Number\n");
    printf("3. Edit Email\n");

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

        strcpy(addr->c[*searched_index].name, name);

        printf("Name updated successfully.\n");
        break;
    }

    case 2:
    {
        char phone[20];
        int duplicate_index;

        while (1)
        {
            phone_validation(phone);

            duplicate_index = -1;
            search_phone(addr, phone, &duplicate_index);

            /*
             * The same contact's existing phone number
             * is allowed.
             */
            if (duplicate_index == -1 ||
                duplicate_index == *searched_index)
            {
                break;
            }

            printf("Phone number already exists!\n");
            printf("Please enter another number.\n");
        }

        strcpy(addr->c[*searched_index].phone, phone);

        printf("Phone number updated successfully.\n");
        break;
    }

    case 3:
    {
        char email[20];
        int duplicate_index;

        while (1)
        {
            email_validation(email);

            duplicate_index = -1;
            search_email(addr, email, &duplicate_index);

            /*
             * The same contact's existing email
             * is allowed.
             */
            if (duplicate_index == -1 ||
                duplicate_index == *searched_index)
            {
                break;
            }

            printf("Email already exists!\n");
            printf("Please enter another email.\n");
        }

        strcpy(addr->c[*searched_index].email, email);

        printf("Email updated successfully.\n");
        break;
    }
    }
}
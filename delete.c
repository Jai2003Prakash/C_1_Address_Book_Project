#include "header.h"

void delete_contact(struct address *addr)
{
    char confirm;
    int searched_index = -1;
    int del_ch[MAX_CONTACTS] = {0};
    int match_count = 0;

    printf("------------------------------------------------------------\n");
    printf("                    DELETE CONTACT\n");
    printf("------------------------------------------------------------\n");

    if (addr->count == 0)
    {
        printf("No contacts available to delete.\n");
        return;
    }

    printf("Search the contact you want to delete.\n");

    search_list(addr, &searched_index, del_ch);

    /* Count matching contacts */
    for (int i = 0; i < addr->count; i++)
    {
        if (del_ch[i] == 1)
        {
            match_count++;
        }
    }

    /*
     * If multiple contacts match the name,
     * ask the user to select the index.
     */
    if (match_count > 1)
    {
        while (1)
        {
            printf("Multiple contacts found.\n");
            printf("Enter the contact index to delete: ");

            if (scanf("%d", &searched_index) == 1 &&
                searched_index >= 1 &&
                searched_index <= addr->count &&
                del_ch[searched_index - 1] == 1)
            {
                while (getchar() != '\n')
                    ;

                searched_index--;
                break;
            }

            printf("Invalid index.\n");
            while (getchar() != '\n')
                ;
        }
    }

    if (searched_index == -1)
    {
        printf("Contact not found.\n");
        return;
    }

    printf("\nSelected contact:\n");

    printf("Name  : %s\n",
           addr->c[searched_index].name);

    printf("Phone : %s\n",
           addr->c[searched_index].phone);

    printf("Email : %s\n",
           addr->c[searched_index].email);

    printf("\nAre you sure you want to delete this contact? (y/n): ");

    scanf(" %c", &confirm);

    while (getchar() != '\n')
        ;

    if (confirm == 'y' || confirm == 'Y')
    {
        /*
         * Shift all contacts after the deleted
         * contact one position to the left.
         */
        for (int i = searched_index; i < addr->count - 1; i++)
        {
            addr->c[i] = addr->c[i + 1];
        }

        addr->count--;

        printf("\nContact deleted successfully.\n");
        printf("Total contacts: %d\n", addr->count);
    }
    else
    {
        printf("\nContact was not deleted.\n");
    }
}
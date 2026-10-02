#include "header.h"

int main()
{
    int choice = 0;
    int del_ch[MAX_CONTACTS] = {0};

    struct address addr = {0};

    int searched_index = -1;

    printf("------------------------------------------------------------\n");
    printf("                 WELCOME TO ADDRESS BOOK\n");
    printf("------------------------------------------------------------\n");

    /* Load previously saved contacts */
    initialization(&addr);

    while (1)
    {
        printf("\n");
        printf("1. Create Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. List Contacts\n");
        printf("6. Save and Exit\n");
        printf("\n");

        while (1)
        {
            printf("Enter Your Choice: ");

            if (scanf("%d", &choice) == 1 &&
                choice >= 1 && choice <= 6)
            {
                while (getchar() != '\n')
                    ;
                break;
            }

            printf("Invalid Entry\n");

            while (getchar() != '\n')
                ;

            choice = 0;
        }

        switch (choice)
        {
        case 1:
            create_contact(&addr);
            break;

        case 2:
            searched_index = -1;
            search_list(&addr, &searched_index, del_ch);
            break;

        case 3:
            searched_index = -1;
            edit_contact(&addr, &searched_index);
            break;

        case 4:
            delete_contact(&addr);
            break;

        case 5:
            list(&addr);
            break;

        case 6:
            save(&addr);
            printf("Text File Saved..Exiting....\n");
            return 0;
        }

        choice = 0;
    }

    return 0;
}
#include "header.h"

void create_contact(struct address *addr)
{
    int search_index = -1;

    if (addr->count >= MAX_CONTACTS)
    {
        printf("\nAddress book is full!\n");
        return;
    }

    printf("------------------------------------------------------------\n");
    printf("                  ENTER CREATE CONTACT\n");
    printf("------------------------------------------------------------\n");

    /* Get and validate name */
    name_validation(addr->c[addr->count].name);

    /* Get and validate unique phone number */
    while (1)
    {
        phone_validation(addr->c[addr->count].phone);

        search_index = -1;
        search_phone(addr,
                     addr->c[addr->count].phone,
                     &search_index);

        if (search_index == -1)
        {
            break;
        }

        printf("Phone number already exists!\n");
        printf("Please enter another phone number.\n");
    }

    /* Get and validate unique email */
    while (1)
    {
        email_validation(addr->c[addr->count].email);

        search_index = -1;
        search_email(addr,
                     addr->c[addr->count].email,
                     &search_index);

        if (search_index == -1)
        {
            break;
        }

        printf("Email already exists!\n");
        printf("Please enter another email address.\n");
    }

    addr->count++;

    printf("\nContact created successfully!\n");
    printf("Total contacts: %d\n", addr->count);
}

/* Validate contact name */
void name_validation(char *name)
{
    int valid;

    do
    {
        valid = 1;

        printf("Enter Name: ");

        if (scanf("%19[^\n]", name) != 1)
        {
            valid = 0;
            printf("Name cannot be empty.\n");
        }

        while (getchar() != '\n')
            ;

        if (!valid)
        {
            continue;
        }

        /* Name cannot start with a space */
        if (name[0] == ' ')
        {
            printf("Name should not start with a space.\n");
            valid = 0;
            continue;
        }

        /* Check allowed characters */
        for (int i = 0; name[i] != '\0'; i++)
        {
            char ch = name[i];

            if (!((ch >= 'A' && ch <= 'Z') ||
                  (ch >= 'a' && ch <= 'z') ||
                  ch == ' ' ||
                  ch == '.'))
            {
                printf("Invalid name. Use alphabets, spaces and dots only.\n");
                valid = 0;
                break;
            }
        }

    } while (!valid);
}

/* Validate phone number */
void phone_validation(char *phone)
{
    int valid;

    do
    {
        valid = 1;

        printf("Enter Phone Number: ");

        if (scanf("%19s", phone) != 1)
        {
            valid = 0;
        }

        while (getchar() != '\n')
            ;

        if (strlen(phone) != 10)
        {
            printf("Phone number must contain exactly 10 digits.\n");
            valid = 0;
            continue;
        }

        for (int i = 0; phone[i] != '\0'; i++)
        {
            if (phone[i] < '0' || phone[i] > '9')
            {
                printf("Phone number must contain digits only.\n");
                valid = 0;
                break;
            }
        }

        if (!valid)
        {
            continue;
        }

        if (phone[0] < '6' || phone[0] > '9')
        {
            printf("Phone number must start with 6, 7, 8 or 9.\n");
            valid = 0;
        }

    } while (!valid);
}

/* Validate email address */
void email_validation(char *email)
{
    int valid;

    do
    {
        valid = 1;

        printf("Enter Email: ");

        if (scanf("%19s", email) != 1)
        {
            valid = 0;
        }

        while (getchar() != '\n')
            ;

        if (!valid)
        {
            continue;
        }

        /* Email cannot contain spaces */
        if (strchr(email, ' ') != NULL)
        {
            printf("Email cannot contain spaces.\n");
            valid = 0;
            continue;
        }

        /* Find @ */
        char *at = strchr(email, '@');

        if (at == NULL || at == email)
        {
            printf("Email must contain a valid '@'.\n");
            valid = 0;
            continue;
        }

        /* Only one @ */
        if (strchr(at + 1, '@') != NULL)
        {
            printf("Email can contain only one '@'.\n");
            valid = 0;
            continue;
        }

        /* Dot must exist after @ */
        char *dot = strchr(at + 1, '.');

        if (dot == NULL || dot == at + 1 || *(dot + 1) == '\0')
        {
            printf("Email must contain a valid domain.\n");
            valid = 0;
            continue;
        }

        /* Dot cannot be the last character */
        if (email[strlen(email) - 1] == '.')
        {
            printf("Email cannot end with '.'.\n");
            valid = 0;
        }

    } while (!valid);
}
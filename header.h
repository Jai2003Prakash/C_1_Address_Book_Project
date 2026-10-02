#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact
{
    char name[20];
    char phone[20];
    char email[20];
};

struct address
{
    struct contact c[MAX_CONTACTS];
    int count;
};

/* Initialization */
void initialization(struct address *addr);

/* Create Contact */
void create_contact(struct address *addr);
void name_validation(char *name);
void phone_validation(char *phone);
void email_validation(char *email);

/* Search Contact */
void search_list(struct address *addr, int *searched_index, int *del_ch);
void search_name(struct address *addr, char *name,
                 int *searched_index, int *del_ch);
void search_phone(struct address *addr, char *phone,
                  int *searched_index);
void search_email(struct address *addr, char *email,
                  int *searched_index);

/* Edit Contact */
void edit_contact(struct address *addr, int *searched_index);

/* Delete Contact */
void delete_contact(struct address *addr);

/* List Contacts */
void list(struct address *addr);

/* Save Contacts */
void save(struct address *addr);

#endif
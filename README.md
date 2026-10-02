Address Book Management System in C
A simple console-based Address Book Management System developed in C.

This project allows users to manage contact information such as name, phone number, and email. It supports basic CRUD operations and stores the contacts in a .txt file so that the saved data can be loaded when the program is run again.

Features
Create new contacts
Search contacts
Edit existing contacts
Delete contacts
Display all saved contacts
Validate name, phone number, and email
Save contacts to a .txt file
Load previously saved contacts when the program starts
Handles invalid user input
Concepts Used
C Programming
Structures
Pointers
Functions
Strings
Arrays
File Handling
Multi-file Programming
Input Validation
Loops and Conditional Statements
Project Structure
C_1_Address_Book_Project/
│
├── main.c          # Main program and menu
├── header.h        # Structure, declarations and common definitions
├── create.c        # Creates new contacts
├── search.c        # Searches contacts
├── edit.c          # Modifies existing contacts
├── delete.c        # Deletes contacts
├── list.c          # Displays all contacts
├── initialize.c    # Loads previously saved contacts
├── save.c          # Saves contacts to file
│
└── data.txt        # Stores saved contact information
How It Works
The program starts by loading previously saved contacts from data.txt.

The user can then select an operation from the menu:

1. Create Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List Contacts
6. Save & Exit
Contact details are validated before they are stored. When the user chooses Save & Exit, all contacts are written to the .txt file for future use.

Key Highlights
Developed using 14 functions
750+ lines of C code
Uses multiple source files for better organization
Implements complete CRUD operations
Uses file handling for data persistence
Includes input validation for contact details
Learning Outcome
This project helped me strengthen my understanding of C programming fundamentals and apply concepts such as structures, pointers, functions, strings, file handling, and multi-file programming in a practical application.

Author
Lokeswar Reddy Pathakunta

If you find this project useful, feel free to explore the repository.

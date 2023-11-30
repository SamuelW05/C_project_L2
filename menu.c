#include "menu.h"
#include <stdio.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int menu() {
    int choice;
    printf(" 1. Search for a contact \n"
           "2. View a contact's appointments\n"
           "3. Create a contact \n"
           "4. Create an appointment for a contact \n"
           "5. Delete an appointment\n"
           "6. Save the file of all appointments\n"
           "7. Load an appointment file \n"
           "8. Provide the calculation times for inserting a new contact \n\n");

    printf("Choose an action between 1 and 8: ");

    if (scanf("%d", &choice) != 1) {
        // Handle the case where the input is not an integer
        printf("Invalid input. Please enter a valid number.\n\n");
        clearInputBuffer();  // Clear the input buffer
        return -1;
    }

    if (choice >= 1 && choice <= 8) {
        return choice; // Exit the loop if a valid choice is entered
    } else {
        printf("Invalid choice. Please choose a number between 1 and 8.\n\n");
        clearInputBuffer();  // Clear the input buffer
        return -1;
    }
}

void choice(int a) {
    switch (a) {
        case 1:
            printf("Case 1\n");
            break;
        case 2:
            printf("Case 2\n");
            break;
        case 3:
            printf("Case 3\n");
            break;
        case 4:
            printf("Case 4\n");
            break;
        case 5:
            printf("Case 5\n");
            break;
        case 6:
            printf("Case 6\n");
            break;
        case 7:
            printf("Case 7\n");
            break;
        case 8:
            printf("Case 8\n");
            break;
        default:
            break;
    }
}

void main_function() {
    int b = menu();
    choice(b);
}

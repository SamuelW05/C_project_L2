#include "menu.h"
#include <stdio.h>
#include "string.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void menu(ht_d_contact_list list) {
    int choice;
    printf("1. Search for a contact \n"
           "2. View a contact's appointments\n"
           "3. Create a contact \n"
           "4. Create an appointment for a contact \n"
           "5. Delete an appointment\n"
           "6. Save the file of all appointments\n"
           "7. Load an appointment file \n"
           "8. Provide the calculation times for inserting a new contact \n\n");

    printf("     -> Choose an action between 1 and 8 : ");

    if (scanf("%d", &choice) != 1) {
        // Handle the case where the input is not an integer
        printf("Invalid input, please enter a valid number.\n\n\n");
        clearInputBuffer();  // Clear the input buffer
        menu(list);
        return;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Vider le flux d'entrée
    }
    if (choice >= 1 && choice <= 8) {
        choose(choice, list);
        menu(list);
        return;
    }
    else {
        printf("Invalid choice, please choose a number between 1 and 8.\n\n\n");
        clearInputBuffer();  // Clear the input buffer
        menu(list);
        return;
    }
}

void choose(int a, ht_d_contact_list list) {
    switch (a) {
        case 1:
            search_for_a_contact(list);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
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

void search_for_a_contact(ht_d_contact_list list){
    printf("\n\nSearch for contact, enter the name letter by letter :\n");
    char name[50] = "";
    p_contact previous = list.head[0];
    int i = 0;

    while (previous != NULL){
        if (i == 0)
            printf("     -> Enter the 1st character of the name : ");
        else
            printf("     -> Current name :  [ %s... ]\n", name);
        if (i == 1)
            printf("     -> Enter the 2nd character of the name : ");
        else if (i == 2)
            printf("     -> Enter the 3rd character of the name : ");
        else if (i > 2)
            printf("     -> Enter the %dth character of the name : ", i+1);
        strcat(name, scanString());
        previous = search_contact(&list, name, previous);
        i++;
    }
}


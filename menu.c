#include "menu.h"
#include <stdio.h>
#include "string.h"
#include "conio.h"
#include <unistd.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int menu(ht_d_contact_list list) {
    int choice;
    printf("1. Search for a contact \n"
           "2. View a contact's appointments\n"
           "3. Create a contact \n"
           "4. Create an appointment for a contact \n"
           "5. Provide the calculation times for inserting a new contact \n"
           "6. Display the level list\n"
           "7. Quit\n\n");

    printf("     -> Choose an action between 1 and 7 : ");

    if (scanf("%d", &choice) != 1) {
        // Handle the case where the input is not an integer
        printf("Invalid input, please enter a valid number.\n\n\n");
        clearInputBuffer();  // Clear the input buffer

        menu(list);
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Vider le flux d'entrée
    }
    if (choice >= 1 && choice <= 6) {
        choose(choice, list);
        menu(list);
        return 1;
    }
    else if (choice == 7)
        return 0;
    else {
        printf("Invalid choice, please choose a number between 1 and 8.\n\n\n");
        clearInputBuffer();  // Clear the input buffer
        menu(list);
        return 1;
    }
}

void choose(int a, ht_d_contact_list list) {

    switch (a) {
        case 1:
            system("cls");
            search_for_a_contact(list,1);
            system("cls");
            break;
        case 2:
            system("cls");
            search_for_a_contact(list,2);
            system("cls");
            break;
        case 3:
            system("cls");
            insert_a_contact_menu(&list);
            system("cls");
            break;
        case 4:
            system("cls");
            search_for_a_contact(list,3);
            system("cls");
            break;
        case 5:
            system("cls");
            compare_time();
            sleep(4);
            system("cls");
            break;
        case 6:
            system("cls");
            display_all_contact_levels(list);
            printf("\n\n");
        default:
            break;
    }
}

void search_for_a_contact(ht_d_contact_list list,int a){
    printf("Search for contact, enter the name letter by letter :\n");
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
        previous = search_contact(&list, name, previous,a);
        i++;
    }
}

void insert_a_contact_menu(ht_d_contact_list* list){
    printf("Enter the first name of the contact: ");
    char name[20];
    char lastname[20];
    scanf("%s",name);
    printf("Enter the last name of the contact: ");
    scanf("%s",lastname);
    insert_in_good_order_cell(list,lastname,name);
    printf("\nContact inserted in the list\n");
    sleep(2);
}


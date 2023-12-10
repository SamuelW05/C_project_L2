#include <stdio.h>
#include "level_lists.h"
#include "agenda.h"
#include "contact.h"
#include "string.h"
#include "menu.h"
#include "stdlib.h"

int main() {
    printf("Loading...\n\n\n");
    ht_d_contact_list list = create_contact_list();
    while (1){
        menu(list);
    }
    return 0;
    /*
    ht_d_contact_list list3 = create_contact_list();

    printf("Search for contact, enter the name letter by letter :\n\n");
    char name[50] = "";
    p_contact previous = list3.head[0];
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
        previous = search_contact(&list3, name, previous);
        i++;

        if
    }
    return 0;
    /*

    display_all_contact_levels(list3);
    return 0;

    display_contacts_at_levels(list3, 0);
    
    printf("%d\n", count_lines("D:\\OneDrive\\CLION\\C_project_L2-main\\names_example.txt"));
    t_d_list list2 = create_contact_list();
    display_all_levels(list2);
    t_d_list list = create_empty_list(5);

    //level 0
    insert_a_cell_with_increasing_order(&list, 91, 3);
    insert_a_cell_with_increasing_order(&list, 59, 3);
    insert_a_cell_with_increasing_order(&list, 59, 5);
    insert_a_cell_with_increasing_order(&list, 59, 1);
    insert_a_cell_with_increasing_order(&list, 32, 5);
    insert_a_cell_with_increasing_order(&list, 31, 2);
    insert_a_cell_with_increasing_order(&list, 25, 1);
    insert_a_cell_with_increasing_order(&list, 18, 4);
    //display_cells_at_levels(list,0);
    //display_cells_at_levels(list,4);
    display_all_levels(list);
    printf("%s", scanString());

*/
}
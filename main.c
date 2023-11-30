#include <stdio.h>
#include "level_lists.h"
#include "agenda.h"
#include "contact.h"

int main() {
    ht_d_contact_list list3 = create_contact_list();
    printf("%s", list3.head[0]->information->contact.name);
    //display_contacts_at_levels(list3, 0);
    /*
    printf("%d\n", count_lines("D:\\OneDrive\\CLION\\C_project_L2-main\\names_example.txt"));
    t_d_list list2 = create_contact_list();
    display_all_levels(list2);*/
    return 0;
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


}
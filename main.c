#include <stdio.h>
#include "level_lists.h"

int main() {
    t_d_list list = create_empty_list(5);

    //level 0
    insert_a_cell(&list, 91, 3);
    insert_a_cell(&list, 59, 1);
    insert_a_cell(&list, 59, 5);
    insert_a_cell(&list, 56, 3);
    insert_a_cell(&list, 32, 5);
    insert_a_cell(&list, 31, 2);
    insert_a_cell(&list, 25, 1);
    insert_a_cell(&list, 18, 4);
    //display_cells_at_levels(list,0);
    //display_cells_at_levels(list,4);
    display_all_levels(list);


    return 0;
}

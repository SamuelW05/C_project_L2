#include <stdio.h>
#include "level_lists.h"
#include "agenda.h"

int main() {
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

    return 0;
}

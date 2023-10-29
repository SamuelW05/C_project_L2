#ifndef PROJECT1_LEVEL_LISTS_H
#define PROJECT1_LEVEL_LISTS_H
#include "level_cells.h"
typedef struct s_d_list
{
    int nb_max_levels;
    t_d_cell **head;
} t_d_list;

t_d_list create_empty_list(int);
void display_cells_at_levels(t_d_list list, int level);
void display_all_levels(t_d_list list);
void insert_a_cell(t_d_list* list, int val, int cell_levels);
void insert_a_cell_with_increasing_order(t_d_list* list, int val, int cell_levels);
#endif //PROJECT1_LEVEL_LISTS_H

#include "level_cells.h"
#include "stdlib.h"
#include "stdio.h"

p_cell create_cell(int value, int nb_levels)
{
    p_cell cell = (p_cell)malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->nb_levels = nb_levels;
    cell->level = (p_cell*) malloc(nb_levels*sizeof(p_cell));
    for (int i = 0; i < nb_levels; i++) {
        cell->level[i] = NULL;
    }
    return cell;
}

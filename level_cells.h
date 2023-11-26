#ifndef PROJECT1_LEVEL_CELLS_H
#define PROJECT1_LEVEL_CELLS_H
#include "stdio.h"

typedef struct s_d_cell
{
    int value;
    int nb_levels;
    struct s_d_cell **level;
} t_d_cell;

typedef t_d_cell* p_cell;

p_cell create_cell(int, int);

#endif



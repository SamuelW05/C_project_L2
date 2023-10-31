#include <stdio.h>
#include <stdlib.h>
#include "level_list_dico.h"
#include "level_lists.h"
#include "math.h"


t_d_list create_list_dico(int levels) {
    t_d_list list = create_empty_list(levels);
    int nb_val = (int) pow(2, levels) - 1;
    int *val_level = (int *) malloc(nb_val * sizeof(int));
    for (int i = 0; i < nb_val; i++) {
        val_level[i] = 0;
    }
    int n = levels;
    int k = 0;
    int j;
    while (k < n - 1) {
        j = (int) pow(2, (k + 1)) - 1;
        while (j < nb_val - 1) {
            val_level[j]++;
            j += (int) pow(2, (k + 1));
        }
        k++;

    }

    for (int i = nb_val - 1; i >= 0; i--) {
        insert_a_cell(&list, i + 1, val_level[i] + 1);

}
    return list;
}

    int classic_search(int val, t_d_list list){
    p_cell temp = list.head[0];
    int i = 0;
    while(temp->level[0]!= NULL){
        if(temp->value == val){
            return val;
            break;}
        else {
            temp = temp->level[0];
            i++;
            }
            }
    return -1;
    }

int dico_search(int val, t_d_list list) {
    int level = list.nb_max_levels - 1;
    p_cell temp = list.head[level];
    p_cell prev = NULL;

    while (level >= 0 && temp != NULL) {
        if (temp->value == val) {
            return val;
        } else if (temp->value < val) {
            prev = temp;

            if (temp->level[level] == NULL || temp->level[level]->value > val) {
                level--;
            } else {
                temp = temp->level[level];
            }
        } else {
            level--;
            temp = list.head[level];
            prev = NULL;
        }
    }
    if (prev != NULL && temp != NULL && prev->value < val && temp->value > val) {
        return val;
    }

    return -1;
}

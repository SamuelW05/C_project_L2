#include "level_lists.h"
#include "stdlib.h"
#include "stdio.h"

int is_empty_level(t_d_list list,int level){// function not demanded
    if(list.head[level] == NULL){
        return 1;
    } else{
        return 0;
    }
}

t_d_list create_empty_list(int levels){
    t_d_list list;
    list.nb_max_levels = levels;
    list.head = (p_cell*) malloc(levels*sizeof(p_cell));
    for (int i = 0; i < list.nb_max_levels; i++) {
        list.head[i] = NULL;
    }

    return list;
}

void insert_a_cell(t_d_list* list, int val, int cell_levels){
        p_cell new = create_cell(val, cell_levels);

        for(int i = 0; i< cell_levels; i++) {

            new->level[i] = list->head[i];

            list->head[i] = new;
        }
}

void display_cells_at_levels(t_d_list list, int level){
    if(list.nb_max_levels-1< level){
        printf("We can't display");// Au cas ou si on a des erreurs mais on peut effacer
    } else{
            printf("[list head_%d @-]", level);
            p_cell temp = list.head[level];
            p_cell ogcell = list.head[0];
            int index;
            if(is_empty_level(list, level) != 1) {
                while (temp != NULL) {
                    index = 0;
                    while ((ogcell != NULL) && (ogcell->value != temp->value)) {
                        ogcell = ogcell->level[0];
                        index++;
                    }
                    for (int j = 0; j < index; j++) {
                        printf("-----------");
                    }
                    printf("-->[ %d|@-]", temp->value);
                    ogcell = ogcell->level[0];
                    temp = temp->level[level];
                }
            }
            index= 0;
            while ((ogcell!= NULL)){
                ogcell = ogcell->level[0];
                index++;
            }
            for (int j = 0; j < index; j++) {
                printf("-----------");
            }
            printf("-->NULL\n");
    }
}

void display_all_levels(t_d_list list){
    for(int i = 0; i<list.nb_max_levels; i++){
        display_cells_at_levels(list,i);
    }
}

void insert_a_cell_with_increasing_order(t_d_list* list, int val, int cell_levels){
    if (is_empty_level(*list,0) != 1){
        if(list->head[0]->value >= val){
            insert_a_cell(list,val,cell_levels);
        }else {
            p_cell new = create_cell(val,cell_levels);
            for(int i = 0; i< cell_levels; i++){
                p_cell temp = list->head[i];
                p_cell prev = temp;
                while ((temp != NULL)&& (val >= temp->value)){
                    prev = temp;
                    temp = temp->level[i];
                }
                if(prev!=temp){
                    prev->level[i] = new;
                    new->level[i] = temp;
                } else{
                    new->level[i] = temp;
                    list->head[i] = new;
                }
            }
        }
    } else{
        insert_a_cell(list,val,cell_levels);
    }
}


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
    if(list.nb_max_levels< level){
        printf("We can't display");// Au cas ou si on a des erreurs mais on peut effacer
    } else{
        if(is_empty_level(list, level) != 1) {
            printf("\n[list head_%d @-]", level);
            p_cell temp = list.head[level];
            p_cell ogcell = list.head[0];
            int index;
            while (temp->level[level] != NULL) {
                index = 0;
                while ((ogcell->level[0] != NULL)&&(ogcell->value!= temp->value)){
                    ogcell = ogcell->level[0];
                    index++;
                }
                ogcell = ogcell->level[0];

                if(index != 0) {
                    for (int j = 0; j < index; j++) {
                        printf("----------");
                    }
                    for (int j = 0; j < index; j++) {
                        printf("-");
                    }
                }

                printf("-->[ %d|@-]", temp->value);
                temp = temp->level[level];

            }
            // Une iteration en plus car ca marche pas dans la boucle temp != NULL
            index = 0;
            while ((ogcell->level[0] != NULL)&&(ogcell->value!= temp->value)){
                ogcell = ogcell->level[0];
                index++;
            }
            if(index != 0) {
                for (int j = 0; j < index; j++) {
                    printf("----------");
                }
                for (int j = 0; j < index; j++) {
                    printf("-");
                }
            }
            printf("-->[ %d|@-]", temp->value);
            while (ogcell->level[0] != NULL){
                ogcell = ogcell->level[0];
                index++;
            }
            if(index != 0) {
                for (int j = 0; j < index-1; j++) {
                    printf("----------");
                }
                for (int j = 0; j < index+1; j++) {
                    printf("-");
                }
                printf(">");
            }
            if(level != 0){
                printf("NULL");
            } else{
                printf("-->NULL");
            }

        } else{
            printf("[list head_%d @-]--> NULL\n", level);
        }
    }
}
void display_all_levels(t_d_list list){
    for(int i = 0; i<list.nb_max_levels; i++){
        display_cells_at_levels(list,i);
    }
}

void insert_a_cell_with_increasing_order(t_d_list* list, int val, int cell_levels){
    if (is_empty_level(*list,0) != 1){
        p_cell new = create_cell(val,cell_levels);
        p_cell temp = list->head[0];
        p_cell prev = temp;
        if(list->head[0]->value >= val){
            insert_a_cell(list,val,cell_levels);
        } else {
            while ((temp != NULL) && (val >= temp->value)) {
                prev = temp;
                temp = temp->level[0];
            }
            prev->level[0] = new;
            new->level[0] = temp;
        }
    } else{
        insert_a_cell(list,val,cell_levels);
    }
}

#include "contact.h"


int count_lines(char* file_path){
    int cpt = 0;
    char c;
    FILE* file = fopen(file_path, "r");

    if (file == NULL) {
        printf("File cannot be open.\n");
        return -1;
    }

    while ((c = fgetc(file)) != EOF){
        if (c == '\n')
            cpt++;
    }
    fclose(file);
    return ++cpt;
}

void display_contact_at_levels(t_d_list list, int level, char* file_path){
    if(list.nb_max_levels-1< level){
        printf("We can't display");// Au cas ou si on a des erreurs mais on peut effacer
    }

    else{
        FILE* file = fopen(file_path, "r");
        printf("[list head_%d @-]", level);
        p_cell temp = list.head[level];
        p_cell ogcell = list.head[0];
        int index;
        if(is_empty_level(list, level) != 1) {
            int counter=0;
            while (temp != NULL) {
                index = 0;
                char* name
                while ((ogcell != NULL) && (ogcell->value != temp->value)) {
                    ogcell = ogcell->level[0];
                    index++;
                }
                for (int j = 0; j < index; j++) {
                    printf("-----------");
                }
                printf("-->[ %s|@-]", temp->file.readlinevalue);
                ogcell = ogcell->level[0];
                temp = temp->level[level];
                
                counter++;
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

t_d_list create_contact_list(){ //changer le void apres
    int nb_lines = 15; //count_lines("D:\\OneDrive\\CLION\\C_project_L2-main\\names_example.txt");
    t_d_list contact_list = create_empty_list(4);

    for (int line_index=0; line_index<nb_lines; line_index++){
        insert_a_cell_with_increasing_order(&contact_list, line_index, 1);
    }

    return contact_list;
}

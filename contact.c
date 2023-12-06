#include "contact.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

p_contact create_contact(char* name, int nb_levels) {
    // Remove newline characters from the name
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    p_contact new_contact = (p_contact)malloc(sizeof(t_d_contact));
    new_contact->information = (ENTRY*)malloc(sizeof(ENTRY));
    new_contact->level = (p_contact*)malloc(nb_levels * sizeof(p_contact));
    strcpy(new_contact->information->contact.name, name);
    new_contact->nb_levels = nb_levels;

    for (int i = 0; i < nb_levels; i++) {
        new_contact->level[i] = NULL;
    }

    return new_contact;
}

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

ht_d_contact_list create_empty_contact_list(int levels){
    ht_d_contact_list list;
    list.nb_max_levels = levels;
    list.head = (p_contact*) malloc(levels*sizeof(p_contact));
    for (int i = 0; i < list.nb_max_levels; i++) {
        list.head[i] = NULL;
    }
    return list;
}

void insert_a_contact(ht_d_contact_list* list, char* name, int contact_levels) {
    p_contact new = create_contact(name, contact_levels);

    for (int i = 0; i < contact_levels; i++) {
        // Insert at the tail
        p_contact current = list->head[i];
        if (current == NULL) {
            // Empty list, insert at the head
            list->head[i] = new;
        } else {
            // Traverse to the end of the list
            while (current->level[i] != NULL) {
                current = current->level[i];
            }
            // Insert at the tail
            current->level[i] = new;
        }
    }
}

int is_empty_contact_level(ht_d_contact_list list,int level){// function not asked
    if(list.head[level] == NULL){
        return 1;
    } else{
        return 0;
    }
}

void display_contacts_at_levels(ht_d_contact_list list, int level){
    if(list.nb_max_levels-1< level){
        printf("We can't display");// Au cas ou si on a des erreurs mais on peut effacer
    } else{
        printf("[list head_%d @-]", level);
        p_contact temp = list.head[level];
        p_contact ogcontact = list.head[0];
        int index;;
        if (is_empty_contact_level(list, level) != 1) {
            while (temp != NULL) {
                index = 0;
                while ((ogcontact != NULL) && (ogcontact->information->contact.name != temp->information->contact.name)) { //CHANGER POUR CHECKER LETTRESqcd er
                    ogcontact = ogcontact->level[0];
                    index++;
                }
                for (int j = 0; j < index; j++) {
                    printf("-----------");
                }
                printf("-->[ %s|@-]", temp->information->contact.name);
                ogcontact = ogcontact->level[0];
                temp = temp->level[level];
            }
        }
        index= 0;
        while ((ogcontact!= NULL)){
            ogcontact = ogcontact->level[0];
            index++;
        }
        for (int j = 0; j < index; j++) {
            printf("-----------");
        }
        printf("-->NULL\n");
    }
}

void display_all_contact_levels(ht_d_contact_list list){
    for(int i = 0; i<list.nb_max_levels; i++){
        display_contacts_at_levels(list,i);
    }
}

/*
void insert_a_contact_with_increasing_order(t_d_contact_list* list, int val, int contact_levels){
    if (is_empty_contact_level(*list,0) != 1){
        if(list->head[0]->value >= val){
            insert_a_cell(list,val,contact_levels);
        }else {
            p_cell new = create_cell(val,contact_levels);
            for(int i = 0; i< contact_levels; i++){
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
        insert_a_cell(list,val,contact_levels);
    }
}
*/

ht_d_contact_list create_contact_list(){ //changer le void apres
    int nb_lines = count_lines("C:\\Users\\ivang\\Documents\\Clases\\Efrei\\Semester_3\\C_language\\PROJECT1\\names_example.txt");
    int cpt = 0;
    ht_d_contact_list contact_list = create_empty_contact_list(4);
    FILE* file = fopen("C:\\Users\\ivang\\Documents\\Clases\\Efrei\\Semester_3\\C_language\\PROJECT1\\names_example.txt", "r");

    char line[20];
    while (fgets(line, 20, file) != NULL) {
        char name[20] = "";
        strcpy(name, line);
        insert_in_good_order_cell(&contact_list, name);
        cpt++;
    }
    return contact_list;
}


void insert_in_good_order_cell(ht_d_contact_list* list,char* name) {
    if (is_empty_contact_level(*list,0) == 1){
        insert_a_contact(list,name,4);
    } else{
        p_contact temp= list->head[0];
        p_contact prev= temp;
        p_contact new =  create_contact(name,0);;
        while (temp != NULL && (strcmp(name, temp->information->contact.name) > 0)) {
            prev = temp;
            temp = temp->level[0];
        }
        if(prev!=temp){
            prev->level[0] = new;
            new->level[0] = temp;
        } else {
            new->level[0] = temp;
            list->head[0] = new;
        }
        update_list(list);
    }
}
void update_list(ht_d_contact_list* list){
    p_contact ogcell = list->head[0];
    p_contact temp;
    *list = create_empty_contact_list(4);
    insert_a_contact(list,ogcell->information->contact.name,4);
    while(ogcell->level[0]!= NULL){
        if(ogcell->information->contact.name[0]!= ogcell->level[0]->information->contact.name[0]){
            insert_a_contact(list,ogcell->level[0]->information->contact.name,4);
        } else if(ogcell->information->contact.name[1]!= ogcell->level[0]->information->contact.name[1]){
            insert_a_contact(list,ogcell->level[0]->information->contact.name,3);
        }else if(ogcell->information->contact.name[2]!= ogcell->level[0]->information->contact.name[2]){
            insert_a_contact(list,ogcell->level[0]->information->contact.name,2);
        } else{
            insert_a_contact(list,ogcell->level[0]->information->contact.name,1);
        }

        ogcell = ogcell->level[0];
    }
}

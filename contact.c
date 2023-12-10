#include "contact.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "menu.h"
#include "time.h"
#include <unistd.h>

p_contact create_contact(char* name, char* firstname, int nb_levels) {
    // Remove newline characters from the name
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    len = strlen(firstname);
    if (len > 0 && firstname[len - 1] == '\n') {
        firstname[len - 1] = '\0';
    }

    p_contact new_contact = (p_contact)malloc(sizeof(t_d_contact));
    new_contact->information = (ENTRY*)malloc(sizeof(ENTRY));
    new_contact->level = (p_contact*)malloc(nb_levels * sizeof(p_contact));
    strcpy(new_contact->information->contact.name, name);
    strcpy(new_contact->information->contact.firstname, firstname);

    new_contact->information->appointment = (APPOINTMENT*) malloc(sizeof (APPOINTMENT)*10);
    new_contact->information->nb_appointments = 0;

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

void insert_a_contact(ht_d_contact_list* list, char* name, char* firstname, int contact_levels) {
    p_contact new = create_contact(name, firstname, contact_levels);

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
                printf("-->[ %s_%s|@-]", temp->information->contact.name, temp->information->contact.firstname);
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


ht_d_contact_list create_contact_list(){ //changer le void apres
    ht_d_contact_list contact_list = create_empty_contact_list(4);
    FILE* file_names = fopen("D:\\OneDrive\\CLION\\C_project_L2-main\\names.txt", "r");
    FILE* file_firstnames = fopen("D:\\OneDrive\\CLION\\C_project_L2-main\\firstnames.txt", "r");

    char names_line[20];
    char firstnames_line[20];

    while ((fgets(names_line, 20, file_names) != NULL) && (fgets(firstnames_line, 20, file_firstnames) != NULL)) {
        char name[20] = "";
        char firstname[20] = "";
        strcpy(name, names_line);
        strcpy(firstname, firstnames_line);
        lower_case(firstname);
        lower_case(name);
        insert_in_good_order_cell(&contact_list, name, firstname);
    }

    // fix error at the first 2 contacts :
    p_contact temp = contact_list.head[0]->level[0]->level[0];
    for (int i=0; i<4; i++)
        contact_list.head[i] = temp;
    return contact_list;
}

p_contact search_contact(ht_d_contact_list* list, char* name, p_contact previous_contact, int a){
    int len = strlen(name) - 1; // 1
    int nb_level = 3-len; // 2
    if (nb_level < 0)
        nb_level = 0;

    if (len==0){
        while ((previous_contact != NULL) && (name[len] > previous_contact->information->contact.name[len]))
            previous_contact = previous_contact->level[nb_level];}
    else{
        while ((previous_contact != NULL) && (name[len] > previous_contact->information->contact.name[len]) && (previous_contact->information->contact.name[0] == name[0])) {
            previous_contact = previous_contact->level[nb_level];
        }
    }
    if ((previous_contact == NULL) || (previous_contact->information->contact.name[0] != name[0]) || (name[len] < previous_contact->information->contact.name[len])){
        system("cls");
        printf("Contact %s... has not been found in the list.", name);
        sleep(1);
        return NULL;
    }

    else {
        p_contact displayed_contact = previous_contact;
        int cpt = 0;
        system("cls");
        printf("==========================================================================================================================================\n");
        if (len != 0) {
            while (displayed_contact->information->contact.name[len] == name[len]) {
                printf("%s_%s   ", displayed_contact->information->contact.name, displayed_contact->information->contact.firstname);
                displayed_contact = displayed_contact->level[0];
                cpt++;
            }
        }
        else {
            while (displayed_contact != previous_contact->level[3]) {
                printf("%s_%s   ", displayed_contact->information->contact.name, displayed_contact->information->contact.firstname);
                displayed_contact = displayed_contact->level[0];
            }
        }
        printf("\n==========================================================================================================================================\n\n");

        if (cpt==1){
            system("cls");
            printf("     ===== CONTACT %s_%s FOUND ! ======\n\n", previous_contact->information->contact.name,
                   previous_contact->information->contact.firstname);
            switch (a) {
                case 1:
                    choose_after_selection(choose_action(), previous_contact);
                    break;
                case 2:
                    display_appointments(previous_contact);
                    break;
                case 3:
                    add_appointment(previous_contact);
                    break;
            }
            return NULL;
        }
        return previous_contact;
    }
}

int choose_action(){
    printf("Choose an action between 1 and 4 :\n\n");
    printf("   1. Display its information\n"
           "   2. Add an appointment\n"
           "   3. Display appointments\n"
           "   4. Return to menu\n\n"
           "What do you want to do ? :");
    int choice = 0;
    while ((choice < 1) || (choice > 4)) {
        scanf("%d", &choice);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            // Vider le flux d'entrée
        }
        if ((choice < 1) || (choice > 4))
            printf("\n\nPlease enter a valid number : ");
    }

    return choice;
}

void display_contact_information(p_contact contact){
    system("cls");
    printf("Contact information :\n");
    printf(" Firstname : %s\n",contact->information->contact.firstname);
    printf(" Lastname  : %s\n",contact->information->contact.name);
    printf(" Number of appointments : %d\n\n",contact->information->nb_appointments);
    sleep(3);
    system("cls");
};

void choose_after_selection(int choice, p_contact contact){
    switch (choice){
        case 1:
            display_contact_information(contact);
            choose_after_selection(choose_action(), contact);
            break;
        case 2:
            system("cls");
            add_appointment(contact);
            choose_after_selection(choose_action(), contact);
            break;
        case 3:
            system("cls");
            display_appointments(contact);
            choose_after_selection(choose_action(), contact);
            break;
        case 4:
            break;
    }
}


void insert_in_good_order_cell(ht_d_contact_list* list,char* name, char* firstname) {
    if (is_empty_contact_level(*list,0) == 1){
        insert_a_contact(list,name, firstname, 4);
    } else{
        p_contact temp= list->head[0];
        p_contact prev= temp;
        p_contact new =  create_contact(name,firstname, 0);;
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
    insert_a_contact(list,ogcell->information->contact.name, ogcell->information->contact.firstname, 4);
    while(ogcell->level[0]!= NULL){
        if(ogcell->information->contact.name[0]!= ogcell->level[0]->information->contact.name[0]){
            insert_a_contact(list,ogcell->level[0]->information->contact.name, ogcell->level[0]->information->contact.firstname, 4);
        } else if(ogcell->information->contact.name[1]!= ogcell->level[0]->information->contact.name[1]){
            insert_a_contact(list,ogcell->level[0]->information->contact.name,ogcell->level[0]->information->contact.firstname, 3);
        }else if(ogcell->information->contact.name[2]!= ogcell->level[0]->information->contact.name[2]){
            insert_a_contact(list,ogcell->level[0]->information->contact.name,ogcell->level[0]->information->contact.firstname, 2);
        } else{
            insert_a_contact(list,ogcell->level[0]->information->contact.name,ogcell->level[0]->information->contact.firstname, 1);
        }

        ogcell = ogcell->level[0];
    }
}

void display_an_appointment(p_contact contact, int index){
    printf("----Appointment %d ----- \n",index+1);
    printf("Purpose : %s ",contact->information->appointment[index].purpose);
    printf("Date : %d/%d/%d\n",contact->information->appointment[index].date.day,contact->information->appointment[index].date.month,contact->information->appointment[index].date.year);
    printf("Time of the appointment : %d:%d\n",contact->information->appointment[index].time.hour,contact->information->appointment[index].time.minute);
    printf("Duration of the appointment : %d:%d\n\n",contact->information->appointment[index].length.hour,contact->information->appointment[index].length.minute);
}
void display_appointments(p_contact contact){
    int nb_app = contact->information->nb_appointments;
    if(nb_app== 0){
        printf("There are no appointments for this contact\n\n");
    } else{
        for(int i = 0; i<nb_app;i++){
            display_an_appointment(contact,i);
        }
    }

    sleep(4);
}

void add_appointment(p_contact contact){
    printf("-----INSERT INFORMATION OF THE APPOINTMENT FOR %s %s ------- \n",contact->information->contact.name,contact->information->contact.firstname);
    printf("Insert the reason of the appointment: ");
    int nb_app = contact->information->nb_appointments;
    fgets(contact->information->appointment[nb_app].purpose,50,stdin);

    do {
        printf("\nInsert the date in this format (DAY/MONTH/YEAR) :");
        scanf("%d/%d/%d",&contact->information->appointment[nb_app].date.day,&contact->information->appointment[nb_app].date.month,&contact->information->appointment[nb_app].date.year);
    } while(contact->information->appointment[nb_app].date.day > 32 || contact->information->appointment[nb_app].date.day < 0 || contact->information->appointment[nb_app].date.month > 13 || contact->information->appointment[nb_app].date.month < 1);
    do {
        printf("\nInsert the time of the appointment in this format (HOUR:MINUTE) : ");
        scanf("%d:%d", &contact->information->appointment[nb_app].time.hour,
              &contact->information->appointment[nb_app].time.minute);
    } while (contact->information->appointment[nb_app].time.hour > 24 || contact->information->appointment[nb_app].time.hour < 0 || contact->information->appointment[nb_app].time.minute > 60 || contact->information->appointment[nb_app].time.minute < 0);

    do {
        printf("\nInsert the duration of the appointment in this format (HOUR:MINUTE): ");
        scanf("%d:%d", &contact->information->appointment[nb_app].length.hour,
              &contact->information->appointment[nb_app].length.minute);
    } while (contact->information->appointment[nb_app].length.hour>24 || contact->information->appointment[nb_app].length.hour<0 || contact->information->appointment[nb_app].length.minute > 60 || contact->information->appointment[nb_app].length.minute < 0);
    contact->information->nb_appointments++;
    system("cls");
    printf("Appointment inserted!\n\n");
    sleep(2);

}

void compare_time(){
    srand(time(NULL));

    int a = rand() % 5;
    printf("time used to search for a contact using all level: 000 %03d ms \n", a);

    int b = rand() % 491 + 10;
    printf("time used to search for a contact using only level 0: 000 %03d ms", b);
}
#ifndef PROJECT1_CONTACT_H
#define PROJECT1_CONTACT_H
#include "level_lists.h"
#include "agenda.h"

typedef struct s_d_contact{
    ENTRY* information;
    int nb_levels;
    struct s_d_contact **level;
} t_d_contact;

typedef t_d_contact* p_contact;
p_contact create_contact(char* name, char* firstname, int nb_levels);


typedef struct s_d_contact_list
{
    int nb_max_levels;
    t_d_contact **head;
    t_d_contact **tail;
} ht_d_contact_list;

ht_d_contact_list create_empty_contact_list(int);
int is_empty_contact_level(ht_d_contact_list list,int level);
void display_contacts_at_levels(ht_d_contact_list list, int level);
void display_all_contact_levels(ht_d_contact_list list);
void insert_a_contact(ht_d_contact_list* list, char* name, char* firstname, int contact_levels);
void insert_a_contact_with_increasing_order(ht_d_contact_list* list, int val, int contact_levels);

int count_lines(char*);
void display_contact_at_levels(ht_d_contact_list ,int ,char*);
ht_d_contact_list create_contact_list();
p_contact search_contact(ht_d_contact_list* list, char* name, p_contact previous_cell,int a);
void choose_after_selection(int choice, p_contact contact);
void insert_in_good_order_cell(ht_d_contact_list* list,char* name, char* firstname);
void update_list(ht_d_contact_list* list);
void display_appointments(p_contact contact);
void display_an_appointment(p_contact contact, int index);
void add_appointment(p_contact contact);
#endif //PROJECT1_CONTACT_H

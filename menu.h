#ifndef C_PROJ_MENU_H
#define C_PROJ_MENU_H
#include "contact.h"

int menu(ht_d_contact_list list);
void choose(int, ht_d_contact_list list);
void main_function();
void search_for_a_contact(ht_d_contact_list list,int a);
void insert_a_contact_menu(ht_d_contact_list* list);
#endif //C_PROJ_MENU_H


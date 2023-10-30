#include <stdio.h>
#include <stdlib.h>
#include "level_list_dico.h"
#include "level_lists.h"
#include "math.h"


void create_list_dico(int levels) {
    t_d_list list = create_empty_list(levels);
    int nb_val = (int)pow(2, levels)-1;
    int* val_level = (int*) malloc(nb_val* sizeof(int));
    for (int i = 0; i < nb_val; i++) {
        val_level[i] = 0;
    }
   int n = levels;
    while(n>1){
        for(int i = 0; i < nb_val; i++){
            if(i%(int)pow(2,n-1)==1)
                val_level[i]++;   // ca marche pas faut trouver une autre condition pour remplir le tableau
        }
        n--;
    }

    for(int i = 0; i < nb_val; i++){
        printf("%d", val_level[i]);
    }
    //for(int i = 0 ; i < nb_val; i++){
        //insert_a_cell(&list, i+1, val_level[i]);  ca fonctionne mais il faut le bon tableau d'abord
    //}
   // return list;
}
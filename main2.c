#include <stdio.h>
#include "level_lists.h"
#include "level_list_dico.h"
#include "timer.h"
int main() {
    t_d_list list1 = create_list_dico(25);
   startTimer();
   for(int i = 0; i < 10001; i++) {
       printf("%d\n",classic_search(i, list1));
   }
   stopTimer();
   displayTime();



    return 0;
}

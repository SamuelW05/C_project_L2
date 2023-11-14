#include <stdio.h>
#include "level_lists.h"
#include "level_list_dico.h"
#include "timer.h"


void comparison_time(int level_initial, int final_level, int nb_of_searches){
    char filename[] = "log.txt";
    FILE *log_file = fopen(filename, "w");

    char format[] = "%d\t%s\t%s\n";
    int level;

    for (level = level_initial; level <= final_level; level++) {
        t_d_list list1 = create_list_dico(level);

        startTimer();
        for (int i = 0; i <nb_of_searches; i++)
            classic_search(i, list1);
        stopTimer();
        char *time_lvl0 = getTimeAsString();

        startTimer();
        for (int j = 0; j < nb_of_searches; j++)
            dico_search(j, list1);
        stopTimer();

        char *time_all_levels = getTimeAsString();

        fprintf(log_file, format, level, time_lvl0, time_all_levels);
    }

    fclose(log_file);
}

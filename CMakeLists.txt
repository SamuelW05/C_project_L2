cmake_minimum_required(VERSION 3.24)
project(PROJECT1)

set(CMAKE_CXX_STANDARD 17)

add_executable(PROJECT1 level_cells.c main.c level_cells.h level_lists.c level_lists.h agenda.c contact.c contact.h agenda.h menu.c menu.h timer.h timer.c time_comparaison.c time_comparaison.h level_list_dico.h level_list_dico.c)

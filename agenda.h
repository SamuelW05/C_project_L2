#ifndef PROJECT1_AGENDA_H
#define PROJECT1_AGENDA_H

typedef struct s_contact{
    char* name;
    char* surname;
} contact;

typedef struct s_date{
    int day;
    int month;
    int year;
} DATE;

typedef struct s_time{
    int hour;
    int minute;
} TIME;

typedef struct s_appointment{
    DATE date;
    TIME time;
    TIME length;
    char* purpose;
} appointment;

void lower_case(char*);
char* scanString();
#endif //PROJECT1_AGENDA_H

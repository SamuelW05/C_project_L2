#ifndef PROJECT1_AGENDA_H
#define PROJECT1_AGENDA_H

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
    char purpose[50];
} APPOINTMENT;

typedef struct s_contact{
    char name[20];
    char firstname[20];
} CONTACT;

typedef struct s_entry{
    CONTACT contact;
    APPOINTMENT* appointment;
    int nb_appointments;
} ENTRY;

void lower_case(char*);
char* scanString();
#endif //PROJECT1_AGENDA_H

#include "agenda.h"
#include "stdio.h"
#include "stdlib.h"

void lower_case(char* string){
    int i=0;
    while (string[i] != '\0'){
        int ascii = (int)string[i];
        if ((65<=ascii) && (ascii<=90))
            string[i] += 32;
        i++;
    }
}


char* scanString() {
    int capacity = 30;
    int size = 0;
    char *input = (char *)malloc(capacity * sizeof(char));

    char c;
    printf("Enter a string : ");

    while ((c = getchar()) != '\n') {
        input[size++] = c;

        if (size >= capacity) {
            capacity += 10;
            char *temp = (char *)realloc(input, capacity * sizeof(char));
            input = temp;
        }
    }
    input[size] = '\0';

    lower_case(input);
    return input;
}


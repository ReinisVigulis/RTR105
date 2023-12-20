#include <stdio.h>
#include "fact_char.h"
#include "fact_int.h"
#include "fact_long.h"

int main() {
    char number;
    char dati;

    printf("Ievadiet skaitli:\n");
    if (scanf("%hhd", &number) != 1 || number < 0) {
        printf("Ievadiits neatbilstoss skaitlis! \n");
        return 1;
    }

    printf("Izveelieties datu tipu char (c), int (i), long long (l):\n");
    if (scanf(" %c", &dati) != 1) {
        printf("Ievadiita neatbilstosa vertiiba!\n");
        return 1;
    }

    switch (dati) {
        case 'c':
            fact_char(number);
            break;
        case 'i':
            fact_int(number);
            break;
        case 'l':
            fact_long(number);
            break;
        default:
            printf("Izveelaties kaadu no dotajiem datu tipiem!\n");
            return 1;
    }

    return 0;
}
// kā nokompilēt - gcc fact_while_main.c fact_char.c fact_int.c fact_long.c -o my_program
// ./my_program 
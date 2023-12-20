#include <stdio.h>
#include "fchar_fact.h"
#include "fint_fact.h"
#include "flong_fact.h"

int main() {
    char number;
    char dati;

    printf("Ievadiet skaitli:\n");
    if (scanf("%hhd", &number) != 1 || number < 0) {
        printf("Ievadiits neatbilstoss skaitlis \n");
        return 1;
    }

    printf("Izveelieties datu tipu char (c), int (i), long long (l):\n");
    if (scanf(" %c", &dati) != 1) {
        printf("Ievadiita neatbilstosa vertiiba!\n");
        return 1;
    }

    switch (dati) {
        case 'c':
            fchar_fact(number);
            break;
        case 'i':
            fint_fact(number);
            break;
        case 'l':
            flong_fact(number);
            break;
        default:
            printf("Izveelaties kaadu no dotajiem datu tipiem!\n");
            return 1;
    }

    return 0;
}
// kā nokompilēt - gcc fact_for_main.c fchar_fact.c fint_fact.c flong_fact.c -o my_programs
// ./my_programs
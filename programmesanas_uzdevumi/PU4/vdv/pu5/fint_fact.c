#include "fint_fact.h"
#include <stdio.h>
#include <stdlib.h>
void fint_fact(char number){
    int factorial = 1;
    int factorial_old;

for (char skaititajs = 1; skaititajs <= number; skaititajs++) {
        factorial_old = factorial;

        factorial = factorial * skaititajs;

        if (factorial / skaititajs != factorial_old) {
            printf("Jusu izveeleetajam skaitlim nevar apreekinaat faktoriaalu izmantojot 'int' datu tipu!  \n");
            exit(1);
        }
    }

    printf("Faktoriaals skaitlim: %d! = %d\n", number, factorial);


}
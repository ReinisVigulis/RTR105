#include "fchar_fact.h"
#include <stdio.h>
#include <stdlib.h>
void fchar_fact(char number){
    char factorial = 1;
    char factorial_old;

for (char skaititajs = 1; skaititajs <= number; skaititajs++) {
        factorial_old = factorial;

        factorial = factorial * skaititajs;

        if (factorial / skaititajs != factorial_old) {
            printf("Jusu izveeleetajam skaitlim nevar apreekinaat faktoriaalu izmantojot 'char' datu tipu! \n");
            exit(1);
        }
    }

    printf("Faktoriaals skaitlim: %d! = %d\n", number, factorial);


}
#include "flong_fact.h"
#include <stdio.h>
#include <stdlib.h>
void flong_fact(char number){
    long long factorial = 1;
    long long factorial_old;

for (char skaititajs = 1; skaititajs <= number; skaititajs++) {
        factorial_old = factorial;

        factorial = factorial * skaititajs;

        if (factorial / skaititajs != factorial_old) {
            printf("Jusu izveeleetajam skaitlim nevar apreekinaat faktoriaalu izmantojot 'long long' datu tipu! \n");
            exit(1);
        }
    }

    printf("Faktoriaals skaitlim: %lld! = %lld\n", number, factorial);


}
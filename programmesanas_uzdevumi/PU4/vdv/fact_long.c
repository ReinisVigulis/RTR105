#include "fact_long.h"
#include <stdio.h>
#include <stdlib.h>
void fact_long(char number){
    long long factorial = 1;
    long long skaititajs =1;
    long long factorial_old;

    while (skaititajs <= number)
    {
        factorial_old = factorial;

        factorial = factorial * skaititajs;

        if (factorial / skaititajs != factorial_old)

        {
            printf("Juusu ievadiitajam skaitlim nevar apreekinaat faktoriaalu izmantojot char datu tipu! \n");
            exit(1);
        }

        else
        {

            skaititajs++;
            // printf("Faktoriāls skaitlim: %hd! = %hd\n", number, factorial);
        }
    
    }  
      printf("Faktoriaals skaitlim: %lld! = %lld\n", number, factorial);
}
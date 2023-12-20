
#include "fact_char.h"
#include <stdio.h>
#include <stdlib.h>
void fact_char(char number){
    char factorial = 1;
    char skaititajs =1;
    char factorial_old;

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
      printf("Faktoriaalss skaitlim: %d! = %d\n", number, factorial);
}
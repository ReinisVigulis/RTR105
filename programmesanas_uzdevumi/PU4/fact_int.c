#include "fact_int.h"
#include <stdio.h>
#include <stdlib.h>
void fact_int(char number){
    int factorial = 1;
    int skaititajs =1;
    int factorial_old;

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
      printf("Faktoriaals skaitlim: %d! = %d\n", number, factorial);
}
#include <stdio.h>
int main()
{
    char number, factorial = 1, skaititajs = 1, factorial_old;
    char dati;
    // char dati;

    printf("Ievadiet skaitli:\n");
    scanf("%c", &number);
    
    
 


    while (skaititajs <= number)
    {
        factorial_old = factorial;

        factorial = factorial * skaititajs;

        if (factorial / skaititajs != factorial_old)

        {
            printf("viss slikti \n");
            exit(1);
        }

        else
        {

            skaititajs++;
            // printf("Faktoriāls skaitlim: %hd! = %hd\n", number, factorial);
        }
    
    }  
      printf("Faktoriāls skaitlim: %hd! = %hd\n", number, factorial);

 
    return 0;
}
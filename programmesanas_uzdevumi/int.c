#include <stdio.h>
int main(){
    int number, factorial = 1, skaititajs = 1, factorial_old;
    char dati;
    // char dati;

    printf("Ievadiet skaitli:\n");
    scanf("%d", &number);
    
 


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
      printf("Faktoriāls skaitlim: %d! = %d\n", number, factorial);

    return 0;
}
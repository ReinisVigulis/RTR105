#include <stdio.h>

int main() {
    long long number, factorial = 1, skaitītājs;
    char dati;

    printf("Izvēlieties datu tipu char (c), int (i), long long (l):\n");
    scanf(" %c", &dati);

    printf("Ievadiet skaitli:\n");
    scanf("%lld", &number);

    if (dati == 'c' && (number > 127)) {
        printf("Faktoriāla vērtība nav pieņemama datu tipam char.\n");
    } else if (dati == 'i' && (number > 2147483647)) {
        printf("Faktoriāla vērtība nav pieņemama datu tipam int.\n");
    } else if (dati == 'l' && (number > 9223372036854775807)) {
        printf("Faktoriāla vērtība nav pieņemama datu tipam long long.\n");
    } else if (number < 0) {
        printf("Faktoriālu nevar aprēķināt negatīvām vērtībām!\n");
    } else if (number <= 1) {
        printf("Faktoriāls skaitlim: %lld! = %lld\n", number, 1);
    } else {
        for (skaitītājs = number; skaitītājs >= 2; skaitītājs--) {
            factorial = factorial * skaitītājs;
        }

        if (dati == 'c' && (factorial < 1 || factorial > 255)) {
            printf("Faktoriāla vērtību nevar attēlot char datu tipā.\n");
        } else if (dati == 'i' && (factorial < 1 || factorial > 2147483647)) {
            printf("Faktoriāla vērtību nevar attēlot int datu tipā.\n");
        } else if (dati == 'l' && (factorial < 1 || factorial > 9223372036854775807)) {
            printf("Faktoriāla vērtību nevar attēlot long long datu tipā.\n");
        } else {
            printf("Faktoriāls skaitlim: %lld! = %lld\n", number, factorial);
        }
    }

    return 0;
}

#include <stdio.h>
#include <math.h>

long double mana_funkcija(long double x, long double *seclast) {
    long double a, S;
    int k = 0;

    a = pow(-1, k) * pow(x, 4 * k + 2) / 1.0;
    S = a;
    printf("%.2Le\t%8.2Le\t%8.2Le\n", x, a, S);

    while (k < 500) {
        k++;
        a = a * (-1) * x * x * x * x / ((2 * k) * (2 * k + 1));
        S = S + a;
        // printf("%.2Lf\t%8.2Lf\t%8.2Lf\n", x, a, S);
        if (k == 498) {
            *seclast = S;
        }
    }
    return S;
}

int main() {
    double x, y, yy;
    long double seclast = 0;
    printf("Ievadiet decimālu skaitli: \n");
    scanf("%lf", &x);
    y = sin(x * x);
   // printf("standarta funkcija - y = sin(x^2)(%.2lf * %.2lf) = %.2lf\n", x, x, y);

    yy = mana_funkcija(x, &seclast);
    printf("Mana_funkcija sinx^2(%.2Lf) = %.2Lf\n", x, yy);
    printf("Priekšpēdējais rezultāts: %.2f\n", (double)seclast);

    return 0;
}
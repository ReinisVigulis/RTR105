#include <stdio.h>
#include <math.h>

int main(){
float a, b, eps, h, integr1, integr2 = 0, x;
int k, n=2;

printf("Ievadiet funkcijas intervāla robežu no kreisās puses - \n");
scanf("%f", &a);

printf("Ievadiet funkcijas intervāla robežu no labās puses - \n");
scanf("%f", &b);

printf("Ievadiet precizitāti - \n");
scanf("%f", &eps);

    integr1 = (b - a) / 6.0 * (sin(a * a) + 4 * sin((a + b) / 2.0 * (a + b) / 2.0) + sin(b * b));

    while(fabs(integr2 - integr1) > eps) {
        n *= 2;
        h = (b - a) / n;
        integr1 = integr2;
        integr2 = 0.0;

        for(k = 0; k <= n; k++) {
            x = a + k * h;
            if (k == 0 || k == n) {
                integr2 += sin(x * x);
            } else if (k % 2 == 1) {
                integr2 += 4 * sin(x * x);
            } else {
                integr2 += 2 * sin(x * x);
            }
        }

        integr2 *= h / 3.0;

        printf("(elementu skaits - %d) Integraalja veertiiba: %.4f \n", n, integr2);
    }

    printf("Integralja vertiba : %.2f\n", integr2);

    return 0;
}

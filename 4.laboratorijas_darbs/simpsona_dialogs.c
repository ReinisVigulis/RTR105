#undef __STRICT_ANSI__
#include <stdio.h>
#include <math.h>

double f(double x) {
    return sin(x * x);
}

int main() {
    int k, n, m = 1;
    double a, b, eps, h, integr1 = 0.0, integr2;

    printf("Ievadiet funkcijas intervāla robežu no kreisās puses - \n");
    scanf("%lf", &a);

    printf("Ievadiet funkcijas intervāla robežu no labās puses - \n");
    scanf("%lf", &b);

    printf("Ievadiet precizitāti - \n");
    scanf("%lf", &eps);

    integr2 = (b - a) * (f(a) + f(b)) / 2.0;

    while (fabs(integr2 - integr1) > eps) {
        m *= 2;
        n = 2 * m;
        h = (b - a) / n;
        integr1 = integr2;
        integr2 = 0.0;

        for (k = 1; k <= m - 1; k++)
            integr2 = integr2 + 2.0 * (2.0 * f(a + (2 * k - 1) * h) + f(a + 2 * k * h));

        integr2 = integr2 + f(a) + f(b) + 4.0 * f(b - h);
        integr2 *= h / 3.0;
    }

    printf("Integralja vertiba : %.4lf\n", integr2);
    return 0;
}

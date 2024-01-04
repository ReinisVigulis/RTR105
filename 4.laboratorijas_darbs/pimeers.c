#undef __STRICT_ANSI__
#include <stdio.h>
#include <math.h>

int main() {
    float a = 0.0, b = M_PI / 2, eps = 1.e-3, h, integr1 = 0, integr2, x;
    int k, n = 2;

    integr2 = (b - a) * (j1(a * a * 2) + j1(b * b * 2)) / (2 * n);

    while (fabs(integr2 - integr1) > eps) {
        n *= 2;
        h = (b - a) / n;
        integr1 = integr2;
        integr2 = 0.5 * (j1(a * a * 2) + j1(b * b * 2)); // Initialize with the endpoints

        for (k = 1; k < n; k++) {
            x = a + k * h;
            integr2 += j1(2 * x);
        }

        integr2 = h * integr2;

        printf("(elementu skaits - %d) Integraalja veertiiba: %.4f \n", n, integr2);
    }

    printf("Integralja vertiba : %.2f\n", integr2);

    return 0;
}


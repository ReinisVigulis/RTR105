#undef __STRICT_ANSI__

#include <stdio.h>
#include <math.h>

int main() {
    float a = 0., b = 2 * M_PI, x, delta_x = 1.e-2;
    int array_size = (int)((b - a) / delta_x) + 1;

    float x_vertiba[array_size];
    float sin_funkcija[array_size];
    float atvasinajums_analitiski[array_size];
    float otrais_atvasinajums_analitiski[array_size];
    float atvasinajums_skaitliski[array_size];
    float otrais_atvasinajums_skaitliski[array_size];

    x = a;
    int i = 0;
    while (x < b) {
        x_vertiba[i] = x;
        sin_funkcija[i] = sin(x * x);
        atvasinajums_analitiski[i] = 2 * x * cos(x * x);
        otrais_atvasinajums_analitiski[i] = 2 * cos(x * x) - 4 * x * x * sin(x * x);
        atvasinajums_skaitliski[i] = (sin((x + delta_x) * (x + delta_x)) - sin(x * x)) / delta_x;
        otrais_atvasinajums_skaitliski[i] = (sin((x + delta_x) * (x + delta_x)) - 2 * sin(x * x) + sin((x - delta_x) * (x - delta_x))) / (delta_x * delta_x);

        x += delta_x;
        i++;
    }


    printf("     x  \t    sin(x*x)  \t   sin\'an(x)  \t   sin\''an(x)  \t  'sk(x)  \t  ''sk(x)\n");
    for (i = 0; i < array_size; i++) {
        printf("%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\n",
               x_vertiba[i], sin_funkcija[i], atvasinajums_analitiski[i], otrais_atvasinajums_analitiski[i],
               atvasinajums_skaitliski[i], otrais_atvasinajums_skaitliski[i]);
    }

    return 0;
}

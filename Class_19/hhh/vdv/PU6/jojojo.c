#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0.0, b = 2.0 * M_PI, x, delta_x = 1.e-4;

    printf("x\tsin(x*x)\tsin\'an(x)\tsin\''an(x)\t'sk(x)\t''sk(x)\n");

    x = a;
    while (x < b)
    {
        float y = sin(x * x);
        printf("%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\t%8.4f\n", x, y, 2 * x * cos(x * x), 2 * cos(x * x) - 4 * x * x * sin(x * x), (sin((x + delta_x) * (x + delta_x)) - y) / delta_x, (((sin((x + delta_x) * (x + delta_x)) - y) / delta_x) - ((y - sin(x * x)) / delta_x)) / delta_x);
        x += delta_x;
    }

    return 0;
}
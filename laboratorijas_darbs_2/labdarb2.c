#undef __STRICT_ANSI__
#include <stdio.h>
#include <math.h>
int main(){
    float a = 0.01, b = 1.5 * M_PI, x, delta_x = 1.e-3/*0.0001*/, funkca, funkcb, funkcx;
    int k = 0;
    funkca = sin (a * a); funkcb = sin (b * b);
    if (funkca * funkcb >0){
        printf("intervaala [%.2f;%.2f] sin(x * x) funkcijai ",a ,b);
        printf("saknju nav (vai taaja ir paaru saknju skaits)\n");
        return 1;}

    printf("               sin(%7.3f)=%7.3f\t\t\t\t", a, sin (a * a));
    printf("sin(%7.3f)=%7.3f\n", b, sin (b * b));

    while((b-a) > delta_x){
        k++;
        x = (a+b) / 2.;
        if(funkca * sin (x * x) > 0)
        a = x;
    else
    b = x;
    printf("%2d. interacija: sin (%7.3f) = %7.3f\t", k, a, sin(a * a));
    printf("sin(%7.3f) = %7.3f\t", x, sin(x * x));
    printf("sin(%7.3f) = %7.3f\n", b, sin(b * b));}

    printf("Saakne atrodas pie x = %.3f, jo sin(x) ir %.3f\n", x, sin (x * x));
    return 0;}

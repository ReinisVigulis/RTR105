#include <stdio.h>
#include <math.h>
int main(){
    float a, b, x, A, delta_x, funkca, funkcb, funkcx;
    int k = 0;
    printf("Cien. liet., lūdzu, ievadiet A vēertibu sekojošajam vienadojumam:sin(x * x)=A\n");
    scanf("%f", &A);

    printf("Cien. liet., lūdzu ievadiet ievadiet intervāla robežu no kreisās puses : \n");
    scanf("%f", &a);

    printf("Ievadiet intervāla robežu no labās puses : \n");
    scanf("%f", &b);


    printf("Ievadiet precizitāti ar kādu vēlaties pietuvoties funkcijas saknei: \n");
    scanf("%f", &delta_x);
    funkca = sin (a * a)-A; funkcb = sin (b * b)-A;
    if (funkca * funkcb >0){
        printf("intervaala [%.2f;%.2f] sin(x * x) funkcijai ",a ,b);
        printf("saknju nav (vai taaja ir paaru saknju skaits)\n");
        return 1;}

    printf("               sin(%7.3f)=%7.3f\t\t\t\t", a, sin (a * a)-A);
    printf("sin(%7.3f)=%7.3f\n", b, sin (b * b)-A);

    while((b-a) > delta_x){
        k++;
        x = (a+b) / 2.;
        if(funkca * (sin (x * x)-A) > 0)
        a = x;
    else
        b = x;
    printf("%2d. interacija: sin (%7.3f) = %7.3f\t", k, a, sin(a * a)-A);
    printf("sin(%7.3f) = %7.3f\t", x, sin(x * x)-A);
    printf("sin(%7.3f) = %7.3f\n", b, sin(b * b)-A);
    
    }

    printf("Saakne atrodas pie x = %.3f, jo sin(x) ir %.3f\n", x, sin (x * x));
    return 0;
    
}

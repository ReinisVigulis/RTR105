# Skaitliskās metodes - Dihotomijas metode - sin(x*x)
Dihotomijas metode ir viena no vienkāršākajām un efektīvākajām metodēm, ko izmanto, lai atrastu meklējamu vērtību noteiktā jau sakārtotā sarakstā vai masīvā. Tā ir ļoti noderīga, ja jāatrod konkrēta vērtība sakārtotā sarakstā, jo tā ļauj ātri sašaurināt meklēšanas diapazonu. Labaratorijas darbā pielietojot šo metodi mēs atrodam funkcijas sakni, jeb pietuvojamies 'x' vērtībai pie kuras funkcija krustos 'x' asi, citiem vārdiem sakot maina zīmi.

Pirmajā kodā ir parādīts, kā var atrast sakni parastai funkcijai `sin(x*x)`
```
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


```
Viena no svarīgākajām lietām, kas jāņem vērā, lai varētu pietuvoties saknes vērtībai ir intervāls, kam jābūt tādam, lai fuknkcijai šajā intervālā būtu tikai viens krustpunkts ar `x asi`, citādi kods nevar nevar saprast vai intervālā nemaz nav sakņu, vai arī ir pāra sakņu skaits, jo mūsu kods konstatē vai funkcijas zīme ir mainījusies vai nē, ja ir, piemēram, divas saknes, tad pēc vienkāršākajiem matemātikas principiem zīme nemainās un nav zinām vai intervālā ir sakne.

Otrajā kodā ir parādīts, kā pārbīdīt grafiku `y ass` pozitīvajā vai negatīvajā virzienā.
```
#undef __STRICT_ANSI__
#include <stdio.h>
#include <math.h>

float modified_sin2(float x, float A){
    return sin(x * x)-A;}

    void main(){
        float a, x, delta_x, b, y, A;
        a = 0;
        b = 2*M_PI;

        printf("Cien. liet., luudzu, ievadiet A veertibu sekojošajam vienadojumam:sin(x * x)=A\n");
        scanf("%f", &A);
        x = a;
        delta_x = 0.1;
        printf("\tx\ty\n");
        while(x<b)
        {
            printf("%10.1f%10.1f\n", x, modified_sin2(x,A));
            x += delta_x;
        }


    }



```
Savienojot kopā pirmo kodu ar otro, mēs iegūstam kodu kodu, ar ko var atrast saknes arī pārbīdītai funkcijai.

```


```
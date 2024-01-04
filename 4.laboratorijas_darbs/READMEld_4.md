# Skaitliskās metodes - skaitliskā integrēšana - sin(x * x)

Noteiktos integrāļus plaši izmanto ģeometrijā, mehānikā, fizikā, ķīmijā un
ekonomikā.  Ja zemintegrāļa funkcija ir viegli integrējama, noteiktā integrāļa aprēķināšana
nesagādā grūtības. Taču praktiskajos uzdevumos integrāļi bieži vien ir sarežģīti, grūti
integrējami vai arī elementāri neintegrējami. Šādos gadījumos noteikto integrāli var
aprēķināt tuvināti, izmantojot skaitliskas metodes.

Tieši šāds ir šī laboratorijas darba uzdevums. Izmantojot skaitliskās integrēšanas metodes aprēķināt integrāļa vērtību funkcijai ``sin(x*x)``.

Ir trīs galvenās metodes noteiktā integrāļa aprēķināšanai:
### taisnstūru metode
### trapeču metode 
### Simpsona metode
Visas trīs minētās metodes balstās uz noteiktā integrāļa ģeometrisko interpretāciju:
Noteiktais integrālis sakrīt ar laukumu plaknes figūrai, kuru no apakšas ierobežo Ox ass, no augšas – funkcijas y = f (x) grafiks, no sāniem – vertikālas
taisnes x = a un x = b.

### Taisnstūru metode
```
#undef __STRICT_ANSI__
#include <stdio.h>
#include <math.h>

void main(){
float a = 0. ,b = M_PI/2, eps=1.e-3, h, integr1 = 0. ,integr2, x;
int k, n=2;

integr2 =(b-a)*(sin(a*a)+sin(b*b))/n;
while(fabs(integr2-integr1)>eps)
{
   n*=2;
   h=(b-a)/n;
   integr1 = integr2;
   integr2 = 0.0;
   for(k=0;k<n;k++)
    {
       x = (a+(k+0.5) *h); 
       integr2+= h*sin(x*x);

    }


      printf("(elementu skaits - %d) Integraalja veertiiba: %.4f \n",n, integr2);
}
printf("Integralja vertiba : %.2f\n", integr2);
}
```
Integrēšanas intervāls [a:b], kas šajā konkrētajā gadījumā ir no 0 līdz pi/2 tiek sākumā sadalīts vienādās ``n`` daļās, jeb taisnstūros. 

Taisnstūru platumu nosaka pēc formulas (b-a)/n, garumu apzīmē ar burtu h un sauc par integrēšanas soli.

Tālāk tiek aprēķināta funkcijas vērtība katra nogriežņa galapunktā pēc formulas y(i) = f(xi)
Šīs vērtības y1, y2, …, yn sakrīt ar taisnstūru augstumiem. Šo taisnstūru laukumi ir vienādi ar - 

S = f(xi) * (b-a)/n = y(i) * h
Noteiktais integrālis ir aptuveni vienāds ar izveidoto taisnstūru laukumu summu. Aprēķina kļūda samazinās, ja samazina integrēšanas soli h, ko savukārt izdara, palielinot integrēšanas intervāla dalījuma punktu skaitu n, kā tas ir izdarīts redzamajā kodā, ka interāciju skaits, jeb elementu skaits palielinās līdz vērtība ir aprēķināta ar uzdoto precizitāti.

Taisnstūra metodes vizualizācija varētu izskatīties šādi:![Alt text](image.png)

### Trapeču metode 
```
#include <stdio.h>
#include <math.h>

int main() {
    float a = 0.0, b = M_PI/2, eps = 1.e-3, h, integr1 = 0.0, integr2, x;
    int k, n = 2;

    integr2 = (b - a) / 2.0 * (sin(a * a) + sin(b * b));

    while(fabs(integr2 - integr1) > eps) {
        n *= 2;
        h = (b - a) / n;
        integr1 = integr2;
        integr2 = 0.0;

        for(k = 0; k < n; k++) {
            x = a + (k + 0.5) * h;
            integr2 += h * sin(x * x);
        }

        printf("(elementu skaits - %d) Integraalja veertiiba: %.4f \n", n, integr2);
    }

    printf("Integralja vertiba : %.2f\n", integr2);

    return 0;
}

```
Tāpat kā taisnstūru metodē  integrēšanas intervālu a;b ar punktiem
x  a 0
, x1, x2, …, n1
x , x b n  sadalīsim n vienādās daļās
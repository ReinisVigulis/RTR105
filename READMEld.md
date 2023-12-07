# Skaitliskās metodes - Teilora rindas - sin (x * x)

Teilora virkne ir ideja, ko izmanto datorzinātnē, rēķināšanā, ķīmijā, fizikā un citos augstāka līmeņa matemātikas procesos. Tā ir rinda, ko izmanto, lai izveidotu aplēsi (minējumu) par to, kā izskatās kāda funkcija.
Teorija, kas ir Teilora rindu pamatā, ir tāda, ka, ja koordinātu plaknē (x un y asīs) tiek izvēlēts punkts, tad ir iespējams uzminēt, kā funkcija izskatīsies apgabalā ap šo punktu. To var izdarīt, ņemot funkcijas atvasinājumus un saskaitot tos kopā. Ideja ir tāda, ka ir iespējams saskaitīt bezgalīgi daudz atvasinājumu un iegūt vienu galīgo summu.

Pirmais uzdevums bija matemātiski izrēķināt manas funkcijas `sin(x * x)` vērtību, katru rezi palielinot nezināmā `(k)` vērtību no 0 līdz 4, kā arī aprēķināt rekurences reizinātāju.
[`sin(x * x)` funkcijas attēlojums pirmajām 4 rindiņām izmantojot gnuplot](https://github.com/ReinisVigulis/RTR105/assets/144206407/8ad99ea9-a397-4539-acc1-ad3e9240bb20)

Izmantojot 'gnuplot' var ļoti labi vizualizēt un saprast, ko tad pirmais kods parāda, kā var saprast pēc grafika ir redzams sin (x * x) grafiks. Funkcijas `s0(x)` - `s4(x)` sākumā sakrīt ar orģinālfunkciju    `sin(x * x)`. Katra nākamā funkcija ilgāku laika periodu sakrīt ar `sin (x * x)`. Dotais grafiks ļoti labi parāda, kā darbojas teilora rindas.

## Gnuplot sin (x * x) koda piemērs!
gnuplot> set title "SIN (x * x)"                                                       
gnuplot> set xrange [-3:3]                                                             
gnuplot> set yrange [-3:3]                                                             
gnuplot> a0(x) = x**2 / (1)                                                            
gnuplot> a1(x) = -x**6 / (1*2*3) 
gnuplot> a2(x) = x**10 / (1*2*3*4*5)
gnuplot> a3(x) = -x**12 / (1*2*3*4*5*6*7)                                              
gnuplot> a4(x) = x**16 / (1*2*3*4*5*6*7*8*9)                                           
gnuplot> s0(x) = a0(x)                                                                 
gnuplot> s1(x) = a0(x) + a1(x)                                                         
gnuplot> s2(x) = a0(x) + a1(x) + a2(x)                                                 
gnuplot> s3(x) = a0(x) + a1(x) + a2(x) + a3(x)                                         
gnuplot> s4(x) = a0(x) + a1(x) + a2(x) + a3(x) +a4(x)                                  
gnuplot> plot sin(x*x) lw 3, s0(x) lw 3, s1(x) lw 3, s2(x) lw 3, s3(x) lw 3, s4(x) lw 3 

## Teilora rindas - kods, gala versija sin (x * x) 
Uzdevums bija izveidot kodu, kas izmantojot teilora rindas rekurences rezinātāju aprēķinās funkcijas `sin (x * x)` vērtību pie attiecīgās `x` vērtības. Es vadījos pēc dotā pasniedzējas piemēra, to pārveidojot savai funkcijai.
Lietotājam tiek paprasīts ievadīt skaitli `x`. Pēc koda palaišanas tiek parādīts standarta funkcijas rezultāts, un tālāk tiek izrēķināts manas funkcijas rezultāts izmantojot teilora rindas, kā arī aprēķinātās summas pirmspēdējais un pēdējais rezultāts.

```
sin (x * x) aprēķināšana:
Ievadiet decimālu skaitli: 5
standarta funkcija - y=sinx^2(5.00 * 5.00)= -0.13
a499 =       S499 = 
a500 =       S500 =
lietotāja funkcija - y=mana_funkcija sinx^2(5.00)= -0.13

               500
               ===          k   (4 * k + 2)
               \        (-1) * x
sin(5 * 5) =    /     = ------------------------
               ===            (2 * k + 1)!
              k = 0

                                 1   4
                             (-1) * x
rekurences reizinātājs: -------------------
                         (2 * k) * (2 * k + 1)

```
Kā redzam izveidotais kods strādā, taču iedziļinoties savā kodā es pamanīju problēmu. Piemēram piešķirot mainīgajam `x` vērtību (10). Koda rezultāts ir 
```
standarta funkcija - y=sinx^2(10.00 * 10.00)= -0.51
lietotāja funkcija - y=mana_funkcija sinx^2(10.00)= -31041717557729444233216.00
```
Kā redzams, lietotāja funkcijas rezultāts ir kāds mistisks skaitlis, kas nav pareizs, jo funkcijas `sin (x * x)` rezultātam ir jābūt robežās no [-1 : 1].
Analizējot kodu un meklējot kļūdu, ar pasniedzējas palīdzību tika konstatēts, ka kļūdu rada long double datu tipa īpatnības, es to sapratu tā, ka veicot aritmētiskas darbības ar long double datu tipu, pēc kārtas izpildot darbības uzkrājas kļūda, un ņemot vērā to, ka aprēķinot nākamo rezultā vērā tiek ņemts iepriekšējais rezultāts, tādēļ kļūda uzkrājas arvien lielāka un rezultāts ir kļūdains.
Vairāk par šo īpatnību ir aprakstīts šeit 

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
    printf("lietotāja funkcija - y = mana_funkcija sinx^2(%.2Lf) = %.2Lf\n", x, yy);
    printf("Second to last term: %.2f\n", (double)seclast);

    return 0;
}

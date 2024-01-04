# Skaitliskās metodes - skaitliskā diferencēšana sin(x*x)
Funkcijas pieauguma un argumenta pieauguma attiecības robežu, kad argumenta pieaugums tiecas uz nulli, sauc par funkcijas atvasinājumu vai diferencēšanu.

Laboratorijas darba uzduvums ir uzrakstīt kodu, kas manai funkcijai ``sin(x*x)``, aprēķinātu pirmās un otrās kārtas atvasinājumu ar divām dažādām metodēm, analītisko un skaitlisko, jeb diferencēšanu uz priekšu. Kā arī lietotājam tiek prasīts ievadīt vērtības ``a`` un ``b``, kas parāda intervālu kādā tiks meklēts atvasinājums. Lietotājam ir jāievada arī precizitāte, jeb solis pēc, pēc kura tiks veikta nākamā interācija.

Koda piemērs
```
#undef __STRICT_ANSI__

#include <stdio.h>
#include <math.h>

void main()
{
 float a = 0. ,b = 2 * M_PI, x, delta_x = 1.e-2;
 //floaty;
 printf("     x  \t    sin(x*x)  \t   sin\'an(x)  \t   sin\''an(x)  \t  'sk(x)  \t  ''sk(x)\n");
 x = a;
 while(x < b)
 {
//y=sin(x);
  printf("%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\n" ,x, sin(x*x), 2*x * cos(x*x),2 * cos(x*x) - 4 * x * x * sin(x*x), (sin((x + delta_x) * (x + delta_x)) - sin(x*x)) / delta_x, (sin((x + delta_x) * (x + delta_x)) - 2 * sin(x * x) + sin((x - delta_x) * (x - delta_x))) / (delta_x * delta_x));
;
  //printf(”%10.2f\t%10.2f\n”,x,y);
  x += delta_x; //x=x+delta_x;
 }
}
```
```
float a = 0. ,b = 2 * M_PI, x, delta_x = 1.e-2;
```
Šajā koda rindiņā tiek parādīts, ka mainīgā `x` intervāls ir no `0 līdz 2 * pi` un solis jeb precizitāte pēc cik tiks aprēķināta nākamā funkcijas vērtība, kas tieši šajā gadījumā ir ``1*10^-2 jeb 0.01``.

```
int main(){
float a, b , x, delta_x;

printf("Ievadiet funkcijas intervāla robežu no kreisās puses - \n");
scanf("%f", &a);

printf("Ievadiet funkcijas intervāla robežu no labās puses - \n");
scanf("%f", &b);

printf("Ievadiet precizitāti - \n");
scanf("%f", &delta_x);
```
Veids kā iegūt dialogu ar lietotāju nepieciešamo vērtību iegūšanai

Skaidrojums, kā notiek atvasinājuma vērtības aprēķināšana:
```
x, sin(x*x), 2*x * cos(x*x),2 * cos(x*x) - 4 * x * x * sin(x*x)
```
`x` mainās no ``0 līdz 2 * pi``, katru interāciju mainoties par uzdoto precizitāti, kas ir ``0,01``

``sin(x*x)`` ir funkcijas vērtība atkarībā no x vērtības.

`` 2*x * cos(x*x)`` ir pirmās kārtas analītiskais atvasinājums funkcijai sin(x*x)

``2 * cos(x*x) - 4 * x * x * sin(x*x)`` ir otrās kārtas analītiskais atvasinājums funkcijai sin(x*x)
```
(sin((x + delta_x) * (x + delta_x)) - sin(x*x)) / delta_x
```
ir funkcijas sin(x*x) pirmās kārtas skaitliskais atvasinājums. 
(sin((x + delta_x) * (x + delta_x)) šī daļa aprēķina sīnusa kvadrāta vērtību punktā x + delta_x.
tālāk tiek atņemta sin(x*x) vērtība un iepriekš minēto sīnusa vērtību starpību izdala ar delta_x jeb soli iegūstot skaitlisko atvasinājumu.

```
(sin((x + delta_x) * (x + delta_x)) - 2 * sin(x * x) + sin((x - delta_x) * (x - delta_x))) / (delta_x * delta_x)
```
ir funkcijas sin(x*x) otrās kārtas skaitliskais atvasinājums.

Skaitlisko atvasinājumu izmanto, ja nav pieejams analītiskais atvasinājums, vai arī tas ir ļoti sarežģīts vai arī, ja funkcija ir dota tikai ar skaitliskiem punktiem, nevis ar konkrētu analītisku formulu.

Skaitliskais atvasinājums ir precīzāks nekā analītiskais, protams liela nozīmē šajā gadījumā ir izvēlētajam solim, jeb precizitātei.
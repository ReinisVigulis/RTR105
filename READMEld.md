# Skaitliskās metodes - Teilora rindas - sin (x * x)

Teilora virkne ir ideja, ko izmanto datorzinātnē, rēķināšanā, ķīmijā, fizikā un citos augstāka līmeņa matemātikas procesos. Tā ir rinda, ko izmanto, lai izveidotu aplēsi (minējumu) par to, kā izskatās kāda funkcija.
Teorija, kas ir Teilora rindu pamatā, ir tāda, ka, ja koordinātu plaknē (x un y asīs) tiek izvēlēts punkts, tad ir iespējams uzminēt, kā funkcija izskatīsies apgabalā ap šo punktu. To var izdarīt, ņemot funkcijas atvasinājumus un saskaitot tos kopā. Ideja ir tāda, ka ir iespējams saskaitīt bezgalīgi daudz atvasinājumu un iegūt vienu galīgo summu.

Pirmais uzdevums bija matemātiski izrēķināt manas funkcijas 'sin (x * x)' vērtību, katru rezi palielinot nezināmā (k) vērtību no 0 līdz 4, kā arī aprēķināt rekurences reizinātāju.
[sin(x * x) funkcijas attēlojums pirmajām 4 rindiņām izmantojot gnuplot] (https://github.com/ReinisVigulis/RTR105/assets/144206407/8ad99ea9-a397-4539-acc1-ad3e9240bb20)

Izmantojot 'gnuplot' var ļoti labi vizualizēt un saprast, ko tad pirmais kods parāda, kā var saprast pēc grafika ir redzams sin (x * x) grafiks. Funkcijas `s0(x)` - `s4(x)` parāda cik tuvu esam pietuvojušies funkcijai `asin(x)`. Kā redzams, katra nākamā funkcija rindā rada grafiku, kas aiz vien vairāk pietuvinās funkcijai `asin(x)`. Saskaitot katras šīs funkcijas vērtību mainīgajam `x` ir iespējams iegūt vērtību, kas ir pietuvināta funkcijas `asin(x)` patiesajam rezultātam.

gnuplot> set title "SIN (x * x)"                                                       
gnuplot> set xrange [-3:3]                                                             
gnuplot> set yrange [-3:3]                                                             
gnuplot> a0(x) = x**2 / (1)                                                            
gnuplot> a1(x) = -x**6 / (1*2*3)                                                       
gnuplot> a3(x) = -x**12 / (1*2*3*4*5*6*7)                                              
gnuplot> a4(x) = x**16 / (1*2*3*4*5*6*7*8*9)                                           
gnuplot> s0(x) = a0(x)                                                                 
gnuplot> s1(x) = a0(x) + a1(x)                                                         
gnuplot> s2(x) = a0(x) + a1(x) + a2(x)                                                 
gnuplot> s3(x) = a0(x) + a1(x) + a2(x) + a3(x)                                         
gnuplot> s4(x) = a0(x) + a1(x) + a2(x) + a3(x) +a4(x)                                  
gnuplot> plot sin(x*x) lw 3, s0(x) lw 3, s1(x) lw 3, s2(x) lw 3, s3(x) lw 3, s4(x) lw 3 

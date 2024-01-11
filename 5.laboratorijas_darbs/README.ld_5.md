# Skaitliskās metodes - skaitļu kopas kārtošana un statistika.
Statistika - matemātikas nozare, kas pēta datu savākšanas, sistematizēšanas, apstrādes, izmantošanas un interpretācijas metodes.

Laboratorijas darba galvenais uzdevums ir sakārtot simbolu rindu alfabēta secībā (saskaņā ar ASCII skaitļiem). 

### Amerikas informācijas apmaiņas standartkods jeb ASCII 
 Rakstzīmju kopa un kodējums, kas balstīts uz modernajā angļu valodā un citās Rietumeiropas valodās lietoto latīņu alfabētu. Visplašāk to izmanto datoros un citās komunikāciju ierīcēs, lai attēlotu tekstu un kontrolētu ierīces, kas strādā ar tekstu.
 Tajā ietilpst 128 noteiktas rakstzīmes, kas tiek pārvērstas veselos 7 bitu skaitļos, 95 no šīm rakstzīmēm ir drukājamas, proti, tās ir cipari no 0 līdz 9, mazie burti no a līdz z, lielie burti no A līdz Z un pieturzīmju simboli.

Lai sakārtoto simbolu rindu vienā rindā un atbilstošus ASCII skaitļus nākamajā rindā
rindas kārtošana alfabēta secībā - A, B, C, ..., a, b, c, ... (saskaņā ar ASCII skaitļiem), es pielietoju tā saucamo **Burbuļu metodi**, kura katrā ciklā rindas galā izvirzīs vislielāko vai vismazāko skaitli. Metodes pamatā ir blakusesošo rindas elementu salīdzināšana un to maiņa vietām, ja nav pareizā secība.

### Daļa no mana koda, lai sakārtotu simbolu rindu izmantojot (Burbuļu metodi).
```
do {
    swapped = false;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
               
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
    }
} while (swapped);
```
Šis kods ir optimizēts ar ``do - while`` ciklu. Būtiskākā īpašība ir tā, ka swapped mainīgais tiek izmantots, lai noteiktu, vai masīvs jau ir sakārtots, un izvairītos no liekajām iterācijām. Tas palīdz uzlabot algoritma efektivitāti. ``do - while`` cikls turpinās līdz momentam, kad ``swapped`` paliek ``true``. Ja ciklā nav bijusi neviena apmaiņa, ``swapped būs false`` un cikls beigsies. 


![Bubble sorting vizualizācija ](image.png)

Vairāk informācijas par Burbuļu metodi var iegūt https://www.youtube.com/watch?v=YqzNgaFQEh8

```
int start = 0;
while (arr[start] == ' ' && start < length) {
    start++;
}

```
Ar šīm koda rindiņām tiek atrasts pirmais ne tukšais simbols, jeb vienkāršāk sakot (simbols, kas nav atstarpe), vai arī tiek atrastas simbolu rindas beigas, ja nav atstarpju. Tas ir nepieciešams, lai kods būtu optimizēts un lietotājs varētu ievadīt teikumu ar atstarpēm, taču statistikas elementu aprēķinos un simbolu rindā atstarpes tiek ignorētas.

### Lielākā un mazākā vērtība
```
*min = (start < length) ? arr[start] : '\0';
*max = (length > 0) ? arr[length - 1] : '\0';
```
Šeit ir parādīts, kā tiek atjaunoti ``min un max`` simboli, norādot uz pirmo un pēdējo ne-tukšo simbolu masīvā. Ja masīvs ir tukšs vai satur tikai atstarpes, rādītāji tiek atjaunoti ar nulles simbolu ('\0').

### Vidējā vērtība
```
for (i = start; i < length; i++) {
    if (arr[i] != ' ') {
        sum += (int)arr[i];
    }
}
int nonSpaceCount = length - start;
*middle = (nonSpaceCount > 0) ? sum / nonSpaceCount : '\0';
```
Tiek aprēķināta aritmētiski vidējā vērtība kā vesels skaitlis, atstarpes neņemot vērā.

### Moda
```
     *modeCount = 0;

    for (i = start; i < length; i++) {
        if (arr[i] != ' ') {
            if (i > start && arr[i] == arr[i - 1]) {
                currentCount++;
            } else {
                currentCount = 1;
            }

            if (currentCount > maxCount) {
                maxCount = currentCount;
                *modeCount = 1; 
                modes[0] = arr[i];
                counts[0] = currentCount;
            } else if (currentCount == maxCount) {
                
                modes[*modeCount] = arr[i];
                counts[*modeCount] = currentCount;
                (*modeCount)++;
            }
        }
    }
```
No sākuma tiek pārbaudīts, vai masīvā ir ne-tukši simboli ``nonSpaceCount > 0``. Ja, jā tad pirmais atrastais simbols tiek uzskatīts par modu. Ja masīvs ir tukšs, tad moda tiek iestatīta uz nulles simbolu ('\0'). Kods ir arī optimizēts, lai varētu attēlot gadījumus, kad modas ir vairākas, nevis tikai viens simbols.

Cikls pārvietojas pa masīvu un salīdzina katru ne-tukšo simbolu ar iepriekšējo. Ja tie ir vienādi, tad tiek palielināts ``currentCount`` (pašreizējais sastopamo simbolu skaits). Ja tie nav vienādi, tad ``currentCount`` tiek atiestatīts uz 1, jo nākamais simbols ir savādāks.

Tas ļauj noteikt, kāds simbols masīvā ir visvairāk sastopams un cik bieži tas atkārtojas.

### Mediāna
```
if (nonSpaceCount % 2 == 0) {
        // Even-length sentence, output two middle characters
        median[0] = (nonSpaceCount > 0) ? arr[start + nonSpaceCount / 2 - 1] : '\0';
        median[1] = (nonSpaceCount > 1) ? arr[start + nonSpaceCount / 2] : '\0';
    } else {
        // Odd-length sentence, output one middle character
        median[0] = (nonSpaceCount > 0) ? arr[start + nonSpaceCount / 2] : '\0';
        median[1] = '\0'; // Null-terminate the string
    }

```
Tiek aprēķināta mediāna, vērtība, kas atbilst sakārtota masīva vērtībai, kas atrodas tieši pa vidu.

Ja masīva garums ir nepāra skaitlis, tad mediāna tiek attēlots kā viens simbols.
Ja masīva garums ir pāra skaitlis, tad mediāna tiek attēlota kā divi vidējie simboli.

### Piemērs koda darbībai
```
Ievadiet teikumu: jo ho ho
Sākartota simbolu rinda (atstarpes neņemot vērā):   hhjooo
Simbolu ASCII vērtības: 104 104 106 111 111 111
Mazākā vērtība: h
Lielākā vērtība: o
Vidējā vērtība (saskaņā ar ASCII skaitļiem): 107
Modas vērtība(s): o - Count: 3
Mediānas vērtība(s): jo
```
Atšķirībā no citiem laboratorijas darbiem, šis ir vairāk pielietojams sadzīvē un statistikā. Principā, galvenais uzdevums bija sakārtot simbolu rindu alfabēta secībā un izdomāt, kā neievērot atstarpes, jo arī atstarpe ir simbols, bet lietotājam rakstot teikumu ir svarīgi atdalīt vārdus ar atstarpi, lai teikums būtu pārskatāms. 
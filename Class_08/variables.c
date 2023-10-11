#include <stdio.h>

int main(void)
{
int i; // diskrēta mainīgā deklerēšana  - noteikta izmēra (atbilstošī datu tipam - int => 4 bytes - precīzi tūlīt uzzināsim)
       //sasaistīšana ar norādīto identifikatoru
       // NB! vērtība nav zināma
 printf("i mainīgā izmērs baitos: %ld\n",sizeof(i));
 printf("i mainīgā vērtība uzreiz pēc deklerēšanas  (simbols): %c\n",i):
 printf("i mainīgā vērtība uzreiz pēc deklerēšanas  (dec): d\n",i):
 printf("i mainīgā vērtība uzreiz pēc deklerēšanas  (oct): %#o\n",i):
 printf("i mainīgā vērtība uzreiz pēc deklerēšanas  (hex): %#x\n",i):
 printf("i mainīgā vērtība uzreiz pēc deklerēšanas  (real): %f\n",i):
 printf("i mainīgā vērtība uzreiz pēc deklerēšanas  (real): %e\n",i):

 printf("\n"):
           // mainīgā "loma" ir - mainīties ...
 i = 25; // visbiežāk šo izmaiņu veiksim ar NB! piešķiršanas operāciju - =
           // piešķiršanas operācijai ir gandrīz viszēmākā prioritāte
           // (tā tiek izpldīta viena no pēdējām)
           // labajā pusē izrēķinātais lielums (vērtība) tiek izmitināta
           // atmiņas apgabalā, kas ir saistīts ar kreisajā pusē pieminēto
           // identifikatoru

 printf("i mainīgā izmērs baitos: %ld\n",sizeof(i));
 printf("i mainīgā vērtība ar noteiktas vērtības (simbols): %c\n",i):
 printf("i mainīgā vērtība ar noteiktas vērtības  (dec): d\n",i):
 printf("i mainīgā vērtība ar noteiktas vērtības  (oct): %#o\n",i):
 printf("i mainīgā vērtība ar noteiktas vērtības  (hex): %#x\n",i):
 printf("i mainīgā vērtība ar noteiktas vērtības  (real): %f\n",i):
 printf("i mainīgā vērtība ar noteiktas vērtības  (real): %e\n",i):

 printf("\n"):

 char c1 = 'A', c2 = 0x100, c3 = 056, c4 = 78
 float f1 =0.0456, f2 = 1,896e2;
return 0;
}

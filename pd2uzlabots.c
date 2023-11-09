#include<stdio.h>
int main() {
int skaitlis1;
char bit0;
char bit1;
char bit2;
char bit3;
char bit4;
char bit5;
char bit6;
char bit7;
printf("Uzrakstiet naturālu skaitli: ");
scanf("%d", &skaitlis1);
fflush(stdin);
printf ("%d", skaitlis1);
if(skaitlis1 < 0 && skaitlis1 > 255 ){
   printf("Ievadiet naturālu skaitli\n");
   return 0;
}


bit7 = skaitlis1 >> 7 & 1;
printf("%d", bit7);
bit6 = skaitlis1 >> 6 & 1;
printf("%d", bit6);
bit5 = skaitlis1 >> 5 & 1;
printf("%d", bit5);
bit4 = skaitlis1 >> 4 & 1;
printf("%d", bit4);
bit3 = skaitlis1 >> 3 & 1;
printf("%d", bit3);
bit2 = skaitlis1 >> 2 & 1;
printf("%d", bit2);
bit1 = skaitlis1 >> 1 & 1;
printf("%d", bit1);
bit0 = skaitlis1 >> 0 & 1;
printf("%d", bit0);
//printf("Skaitlis %hhu binārajā kodā ir: ", skaitlis1 );
//for (int i = 7; i >= 0; i--) {
    //if ((skaitlis1 >> i) & 1){
     //printf("1");
    //}

   // else{
       // printf("0");
    //}
//}

//printf("\n");
return 0;
}

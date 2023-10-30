#include<stdio.h>
int main() {
unsigned char skaitlis1;

printf("Uzrakstiet naturālu skaitli: ");
scanf("%hhu", &skaitlis1);

printf("Skaitlis %hhu binārajā kodā ir: ", skaitlis1 );
for (int i = 7; i >= 0; i--) {
    if ((skaitlis1 >> i) & 1){
     printf("1");
    }

    else{
        printf("0");
    }
}

printf("\n");
return 0;
}

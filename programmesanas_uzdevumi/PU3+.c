#include<stdio.h>
int main(){
char c1, c2, c3;
char secība;
printf("Kādā secībā vēlaties attēlot burtus, augošā (a), vai dilstošā (d), alfabēta secībā?\n");
scanf("%c", &secība);
if(secība == 'a'){

 printf("Uzrakstiet trīs burtus.\n");
 scanf(" %c %c %c", &c1, &c2, &c3);

  int mazākais, vidējais, lielākais;

  if(c1 <= c2 && c1 <= c3){
    mazākais = c1;

     if(c2 <= c3){
        vidējais = c2;
        lielākais = c3;
     }
     else{
        vidējais = c3;
        lielākais = c2;
     }
  }
 else if (c2 <= c1 && c2 <= c3){
     mazākais = c2;
     if(c1 <= c3){
        vidējais = c1;
        lielākais = c3;
    }
     else{
        vidējais = c3;
         lielākais = c1;
     }
 }
 else{
     mazākais = c3;
     if(c1 <= c2){
         vidējais = c1;
         lielākais = c2;
     }
     else{
         vidējais = c2;
         lielākais = c1;
     }

 }
printf("augošā kārtībā: %c %c %c\n", mazākais, vidējais, lielākais);
}
else if(secība == 'd'){
    printf("Uzrakstiet trīs burtus.\n");
 scanf(" %c %c %c", &c1, &c2, &c3);

  int mazākais, vidējais, lielākais;

  if(c1 <= c2 && c1 <= c3){
    mazākais = c1;

     if(c2 <= c3){
        vidējais = c2;
        lielākais = c3;
     }
     else{
        vidējais = c3;
        lielākais = c2;
     }
  }
 else if (c2 <= c1 && c2 <= c3){
     mazākais = c2;
     if(c1 <= c3){
        vidējais = c1;
        lielākais = c3;
    }
     else{
        vidējais = c3;
         lielākais = c1;
     }
 }
 else{
     mazākais = c3;
     if(c1 <= c2){
         vidējais = c1;
         lielākais = c2;
     }
     else{
         vidējais = c2;
         lielākais = c1;
     }

 }

printf("dilstošā kārtībā: %c %c %c\n", lielākais, vidējais, mazākais);
}
else{
    printf("Jūs ievadījāt nepareizus lielumus.\n");
} 
  
return 0;
}
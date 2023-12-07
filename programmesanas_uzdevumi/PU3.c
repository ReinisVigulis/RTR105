#include<stdio.h>
int main(){
int s1, s2, s3;
char secība;
printf("Kādā secībā vēlaties attēlot skaitļus, augošā (a), vai dilstošā (d)?\n");
scanf("%c", &secība);
if(secība == 'a'){

 printf("Uzrakstiet trīs skaitļus.\n");
 scanf("%d %d %d", &s1, &s2, &s3);

  int mazākais, vidējais, lielākais;

  if(s1 <= s2 && s1 <= s3){
    mazākais = s1;

     if(s2 <= s3){
        vidējais = s2;
        lielākais = s3;
     }
     else{
        vidējais = s3;
        lielākais = s2;
     }
  }
 else if (s2 <= s1 && s2 <= s3){
     mazākais = s2;
     if(s1 <= s3){
        vidējais = s1;
        lielākais = s3;
    }
     else{
        vidējais = s3;
         lielākais = s1;
     }
 }
 else{
     mazākais = s3;
     if(s1 <= s2){
         vidējais = s1;
         lielākais = s2;
     }
     else{
         vidējais = s2;
         lielākais = s1;
     }

 }
printf("augošā kārtībā: %d %d %d\n", mazākais, vidējais, lielākais);
}
else if(secība == 'd'){
    printf("Uzrakstiet trīs skaitļus.\n");
 scanf("%d %d %d", &s1, &s2, &s3);

  int mazākais, vidējais, lielākais;

  if(s1 <= s2 && s1 <= s3){
    mazākais = s1;

     if(s2 <= s3){
        vidējais = s2;
        lielākais = s3;
     }
     else{
        vidējais = s3;
        lielākais = s2;
     }
  }
 else if (s2 <= s1 && s2 <= s3){
     mazākais = s2;
     if(s1 <= s3){
        vidējais = s1;
        lielākais = s3;
    }
     else{
        vidējais = s3;
         lielākais = s1;
     }
 }
 else{
     mazākais = s3;
     if(s1 <= s2){
         vidējais = s1;
         lielākais = s2;
     }
     else{
         vidējais = s2;
         lielākais = s1;
     }

 }

printf("dilstošā kārtībā: %d %d %d\n", lielākais, vidējais, mazākais);
}
else{
    printf("Jūs ievadījāt kaut ko nepareizi\n");
} 
  
return 0;
}
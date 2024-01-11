#undef __STRICT_ANSI__

#include <stdio.h>
#include <math.h>

int main(){
float a, b , x, delta_x;

printf("Ievadiet funkcijas intervāla robežu no kreisās puses - \n");
scanf("%f", &a);

printf("Ievadiet funkcijas intervāla robežu no labās puses - \n");
scanf("%f", &b);

printf("Ievadiet precizitāti - \n");
scanf("%f", &delta_x);
//floaty;
printf(" x\tsin(x*x)\tsin\'an(x)\tsin\''an(x)\t'sk(x)\t''sk(x)\n");
x = a;
while(x < b)
 {
//y=sin(x);
   printf("%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\n" ,x, sin(x*x), 2*x * cos(x*x),2 * cos(x*x) - 4 * x * x * sin(x*x), (sin((x + delta_x) * (x + delta_x)) - sin(x*x)) / delta_x, (sin((x + delta_x) * (x + delta_x)) - 2 * sin(x * x) + sin((x - delta_x) * (x - delta_x))) / (delta_x * delta_x));
   
  //printf(”%10.2f\t%10.2f\n”,x,y);
   x += delta_x; //x=x+delta_x;
 }
}
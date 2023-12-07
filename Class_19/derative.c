#undef __STRICT_ANSI__

#include <stdio.h>
#include <math.h>

void main()
{
 float a = 0. ,b = 2 * M_PI, x, delta_x = 1.e-2;
 //floaty;
 printf("\tx\t\tsin(x*x)\t\t sin\'an(x)\t\tsin\'sk(x)\n");
 x = a;
 while(x < b)
 {
//y=sin(x);
  printf("%8.2f\t%8.2f\t%8.2f\t%8.2f\n" ,x, sin(x*x), 2*x * cos(x*x),(sin(x*x + delta_x) - sin(x*x)) / delta_x);
  //printf(”%10.2f\t%10.2f\n”,x,y);
  x += delta_x; //x=x+delta_x;
 }
}
#undef __STRICT_ANSI__
#include <stdio.h>
#include <math.h>

void main(){
float a = 0. ,b = M_PI/2, eps=1.e-3, h, integr1 = 0. ,integr2, x;
int k, n=2;

integr2 =(b-a)*(sin(a*a)+sin(b*b))/n;//(b−a)/2.∗sin(a)+(b−a)/2.∗sin(b);
while(fabs(integr2-integr1)>eps)
{
   n*=2;
   h=(b-a)/n;
   integr1 = integr2;
   integr2 = 0.0;
   for(k=0;k<n;k++)
    {
       x = (a+(k+0.5) *h); 
       integr2+= h*sin(x*x);

    }
//integr2+= h* sin((a+(k+0.5) *h)*(a+(k+0.5) *h));

      printf("(elementu skaits - %d) Integraalja veertiiba: %.4f \n",n, integr2);
}
printf("Integralja vertiba : %.2f\n", integr2);
}
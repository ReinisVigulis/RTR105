#undef __STRICT_ANSI__
#include <stdio.h>
#include <math.h>

float modified_sin2(float x, float A){
    return sin(x * x)-A;}

    void main(){
        float a, x, delta_x, b, y, A;
        a = 0;
        b = 2*M_PI;

        printf("Cien. liet., luudzu, ievadiet A veertibu sekojošajam vienadojumam:sin(x * x)=A\n");
        scanf("%f", &A);
        x = a;
        delta_x = 0.1;
        printf("\tx\ty\n");
        while(x<b)
        {
            printf("%10.1f%10.1f\n", x, modified_sin2(x,A));
            x += delta_x;
        }


    }

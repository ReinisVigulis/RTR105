#include <stdio.h>

void sveicinasanas(){
    printf("Sveiks, lietotaaj!\n");
}

void skaitisana (int x, int y){
    printf("Saskaitot %d un %d rezultats ir %d\n", x, y);
}

int gadi(){
    printf("Vecums - ");
    return 19;
}

int reizinasana(int x, int y){
    //printf("%d * %d =", x, y);
    return x * y;
}

int main(){
    sveicinasanas();

    skaitisana(4, 5);

    int result1 = gadi();
    printf("Gadi : %d\n", result1);

    int result2 = reizinasana(3,4);
    printf("3 * 4 = : %d\n", result2);
    return 0;
}
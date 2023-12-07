#include<stdio.h>
int main() {
   int long long skaitlis1, skaitlis2, rezultats;

    printf("Ierakstiet pirmo skaitli 400 000 (četri simti tūkstoši) : ");
    scanf("%lld", &skaitlis1);

    printf("Ieraksiet otro skaitli 100 000 (simts tūkstoši) : ");
    scanf("%lld", &skaitlis2);

    rezultats = skaitlis1 * skaitlis2;
    if(rezultats == 40000000000) {
    
    printf("Reizinājums ir: %lld\n", rezultats);
}
    else { 
    printf("Ievadītas nepareizas vērtības, jo reizinājums sanāk: %lld\n", rezultats);
}
    return 0;
}

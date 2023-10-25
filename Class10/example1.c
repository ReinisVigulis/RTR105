#include <stdio.h>
int main()
{
    char name[30];
    printf("Uzrakstiet teikumu: ");
    fgets(name, sizeof(name), stdin);  // read string
    
int size = 0;
int skaititajs = 0;
    printf("Name: ");
    for (int i =0; i < 30; i++)
    {
     size = size +1;
     if(name[i] == 32||name [i] == '\0');
      {
       if(size > 5){
        skaititajs = skaititajs +1;
        }

      size = 0;

      
      }



    }
    printf("%d", skaititajs);
    printf("\n");
    return 0;
}


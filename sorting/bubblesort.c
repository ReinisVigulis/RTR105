#include <stdio.h>
#include <stdbool.h>
int main(void)
{
  int a[] = {8,5,9,3,0,1,2,6,4,7};
  
  int lenght = 10;
  bool swapped = false;
  int i = 0;
do 
{
  swapped = false;
  for (int i = 0; i < lenght; i++)
  {
    for (int j =0; j< (lenght - 1 - i); j++)
    {
        if (a[j] > a[j + 1]) 
        {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            swapped = true;
        }
    }
  }
  i++;
  } while (swapped);
  for (int i = 0; i < lenght; i++)
     printf("a[%d] = %d\n", i, a[i]);






    return 0;
}

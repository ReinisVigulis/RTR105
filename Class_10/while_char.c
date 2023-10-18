#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void) 
{
char i = 1;
int flag = 1, counter = 0;
int grauds;
grauds = time(NULL);
srand(grauds);
while( flag )
 {
 counter++;
 flag = rand();

 }
printf("counter = %d", counter);


return 0;
}

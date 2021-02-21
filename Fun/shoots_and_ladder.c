#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
   int dice_roll = (rand()%(6-1+1))+1;
   printf("%d\n", dice_roll);
}
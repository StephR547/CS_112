#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
   int num_1 = (rand()%(10-1+1))+1;
   printf("%d\n", num_1);


}
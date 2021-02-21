#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
   FILE *my_file = fopen("spoon.txt", "a");
   int num_of_people = 10;
   fprintf(my_file, "%d\n", num_of_people);
   fclose(my_file);

}
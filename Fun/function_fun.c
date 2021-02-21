#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random_val(int result){
   srand(time(NULL));
   int num_1 = (rand()%(100-1+1))+1;
   printf("%d\n", num_1);
   return result;
} 
int main(){
    char user_entry;
    printf("Press Enter to Spin\n");
    scanf("%c", &user_entry);
    random_val(user_entry);
}
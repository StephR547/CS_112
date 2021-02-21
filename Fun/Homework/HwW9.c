#include <stdio.h>

 int number(int input){
     int user_entry;
     printf("Please Enter in a Number:");
     scanf("%d",&user_entry);
     while(input != user_entry){
         printf("%d\n", input);
         input++;
     }
     return input;
     }
     int main(){
         int number_input;
         int results = number(number_input);
     }

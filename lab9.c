#include <stdio.h>
#include <string.h>
 
char get_response(int guess){
   char user_word_entry[100];
   printf("My Current Guess is: %d\n", guess);
   do{
       printf("Please Enter: HIGH, LOW, or EQUAL\n");
       scanf("%s", user_word_entry);
       printf("You Entered: %s\n", user_word_entry);
 }while((strcmp(user_word_entry, "HIGH") != 0) && (strcmp(user_word_entry, "LOW") != 0) && (strcmp(user_word_entry, "EQUAL") != 0));
 if(strcmp(user_word_entry, "HIGH") == 0){
     return '^';
 }else if(strcmp(user_word_entry, "LOW") == 0){
     return 'v';
 }else{
     return '=';
 }
}
int calculate_guess(int upper, int lower){
    int comps_guess = (upper + lower)/2; 
    return comps_guess;
}
void run_game(){
    int guess = 50;
    int upper = 100;
    int lower = 1;
    char response;
    do{
        response = get_response(guess);

        if(response == '^'){
            upper = guess - 1;
            printf("You entered that my guess was too HIGH\n");
            guess = calculate_guess(upper, lower);
        }else if(response == 'v'){
            lower = guess+1;
            printf("You entered that my guess was too LOW\n");
            guess = calculate_guess(upper, lower);
        }
    }while(response != '=');
    printf("I figured out your guess! It is: %d\n", guess);
}
int main(){
    char user_input[50];
    printf("Think of a number between 1-100\n");
    do{
    printf("Are you ready to play?\n");
    scanf("%s", user_input);
    printf("%s\n", user_input);
    }while(strcmp(user_input,"YES") != 0);
    run_game();

}

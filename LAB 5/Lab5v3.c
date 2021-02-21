#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
srand(time(NULL));
int current_game_score;
int amount_of_coins;
int current_save;
int command;
int new_game;
 
FILE*total_file=fopen("total.txt","r");
fscanf(total_file, "%d\n", &amount_of_coins);
printf("You currently have %d coins\n",amount_of_coins);

FILE*current_save_file=fopen("current_save.txt","r");
fscanf(current_save_file,"%d\n", &current_save);
fclose(current_save_file);
fclose(total_file);
if (current_save == 0) {
    current_game_score = 0;
} else{
    printf("You have an ongoing game with %d coins.\n",current_save);
} 
    do {
    printf("Please enter one of the following options:\n");
    printf("Enter a 0 to end your saved game.\n");
    printf("Enter a 1 to continue your game.\n");
    printf("Please enter a command:");
    scanf("%d",&command);
    } while(command != 0 && command != 1);
    
    if (command== 0 ){
        total_file=fopen("total.txt","w");
        printf("%d\n", amount_of_coins);
        int new_total= current_save+amount_of_coins;
 
        fprintf(total_file,"\n%d",new_total);
        fclose(total_file);
        printf("Your new total is %d\n",current_game_score);
        current_game_score=0;
        
    } else if (command== 1) {
        current_save_file=fopen("current_save.txt","w");
        current_game_score =current_save;
        fprintf(current_save_file,"\n0");
        fclose(current_save_file);
       
    }else {
        printf("Input Valid Choice");
    }
// part 2: The Main Game
  
    do{
    printf("Would you like to play?\n");
    printf("It would cost 5 coins to start a new game.\n");
    printf("Enter a 1 for yes or enter a 0 for no\n");
   
    scanf("%d",&new_game);
    
    }while (new_game != 1);
 
    if (new_game == 1 && command== 0) {
    int new_score= amount_of_coins-5;
    total_file=fopen("total.txt","w");
    fprintf(total_file,"\n%d", new_score);
    fclose(total_file);
    printf("Charging you 5 coins\nYour new total is now 0\n");
    current_game_score=5;
    
    int play_game;
    do{
        printf("Double or Nothing\n");
        printf("Guess the result of my coin flip and I'll double your money\n");
        printf("Your current amount is %d\n", current_game_score);
        printf("Enter your guess for the coin flip:\n");
        printf("0 for heads\n1 for tails\n");
        int coin_toss = (rand()%(1-0+1))+0;
        int guess;
        scanf("%d", &guess);
    
    if(guess== coin_toss ){   
        current_save_file=fopen("current_save.txt","w");
        fprintf(current_save_file,"\n%d", current_game_score*2);
        fclose(current_save_file);
 
        if (coin_toss == 0)
        {printf("Coin was heads\nYou guessed correctly\n");}
        else if (coin_toss == 1)
        {printf("Coin was tails\nYou guessed correctly\n");}
 
        printf("Your new score is %d\n", current_game_score*2);
        printf("Would you like to flip again?\n");
        printf("Enter a 1 for yes or a 0 for no\n");
        printf("Enter your response\n");
        scanf("%d", &play_game);
        
      
    }
    else if(guess != coin_toss)
    {   
        current_save_file=fopen("current_save.txt","w");
        fprintf(current_save_file,"\n%d", current_game_score-current_game_score);
        fclose(current_save_file);
 
        if (coin_toss == 0)
        {printf("Coin was heads\nYou guessed incorrectly\n");}
        else if (coin_toss == 1)
        {printf("Coin was tails\nYou guessed incorrectly\n");}
        
        printf("You lost\n");
    }
    }while (current_game_score != 0 && play_game !=0);
    {
    }
     if(new_game == 0){
            printf("Your current game score is %d\n",amount_of_coins);}
 
    // part 3
    if (current_game_score!=0){
    printf("Would you like to save you game? Or bank your earnings?\n");
    printf("Enter 0 to bank your earnings\nEnter 1 to save your game and continue next time\n");
    int save_game;
    scanf("%d\n", &save_game);
        do {
            if (save_game==0)
            {
            total_file=fopen("total.txt","a");
            fprintf(total_file,"\n%d", current_game_score+amount_of_coins);
            fclose(total_file);
            fprintf(current_save_file,"0");
            fclose(current_save_file);
            }
            else if(save_game==1)
            {
            current_save_file=fopen("current_save.txt","a");
            fprintf(current_save_file,"%d", current_game_score);
            fclose(current_save_file);
            }
    }while (save_game !=0 || save_game !=1);
    }
}
}



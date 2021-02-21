#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int get_math_expression(int *left_operand, char *operator, int *right_operand){
    *left_operand = (rand()%(10-0 +1)+0);
    *right_operand = (rand()%(10-0 +1)+0);

    int i = (rand()%(2-0+1)+0);
    if(i == 0){
        *operator = '+';
        return *left_operand + *right_operand;
    }else if(i == 1){
        *operator = '-';
        return *left_operand - *right_operand;
    }else{
        *operator = '*';
        return *left_operand * *right_operand;
    }
}
int ask_math_question(){
    int left_operand;
    int right_operand;
    int user_input;
    char operator;

    int answer = get_math_expression(&left_operand, &operator, &right_operand);
    printf("What is %d %c %d equal?\n", left_operand,operator,right_operand);
    scanf("%d", &user_input);
    if(user_input == answer){
        printf("You Got It Right!\n");
        return 1;
    }else{
        printf("Oops! That Was Wrong.\n");
        return 0;
    }  
}
int battle(int *player_health, int location){
    int bug_health = (location + 1) * 10;
    int x = location + 1;
    int bug_attack;
    int players_attack;

    printf("You Have Encountered A Level %d Bug\n", x);
    do{
        printf("Players Health: %d\n", *player_health);
        printf("Bugs Health: %d\n", bug_health);
        bug_attack = (rand()%(3-1+1)+1) * (location + 1);
        *player_health = *player_health - bug_attack;
        printf("You Recieved %d Damage From The Bug's Hit\n", bug_attack);
        if(*player_health <= 0){
            printf("You Have Ran Out Of Health!\n");
            printf("Your Vision Begins To Fade...\n");
            return 0;
        }else{
            printf("You Have %d Health Left\n", *player_health);
        }
        if(ask_math_question() == 1){
            players_attack = (rand()%(3-1+1)+1) * (location + 2);
            printf("You Attack Back And Gave %d Damage\n", players_attack);
            bug_health = bug_health - players_attack;
            printf("The Bug Has %d Health\n", bug_health);
            if(bug_health <= 0){
                printf("You Have Squashed The Bug!\n");
                return 1;
            }
        }else{
                printf("You Missed...\n");
            }

    }while(bug_health > 0 && *player_health > 0);
}

int main(){
   srand(time(NULL));
   char strings[3][20] = {"START", "MIDDLE", "END"};
   int player_health = 100;
   int location = 0;

   do{
       if(battle(&player_health, location) == 1){
           printf("Let Keep Traveling!\n");
           printf("You Are Now Leaving: %s LEVEL\n", strings[location]);
           location++;
           printf("You Are Arriving To: %s LEVEL\n", strings[location]);
       }else{
           printf("You Are Staying At: %s LEVEL\n", strings[location]);
       }
     }while(location < 3 && player_health > 0);
           if(location == 3){
               printf("CONGRATS! You Won The Game. You Know Your Math!\n");
           }
}
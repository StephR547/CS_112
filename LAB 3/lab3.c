#include "minion_linked.h"
#include <time.h>

void shop(minion_node **shop_list, minion_node **players_list, int up_bound){
    minion *monster = NULL;
    int player_choice;
    up_bound = 3;
    int players_rounds = 0;

    printf("Minion Shop:\n");

      for(int i = 0; i != 5; i++){
      struct minion *monster = (struct minion*) malloc(sizeof(struct minion));
      monster->health = (rand()%(up_bound - 1 + 1) + 1);
      monster->attack = (rand()%(up_bound - 1 + 1) + 1);
      minion_add_to_end(shop_list, *monster);
    }
    up_bound++;
    minion_display_with_indices(*shop_list);
        printf("Please Enter The Index of the Minion You Would Like To Buy: ");
        scanf("%d", &player_choice);
        
     minion_node *current_shop = *shop_list; 

     for(int i = 0; i != player_choice; i++){
        current_shop = current_shop->next;
     }
    printf("You Have Selected {Health %d, Attack %d} \n", current_shop->monster.health , current_shop->monster.attack);

    minion_node *current = *players_list;
    if(current == NULL){
        minion_add_to_start(players_list, current_shop->monster);
    }else{
        int min_placement;
        printf("Players Current Team:\n");
        minion_display_with_indices(*players_list);
        printf("Please Enter the Index Of Where You Would Like To Place Your New Minion: ");
        scanf("%d", &min_placement);
        minion_add_at_index(players_list, current_shop->monster, min_placement);
    }
    printf("Players Team:\n");
    minion_display_with_indices(*players_list);

}
void minion_list_overload(minion_node **player_list){
    minion_node *current = *player_list;

    if(minion_list_length(current) > 5){
    int remove_overload;
    printf("Which Index Would You Like To Remove: ");
    scanf("%d", &remove_overload);
    minion_remove_from_index(&current, remove_overload);
    minion_display_with_indices(*player_list);
   }
}


int main(){
    srand(time(NULL));

    minion_node *shop_list = NULL;
    minion_node *player_one_list = NULL;
    minion_node *player_two_list = NULL;
    minion_node *first_copy = NULL;
    minion_node *second_copy = NULL;

    int player_one_rounds = 0;
    int player_two_rounds = 0;
    int round = 0;
    int upper_bound =+ 3;
    int player_one_health = 30;
    int player_two_health = 30;

    printf("PLAYER 1 SELECTION:\n");
    while(player_one_rounds != 5){
        shop_list = NULL;
        shop(&shop_list, &player_one_list, upper_bound);
       player_one_rounds++;
    }

    printf("PLAYER 2 SELECTION:\n");
    while(player_two_rounds != 5){
        shop_list = NULL;
        shop(&shop_list, &player_two_list, upper_bound);
        player_two_rounds++;
    }

    first_copy = minion_list_copy(player_one_list);
    second_copy = minion_list_copy(player_two_list);
    minion_node *player_one = first_copy;
    minion_node *player_two = second_copy;

    while((player_one_health >= 0) && (player_two_health >= 0)){
        int damage_taken = 0;
        int remaining_minions = 0;
        
        printf("The Battle Is About To Begin\n");
        printf("Players One Team:\n");
        minion_display_with_indices(player_one_list);
        printf("Players Two Team:\n");
        minion_display_with_indices(player_two_list);

        minion_node *first_players_minion = first_copy;
        minion_node *second_players_minion = second_copy; 
       
        while((player_one != NULL)&&(player_two != NULL)){
            printf("Let The Battle Begin\n");
            printf("Round Starting: \n");
            int second_list_length = minion_list_length(second_copy);
            int second_player_randmin = (rand()%(second_list_length-0 +1)+0);
        for(int i=0; i != second_player_randmin; i++){
        second_players_minion = second_players_minion->next;
        }
            printf("PLayer 1's: {%d / %d} minion is know attacking player 2's:{%d / %d} minion\n", first_players_minion->monster.attack,first_players_minion->monster.health, second_players_minion->monster.attack,second_players_minion->monster.health);
            printf("Results:\n");
            second_players_minion->monster.health = second_players_minion->monster.health - first_players_minion->monster.attack;
            if((second_players_minion->monster.health <= 0)){
                minion_remove_from_index(&player_two_list, second_player_randmin);
                printf("Player 2's Minion Has Died\n");
                 second_players_minion = second_players_minion->next;
            }
            printf("Player 1's minion: {%d / %d}\n", first_players_minion->monster.attack, first_players_minion->monster.health);
            printf("Player 2's minion: {%d / %d}\n", second_players_minion->monster.attack, second_players_minion->monster.health);
        
            int first_list_length = minion_list_length(first_copy);
            int first_player_randmin = (rand()%(first_list_length-0 +1)+0);

        for(int i=0; i != first_player_randmin; i++){
        first_players_minion = first_players_minion->next;
        }
            printf("Player 2's: {%d / %d} minion is know attacking Player 1's: {%d / %d} minion\n",second_players_minion->monster.attack, second_players_minion->monster.health, first_players_minion->monster.attack, first_players_minion->monster.health);
            printf("Result:\n");
            first_players_minion->monster.health = first_players_minion->monster.health - second_players_minion->monster.attack;
            if((first_players_minion->monster.health <=0)){
                minion_remove_from_index(&player_one_list,first_player_randmin);
                printf("Player 1's Minion Has Died\n");
                first_players_minion = first_players_minion->next;
            }
            printf("Player 1's minion: {%d / %d}\n", first_players_minion->monster.attack, first_players_minion->monster.health);
            printf("Player 2's minion: {%d / %d}\n", second_players_minion->monster.attack, second_players_minion->monster.health);
        }

        if((player_one == NULL)&&(player_two != NULL)){
            remaining_minions = minion_list_length(second_copy);
           for(int i = 0; i < remaining_minions; i++){
               damage_taken = damage_taken + player_two->monster.attack;
           } 
            player_one_health= player_one_health - damage_taken;
            printf("Player 1's Health: %d\n", player_one_health);
            printf("Player 2 Remaining Team: \n"); 
            minion_display(second_copy);
            printf("Total Damage: %d",damage_taken);
            printf("Player 2's Health: %d\n", player_two_health);
        }else if((player_two == NULL) && (player_one != NULL)){
            remaining_minions = minion_list_length(first_copy);
            for(int i = 0; i < remaining_minions; i++){
               damage_taken = damage_taken + player_one->monster.attack;
           } 
            player_two_health = player_two_health - damage_taken;
            printf("Player 2's Health: %d\n", player_two_health);
            printf("Player 1 Remaining Team: \n"); 
            minion_display(first_copy);
            printf("Total Damage: %d",damage_taken);
            printf("Player 1's Health: %d\n", player_one_health);
        }
        upper_bound++;

        player_one_rounds = 1;
        shop(&shop_list, &player_one_list, upper_bound);
        player_two_rounds = 2;
        shop_list = NULL;
        shop(&shop_list, &player_two_list, upper_bound);
    }
     if(player_one_health == 0){
        printf("Player 1 Has Died... PLAYER 2 WINS!\n");
    }else if(player_two_health == 0){
        printf("Player 2 Has Died... PLAYER 1 WINS!\n");
    }

}
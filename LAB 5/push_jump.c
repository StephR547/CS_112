#include "doubly.h"
#include "singly.h"
#include <time.h>

void cards(card_node **card_list){
    card *list_of_cards = NULL;

     printf("Please Choose One Of The Followings:\n");

      for(int i = 0; i != 5; i++){
      struct card *list_of_cards = (struct card*) malloc(sizeof(struct card));
      list_of_cards->push = (rand()%(3 - 1 + 1) + 1);
      list_of_cards->jump = (rand()%(3 - 1 + 1) + 1);
      singly_add_to_start(card_list, *list_of_cards);
    }
}

void game_display(doubly *head_ptr, doubly *player1_ptr, doubly *player2_ptr){
    doubly *current = head_ptr;

    while(current != NULL){
        if((player1_ptr != current) && (player2_ptr != current)){
            printf(" >{ %c }< ", current->element);
        }else if(player1_ptr == current){
            printf(" >{ 1 }< ");
        }else if(player2_ptr == current){
            printf(" >{ 2 }< ");
        }
        current = current->next;
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    card_node *card_list = NULL;
    doubly *set_up = NULL;
    doubly *p1 = NULL;
    doubly *p2 = NULL;
    int active_player = 0;
    int player_choice;
    int winner;

    for(int i = 0; i < 5; i++){
        add_to_start(&set_up, 'N');
    }

    add_to_start(&set_up, 'G');

    for(int j = 0; j < 5; j++){
        add_to_start(&set_up, 'N');
    }

    p1 = set_up;
    p2 = set_up;

    while(p2->next != NULL){
        p2= p2->next;
    }

    
do{
    card_list = NULL;
    printf("Player 1's Turn:\n");
    game_display(set_up, p1, p2);
    cards(&card_list);
    singly_display_with_indices(card_list);
    printf("Please Enter Your Choice: ");
    scanf("%d", &player_choice);
        
     card_node *current_list = card_list; 

     for(int i = 1; i != player_choice; i++){
        current_list = current_list->next;
     }
    printf("You Have Selected %d) {Push %d, Jump %d} \n",player_choice, current_list->card_list.push , current_list->card_list.jump);
    for(int p = 0; p < current_list->card_list.push; p++){
        if(p2->next != NULL){
            p2 = p2->next;
         }
    }
    for(int j = 0; j < current_list->card_list.jump; j++){
        p1 = p1->next;
    } 
    game_display(set_up, p1, p2);
    printf("\n");

    card_list = NULL;
    printf("Player 2's Turn:\n");
    game_display(set_up, p1, p2);
    cards(&card_list);
    singly_display_with_indices(card_list);
    printf("Please Enter Your Choice: ");
    scanf("%d", &player_choice);
        
    current_list = card_list; 

     for(int i = 1; i != player_choice; i++){
        current_list = current_list->next;
     }
    printf("You Have Selected %d) {Push %d, Jump %d} \n",player_choice, current_list->card_list.push , current_list->card_list.jump);
    for(int p = 0; p < current_list->card_list.push; p++){
        if(p1->prev != NULL){
            p1 = p1->prev;
        }
    }
    for(int j = 0; j < current_list->card_list.jump; j++){
        p2 = p2->prev;
    }
    game_display(set_up, p1, p2);
    printf("\n");

    if(p1->element == 'G'){
        winner = 1;
    }else if(p2->element == 'G'){
        winner = 2;
    }

    if((current_list->card_list.jump > 0) && (p1->next->element == 'G')){
        winner = 1;
    }else if((current_list->card_list.jump > 0) && (p2->prev->element == 'G')){
        winner = 2;
    }
}while(winner != 1 && winner != 2);

if(winner == 1){
    printf("Player 1 WINS\n");
}else if(winner == 2){
    printf("Player 2 WINS\n");
}
}
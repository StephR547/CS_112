#include "string_linked.h"  
#include "char_linked.h"
#include <time.h>

int s_get_count(s_node *head){ 
    int count = 0;   
    s_node *current = head;
    while (current != NULL){ 
        count++; 
        current = current->next; 
    } 
    return count; 
}

void players_hand_setup(c_node **head_ptr, char add_letter){
  c_node *current = *head_ptr;
  int i = 0;
  char string[i];

  int index_add = 0;
  if(current == NULL){
    index_add = 0;
    c_add_to_list_at_index(head_ptr, add_letter, index_add);
  }else{
    c_add_to_list_at_index(head_ptr, add_letter, index_add);
  }
  c_display_list(*head_ptr);
  while(current != NULL){
    i = 0;
    string[i] = current->data;
    i++;
    current = current->next; 
  }
}
void player_choice(c_node **head_ptr, char element_letter){
    int turn = 0;
    c_node *current = *head_ptr; 
    while(turn != 7){
        int rand_num = (rand()%(25-0+1)+0);
        char element_letter = rand_num + 'A';

        current = (*head_ptr);
        while(current != NULL){
                if(element_letter == current->data){
                    current = (*head_ptr);
                    rand_num = (rand()%(25-0+1)+0);
                    element_letter = rand_num + 'A' ;
                }else{
                    current = current->next;
                } 
            }
            c_add_to_start_of_list(head_ptr, element_letter); 
            turn++;
        }
}

int main(){
srand(time(NULL));

s_node *my_dictionary_list = NULL;

c_node *players_hand = NULL;
c_node *choice = NULL;
c_node *current_pick = choice ; 

int players_score = 0;
int player_count = 0;
int value;

char new_letter;
char players_picked_letter;

FILE *input = fopen("dictionary.txt","r");
while(!feof(input)){
    char word[50];
    fscanf(input,"%s", word);
    s_add_to_start_of_list(&my_dictionary_list, word);
}

while(player_count != 6){
    player_count = 0;
    do{
        choice = NULL;
        printf("Pick One Of The Following Letters: ");
        player_choice(&choice, new_letter);
        fflush(stdin);
        c_display_list(choice) ;
        current_pick = choice ; 
        scanf("%c",&players_picked_letter);
        printf("\n");
        
    }while(c_list_contains(choice, players_picked_letter) == 0);    
        printf("Player Has chosen: %c \n", players_picked_letter);
        current_pick = players_hand;
        if(players_hand == NULL){
            c_add_to_start_of_list(&players_hand, players_picked_letter);
            c_display_list(players_hand);
        }else{
            printf("Player's Hand Currently Has: ");
            printf("%d", player_count); 
            printf("\n");
                while(current_pick != NULL) {
                    player_count++;
                    printf(" { %c } %d ", current_pick->data, player_count);
                    current_pick = current_pick->next;
                 }
            printf("\n");
            printf("Please Enter The Index Which You Would Like To Input A New Letter: ");
            scanf("%d",&player_count);
            fflush(stdin);
            printf("\n");
            c_add_to_list_at_index(&players_hand, players_picked_letter, player_count);
            c_display_list(players_hand);
            if((player_count + 1) < 7){
            printf("Player On Turn: %d\n", player_count + 1);
            }

        }
    current_pick = players_hand;    
    int i;
    char string[i];
    for(int i =0; current_pick != NULL; i++){
        string[i]= current_pick->data;
        current_pick = current_pick->next;
    }
    printf("You Currently Have The Word: %s \n",string);
        if(s_list_contains(my_dictionary_list,string) == 1){
            printf("This Is A Word In The Scrabble Dictionary :)!\n");
            players_score ++;
        }else{
            printf("This Is Not A Valid Scrabble Word :(\n");
        }
    printf("Players Current Score Is: %d\n", players_score);
}
printf("Your Final Score: %d\n",players_score);

}

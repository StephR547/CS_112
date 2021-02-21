#include "linked.h"
#include <time.h>

int main(){
    srand(time(NULL)); 
    int user_pick;
    int num_of_players;

    circular *my_players = NULL;
    int num_of_players_killed;
    char name_input[14];

//Player Set Up:
    printf("Please Enter The Number Of Players: ");
    scanf("%d",&num_of_players);
    
    for(int i = 1; i < (num_of_players+1); i++){
        printf("Please Enter The Name Of Player %d: ", i);
        scanf("%s", name_input);
        insert_at_end(&my_players, name_input);
    }
    display(my_players);

    circular *radish = NULL;
    radish = my_players;

//Player Rounds:
   while((num_of_players-num_of_players_killed) != 1){
        int time_count = (rand()%(30 - 1 + 1) + 1); 
         printf("The current player is %s\n", radish->name);
         do{
          //  printf("CURRENT TIMER: %d\n", time_count);

            printf("Please Enter One Of The Following Options:\n");
            printf("1: Pass now (1 second)\n");
            printf("2: Wait 1 seconds then pass (2 seconds)\n");
            printf("3: Wait 2 seconds then pass (3 seconds)\n");
            printf("Enter Your Choice As A Number: ");
            scanf("%d",&user_pick);
            fflush(stdin);

            if(user_pick == 1){ 
                time_count = time_count - 1;
            }else if(user_pick == 2){
                time_count = time_count - 2;
            }else if(user_pick == 3){
                time_count = time_count - 3;
            }else{
                printf("INVALID OPTION\n");
            }
         //   printf("TIMER: %d\n", time_count);

            printf(" %s Is Passing the radish to %s \n", radish->name, radish->next->name);
            radish = radish->next;
            printf("The current player is %s\n", radish->name);

        }while(time_count > 0);
        if(time_count <= 0){
            printf("THE RADISH HAS EXPLODED! %s WAS KILLED\n", radish->name);
            delete_by_name(&my_players, radish->name);
            num_of_players_killed++;
            radish = radish->next;
        }
    }
    printf("%s HAS WON THE GAME!\n", radish->name);

}
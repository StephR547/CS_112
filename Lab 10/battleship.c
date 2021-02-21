#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int size = 10;

void initialize_board(char user_board[size][size], char hidden_board[size][size]){
    for(int row = 0; row < size; row++){
        for(int col =0; col < size; col++){
            user_board[row][col] = '~';
            hidden_board[row][col] = 'x';
        }
    }
}
void display_board(char board[size][size]){
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    int row_number = 0;
    for(int row = 0; row < size; row++){
        printf(" %d", row_number);
        row_number += 1;
        for(int col = 0; col < size; col++){
            printf(" %c", board[row][col]);jv kdx
    }
    printf("\n");
    }
}
int check_placement_vertical(char hidden_board[size][size], int starting_row, int starting_column, int ship_size){
    if(ship_size > (size - starting_column)){
        return 0;
    }
    for(int i = starting_row; i < (starting_row + ship_size); i++){
        if(hidden_board[i][starting_column] != 'x'){
            return 0;
        }
    }
    return 1;
}
int check_placement_horizontal(char hidden_board[size][size], int starting_row, int starting_column, int ship_size){
    if(ship_size > (size - starting_row)){
       return 0;
    }
    for(int i = starting_column; i < (starting_column + ship_size); i++){
        if(hidden_board[i][starting_row] != 'x'){
             return 0;
        }
       
    }
    return 1;
}
void placing_ship_vertical(char hidden_board[size][size], int size, char letter){
    int rows;
    int cols;
    do{
        rows = (rand()%10);
        cols = (rand()%10);
    }while(check_placement_vertical(hidden_board, rows, cols, size) != 1);
    for(int beginning = rows; beginning < (size + rows); beginning++){
        hidden_board[beginning][cols] = letter;
    } 
}
void placing_ship_horizontal(char hidden_board[size][size], int size, char letter){
    int rows;
    int cols;
    do{
        rows = (rand()%10);
        cols = (rand()%10);
    }while(check_placement_horizontal(hidden_board, rows, cols, size) != 1);
    for(int beginning = cols; beginning < (size + cols); beginning++){
        hidden_board[rows][beginning] = letter;
    }
}
void place_ship(char hidden_board[size][size], int size, char letter){
    int rand_placement = (rand()%2);
    if(rand_placement == 0){
        placing_ship_vertical(hidden_board, size, letter);
    }else{
        placing_ship_horizontal(hidden_board, size, letter);
    }
}
void ships_placements(char hidden_board[size][size]){
    place_ship(hidden_board, 5, 'C');
    place_ship(hidden_board, 4, 'B');
    place_ship(hidden_board, 3, 'D');
    place_ship(hidden_board, 3, 'S');
    place_ship(hidden_board, 2, 'P');
}
char guess_valid(char user_board[size][size], int row, int colm){
    if(row < 0 || row > 9){
        printf("Guess Outside Range\n");
        return 0;
    }
    if(colm < 0 || colm > 9){
        printf("Guess Outside Range\n");
        return 0;
    }
    if(user_board[row][colm] != '~'){
        printf("Already Guessed Position\n");
        return 0;
    }
    return 1;
}
char make_guess(char hidden_board[size][size], char user_board[size][size]){
    int row;
    int col;
    do{
        printf("Please Guess a Position:\n");
        printf("ROW position:\n");
        scanf("%d", &row);
        printf("COLUMN position:\n");
        scanf("%d", &col);
    }while(guess_valid(user_board, row, col) != 1);

    user_board[row][col] = hidden_board[row][col];
    return hidden_board[row][col];
}
int main(){
    srand(time(NULL));
    char user_board[size][size];
    char hidden_board[size][size];

    initialize_board(user_board, hidden_board);
    ships_placements(hidden_board);

    int carrie_health = 5;
    int battleship_health = 4;
    int destroyer_health = 3;
    int submarine_health = 3;
    int patrol_boat_health = 2;
    int total_health;

    

    do{
        printf("------User Board------\n");
        display_board(user_board);
        switch (make_guess(hidden_board, user_board)){
            case 'x':
            printf("You Missed\n");
            break;
            case 'C':
            carrie_health--;
            printf("You Landed a Hit on my Carrier\n");
            if(carrie_health == 0){
                printf("You SUNK my Carrier!");
            }
            break;
            case 'B':
            battleship_health--;
            printf("You Landed a Hit on my Battle Ship\n");
            if(battleship_health == 0){
                printf("You SUNK my Battle Ship!\n");
            }
            break;
            case 'D':
            destroyer_health--;
            printf("You Landed a Hit on my Destroyer\n");
            if(destroyer_health == 0){
                printf("You SUNK my Destroyer!\n");
            }
            break;
            case 'S':
            submarine_health--;
            printf("You Landed a Hit on my Submarine\n");
            if(submarine_health == 0){
                printf("You SUNK my Submarine!\n");
            }
            break;
            case 'P':
            patrol_boat_health--;
            printf("You Landed a Hit on my Patrol Boat\n");
            if(patrol_boat_health == 0){
                printf("You SUNK my Patrol Boat!\n");
            }
            break;
            default:
            break;
        }
        total_health = carrie_health + battleship_health + destroyer_health + submarine_health + patrol_boat_health;
    }while(total_health != 0);
    printf("YOU WON!\n");
   
}
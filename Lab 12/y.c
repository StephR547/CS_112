#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stock{
char name [50];
float price;
int owned;
}stock;

void display_stock(stock *my_stock){
printf("%s $%.2f\n", my_stock->name,my_stock->price);
}
void read_input(stock *my_other_stock, char stock_file[50]){
my_other_stock->owned=0;
FILE *stck_file= fopen(stock_file, "r");
fscanf(stck_file, "%s", my_other_stock->name);
fscanf(stck_file, "%f", &my_other_stock->price);
fclose(stck_file);
}
void display_inventory(stock *stack){
float total_value = stack->price * stack->owned;
printf("you own %d of %s at $%.2f worth $%.2f\n", stack->owned, stack->name, stack->price, total_value);
}
void buy_stock(stock *stock_purchased, float *cash){
display_stock(stock_purchased);
int number_entered;

if(*cash< stock_purchased->price){
printf("you too broke for that\n");
}else if(*cash > stock_purchased->price){

float total_amount;
do{
printf("how many shares of %c you want?\n", stock_purchased->name);
scanf("%d", &number_entered);
total_amount= stock_purchased->price * number_entered;
}while(number_entered < 0 || *cash <= total_amount);
printf("you bought %d of %c at $%.2f for $%.2f\n", number_entered, *stock_purchased->name, stock_purchased->price, total_amount);
*cash -= total_amount;
stock_purchased->owned += number_entered;
printf("you have $%.2f remaining\n", *cash);
}
}
void sell_stock(stock *stoock, float *player_cash){
display_inventory(stoock);
printf("$%.2f\n", *player_cash);
int user_answer;
float cash_total;
printf("you have $%.2f\n",*player_cash);
if(stoock->owned == 0){
printf("the amount of stocks you own: %f\n",*player_cash);
}else{
do{
printf("how many shares of %s you want to sell?\n" stoock->name);
scanf("%d", &user_answer);
cash_total= stoock->price * user_answer;
}while(user_answer < 0 || user_answer != stoock->owned);
printf("you sold %d of %d at %.2s for $%.2f\n",user_answer, stoock->owned, stoock->name, cash_total);
}
}

void end_turn(stock *stocked, int turn_count){
for( turn_count =1; turn_count< 10; turn_count++){
printf("turn count %d ENDING\n", turn_count);
printf("stock prices are changing\n");
int num_ran=(rand()% (125-75+1))+1;
float random = num_ran /100;
stocked->price = random * stocked->price;
}
}

int main(){
int turn_count =1;
stock apple;
float cash=100;
read_input(&apple, "stock.txt");
buy_stock(&apple, &cash);
sell_stock(&apple, &cash);
end_turn(&apple, cash);
display_inventory(&apple);
display_stock(&apple);
}

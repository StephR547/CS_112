#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
typedef struct stock{
   char name[10];
   float price;
   int amount;
}stock;
 
void display_stock(stock my_stock){
   printf("%s $%.2f\n",my_stock.name, my_stock.price);
}
 
void read_input(char *file_name, stock *my_stock){
   FILE*my_file = fopen(file_name,"r");
   fscanf(my_file, "%s", my_stock->name);
   fscanf(my_file, "%f", &my_stock->price);
   fclose(my_file);
   my_stock->amount = 0;
}
 
void display_inventory(stock my_stock){
   printf("You own %d stock(s) of %s at $%.2f worth $%.2f.\n", my_stock.amount, my_stock.name, my_stock.price, (my_stock.amount * my_stock.price));
}
 
void buy_stock(stock *my_stock, float *cash_money){
   display_stock(*my_stock);
   printf("CASH MONEY: $%.2f\n", *cash_money);
   float stonk_price = my_stock->price;
   if ((stonk_price) > (*cash_money)){
   	printf("You cannot afford this stock. Go home and reevaluate your life choices.\n");
   	return;
   }
   if ((stonk_price) <= *cash_money){
   	int stonks;
   	do{
       	printf("How much of the stock would you like to purchase?\n");
       	scanf("%d", &stonks);
       	if ((stonk_price * stonks) <= *cash_money){
           	printf("You bought %d of %s at $%.2f for $%.2f.\n", stonks, my_stock->name, my_stock->price, (my_stock->price * stonks));
           	*cash_money = *cash_money - (my_stock->price * stonks);
           	my_stock->amount = my_stock->amount + stonks;
           	printf("You have $%.2f left.\n", *cash_money);
       	}else{
           	printf("No.\n");
       	}
   	}while((stonks > 0) && ((stonks * stonk_price) <= *cash_money));
   }
}
 
void sell_stock(stock *my_stock, float *cash_money){
   display_inventory(*my_stock);
   printf("CASH MONEY: $%.2f.\n", *cash_money);
   int stonk_amount = my_stock->amount;
   if (stonk_amount == 0){
   	printf("You do not own any of this stock.\n");
   	return;
   }
   int stonk;
   do{
   	printf("How much stock would you like to sell?\n");
   	scanf("%d", &stonk);
   	if (stonk <= stonk_amount){
       	printf("You sold %d of %s at $%.2f for $%.2f.\n", stonk, my_stock->name, my_stock->price, (my_stock->price * stonk));
       	*cash_money = *cash_money + (my_stock->price * stonk);
       	my_stock->amount = my_stock->amount - stonk;
       	stonk_amount = my_stock->amount;
       	printf("You have $%.2f left.\n", *cash_money);
   	}else{
       	printf("No.\n");
   	}
   }while ((stonk > 0) && (stonk <= stonk_amount));
}
 
void end_turn(stock *my_stock, int *turn_count){
   printf("The current turn %d is ending...\nStock prices are subject to change.\n",*turn_count);
   int random_num = (rand()%(125-75+1))+75;
   float percent = ((float)random_num/100);
   my_stock->price = my_stock->price * percent;
   *turn_count = *turn_count + 1;
}
 
void high_score(char *score_file, stock *my_stock, float cash_money){
  FILE*my_other_file = fopen("highscore.txt","r");
  char name[4];
  float hi_score;
  fscanf(my_other_file, "%s", name);
  fscanf(my_other_file, "%f", &hi_score);
  printf("HIGH SCORE: %s   %.2f\n", name, hi_score);
  fclose(my_other_file);
  if (cash_money > hi_score){
  	printf("You have the newest high score!\n");
  	printf("Enter your name (3 spaces ONLY): ");
  	scanf("%s", name);
  	FILE*my_other_file = fopen("highscore.txt","w");
  	hi_score = cash_money;
  	fprintf(my_other_file, "%s ", name);
  	fprintf(my_other_file, "%f", hi_score);
  	fclose(my_other_file);
  }
 
   printf("%s	$%.2f\n", name, hi_score);
 
  my_stock->amount = 0;
}
 
int main(){
 
   srand(time(NULL));
 
   int turn_count = 1;
 
   stock my_stock;
 
   read_input("stock_file.txt",&my_stock);
 
   float cash_money = 100.69;
 
   while(turn_count < 11){
   	display_stock(my_stock);
   	display_inventory(my_stock);
   	printf("CASH MONEY: $%.2f\n", cash_money);
 
   	char answer[10];
   	printf("Which would you like to do:\n");
   	printf("BUY 	SELL	NEXT\n");
   	printf("Enter: ");
   	scanf("%s", answer);
   	if ((strcmp(answer,"BUY")==0)){
       	buy_stock(&my_stock, &cash_money);
   	}else if ((strcmp(answer,"SELL")==0)){
       	sell_stock(&my_stock, &cash_money);
   	}else if ((strcmp(answer,"NEXT")==0)){
       	end_turn(&my_stock, &turn_count);
   	}else{
       	printf("INVALID COMMAND\n");
   	}
   }
 
   printf("GAME OVER\n");
   printf("You ended with...\n");
   printf("$%.2f in your pocket ", cash_money);
   printf(" and $%.2f in stonks.\n", (my_stock.price * my_stock.amount));
   high_score("highscore.txt", &my_stock, cash_money);
}


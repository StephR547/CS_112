#include <stdio.h>
int main(){
    int value_x = 10;
    int value_y = 20;
    while(value_x != (value_y+1)){
        if(value_x%2){
            printf("Doop\n");
        }else{
            printf("Boop\n");
        }
        value_x++;
    }
    printf("Value of x is: %d\nValue of y is:%d\n", value_x, value_y);
    }


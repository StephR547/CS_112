#include <stdio.h>

int number(int num){
    while(num != 0){
        printf("%d\n", num);
        num--;
    }
    return num;
}

int main (){
    number(9);
}
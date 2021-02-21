#include <stdio.h>

int rows;
int cols
int array_input(int array[rows][cols]){
    for(int row = 0; row < rows; row++){
        for(int col = cols; col >-1;col--){
            printf("%d ",array[row][col]);
        }
    }
}
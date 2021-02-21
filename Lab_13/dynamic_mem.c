#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(int **ptr_array, int size, int capacity){
    int *pointer = malloc(sizeof(int)*100);
    if(*pointer == 3){
        capacity = 0;
    }else if(*pointer != 3){
        capacity = 3;
        printf("ERROR\n");
    }
}
void display(int *ptr_array, int size, int capacity){
    printf("[");
    float percent = (size/capacity)*100;
    for(int i = 0; i < size; i++){
        printf("%d", size);
    }
    for(int i = size; size < capacity; size++){
        printf("X");
    }
    printf("]\n");
    printf("The Array is %f%% full\n", percent);
}

void add_element(int **ptr_array, int *size, int capacity, int add){
    ptr_array = realloc (ptr_array, sizeof(int)*6);
    (*ptr_array)[*size] = add;
}

int main(){
    int *array;
    int size = 3;
    int capacity = 4;
    int element;
    init(&array, size, capacity);
    display(array, size, capacity);
    add_element(&array, &size, capacity, element);
}
#include <stdlib.h>

#include <string.h>

#include <stdio.h>

typedef struct doubly{    
    char element; 
    struct doubly *next;    
    struct doubly *prev;
}doubly;

    //Struct for int element and int jump
    //Player 1 and 2 must be pointers 

void add_to_empty_list(doubly **head_ptr, char element); 

void display(doubly *head);

void add_to_start(doubly **head_ptr, char element);

void add_at_index(doubly **head_ptr, char element, int index);

void add_to_end(doubly **head_ptr, char element);

void forwards_backwards(doubly *head);

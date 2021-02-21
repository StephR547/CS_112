#include <stdlib.h>

#include <string.h>

#include <stdio.h>

typedef struct card{
    int push;
    int jump;
}card;

typedef struct card_node{
    card card_list;
    struct card_node *next;
}card_node;

void singly_display_with_indices(card_node *head);

void singly_add_to_start(card_node **head_ptr, card element);
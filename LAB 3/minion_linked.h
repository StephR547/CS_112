#include <stdio.h>

#include <stdlib.h>

typedef struct minion {

    int attack;

    int health;

} minion;

typedef struct minion_node {

    minion monster;

    struct minion_node *next;

} minion_node;

void minion_display(minion_node *head);

void minion_display_with_indices(minion_node *head);

// Called by add_at_index

void minion_add_to_start(minion_node **head_ptr, minion element);

void minion_add_at_index(minion_node **head_ptr, minion element, int index);

// Called by copy function

void minion_add_to_end(minion_node **head_ptr, minion element);

// Called by remove from index

void minion_remove_from_start(minion_node **head_ptr);

void minion_remove_from_index(minion_node **head_ptr, int index);

minion_node *minion_list_copy(minion_node *head);

int minion_list_length(minion_node *head);

int minion_list_is_empty(minion_node *head);
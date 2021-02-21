#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct c_node{
    char data;
    struct c_node *next;
}c_node;

int c_list_contains(c_node *head_ptr, char data_to_add);

void c_add_to_start_of_list(c_node **head_ptr, char data_to_add);
void c_add_to_list_at_index(c_node **head_ptr, char data_to_add, int index_to_add_at);

void c_display_list(c_node *head);
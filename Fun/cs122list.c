#include <stdio.h>
#include <stdlib.h>

typedef struct node {  
    int data;  
    struct node *next;
    } node;
void display_list(node *head) {   
if (head == NULL) {        
printf("Empty list\n");    }
}
void add_to_start_of_list(node **head_ptr, int data_to_add){
    node *new_node_ptr = malloc(sizeof(node));
    new_node_ptr->data = data_to_add;
}
int main() {
    node *my_list_head = NULL;
    display_list(my_list_head);
}
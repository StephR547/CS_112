#include "singly.h"

void singly_add_to_start(card_node **head_ptr, card element) {
	card_node *new_node_ptr = malloc(sizeof(card_node));
	new_node_ptr->card_list = element;
	new_node_ptr->next = *head_ptr;
	*head_ptr = new_node_ptr;
}

void singly_display_with_indices(card_node *head){
    int indices = 1;

    if(head == NULL){
        printf("Empty\n");
    }else{
        card_node *current = head;
            while(current != NULL){
             printf("%d) {Push: %d, Jump: %d} \n", indices, current->card_list.push, current->card_list.jump);
             indices++;
             current = current->next;
            }
        }
        printf("\n");
    }
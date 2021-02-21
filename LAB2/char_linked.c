#include "char_linked.h"

int c_list_contains(c_node *head_ptr, char data_to_add){
    //compare
     c_node *current = head_ptr;
    while (current != NULL) {
        if (data_to_add == current->data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void c_add_to_start_of_list(c_node **head_ptr, char data_to_add){
    //add to start
    // create a node pointer and set it to a space for a node
	c_node *new_node_ptr = malloc(sizeof(c_node));
	// put the data we want to insert into the new node
	new_node_ptr->data = data_to_add;
	new_node_ptr->next = *head_ptr;
	*head_ptr = new_node_ptr;
}
void c_add_to_list_at_index(c_node **head_ptr, char data_to_add, int index_to_add_at){
    //add to any point in list
     if (index_to_add_at == 0) {
        c_add_to_start_of_list(head_ptr, data_to_add);
    }
    else {
        int current_index = 0;
        c_node *current_node_ptr = *head_ptr;
        while (current_index < (index_to_add_at - 1)) {
	        if (current_node_ptr != NULL) {
		        current_node_ptr = current_node_ptr->next;
	        } else {
		        printf("Index is invalid, insertion not performed\n");
		        return;  
	        }
	        current_index++;
        }
        c_node *new_node_ptr = malloc(sizeof(c_node));
        new_node_ptr->data = data_to_add;
        new_node_ptr->next = NULL;
        new_node_ptr->next = current_node_ptr->next;
        current_node_ptr->next = new_node_ptr;
    }
}
void c_display_list(c_node *head){
    //display list
     if (head == NULL) {
        printf("Empty list\n");
    } else {
        c_node *current_node_ptr = head;
        while (current_node_ptr != NULL) {
            printf(" { %c } ", current_node_ptr->data);
            current_node_ptr = current_node_ptr->next;
        }
        printf("\n");
    }
}

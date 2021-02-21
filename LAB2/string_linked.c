#include "string_linked.h"

int s_list_contains(s_node *head, char *element){
    s_node *current = head;
    while (current != NULL) {
        if (strcmp(element, current->data) == 0 ) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void s_add_to_start_of_list(s_node **head_ptr, char *data_to_add){
    	// create a node pointer and set it to a space for a node
	s_node *new_node_ptr = malloc(sizeof(s_node));
	// put the data we want to insert into the new node
    new_node_ptr->data = malloc((strlen(data_to_add)+1)*sizeof(char));
    strcpy(new_node_ptr->data, data_to_add);
	new_node_ptr->next = *head_ptr;
	*head_ptr = new_node_ptr;
}

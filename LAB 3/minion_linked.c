#include "minion_linked.h"

void minion_add_to_start(minion_node **head_ptr, minion element) {
	minion_node *new_node_ptr = malloc(sizeof(minion_node));
	new_node_ptr->monster = element;
	new_node_ptr->next = *head_ptr;
	*head_ptr = new_node_ptr;
}

void minion_add_to_end(minion_node **head_ptr, minion element) {
    if (*head_ptr == NULL) {
        minion_add_to_start(head_ptr, element);
    } 
    else { 
        minion_node *current_node_ptr = *head_ptr;
        while(current_node_ptr-> next != NULL) {
        current_node_ptr = current_node_ptr-> next;
        }
        minion_node *new_node_ptr = malloc(sizeof(minion_node));
	    new_node_ptr->monster = element;
        new_node_ptr->next = NULL;
        current_node_ptr->next = new_node_ptr; 
    }
}

void minion_remove_from_start(minion_node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("Nothing to remove\n");
    } else {
    	minion_node *removed_node_ptr = (*head_ptr);
    	*head_ptr = (*head_ptr)->next;
    	free(removed_node_ptr);
    }
}

void minion_remove_from_index(minion_node **head_ptr, int index) {
	if (index == 0) {
		minion_remove_from_start(head_ptr);
	} else {
		   int current_index = 0;
           minion_node *current_node_ptr = *head_ptr;
           while (current_index < index) {
	       if (current_node_ptr != NULL) {
		        current_node_ptr = current_node_ptr->next;
	       } else {
		        printf("Index is invalid, removal not performed\n");
		        return;  
	        }
	        current_index++; 
        }
        minion_node *removed_node_ptr = current_node_ptr->next;
        current_node_ptr->next = removed_node_ptr->next;
        free(removed_node_ptr);
	}
}

void minion_add_at_index(minion_node **head_ptr, minion element, int index) {

    if (index == 0) {
        minion_add_to_start(head_ptr, element);
    }
    else {
        int current_index = 0;
        minion_node *current_node_ptr = *head_ptr;
        while (current_index < (index - 1)) {
	        if (current_node_ptr != NULL) {
		        current_node_ptr = current_node_ptr->next;
	        } else {
		        printf("Index is invalid, insertion not performed\n");
		        return;  
	        }
	        current_index++;
        }
        minion_node *new_node_ptr = malloc(sizeof(minion_node));
        new_node_ptr->monster = element;
        new_node_ptr->next = NULL;
        new_node_ptr->next = current_node_ptr->next;
        current_node_ptr->next = new_node_ptr;
    }
}

void minion_display(minion_node *head) {
    if (head == NULL) {
        printf("Empty list\n");
    } else {
        minion_node *current_node_ptr = head;
        while (current_node_ptr != NULL) {
            printf(" { %d } { %d } -> ", current_node_ptr->monster.health, current_node_ptr->monster.attack);
            current_node_ptr = current_node_ptr->next;
        }
        printf("\n");
    }
}

void minion_display_with_indices(minion_node *head){
    int indices = 0;

    if(head == NULL){
        printf("Empty\n");
    }else{
        minion_node *current = head;
            while(current != NULL){
             printf("%d {Health: %d, Attack: %d} \n", indices, current->monster.health, current->monster.attack);
             indices++;
             current = current->next;
            }
        }
        printf("\n");
    }

minion_node *minion_list_copy(minion_node *head){
    minion_node *current_og = head;
    minion_node *list_copy = NULL;

    while(current_og != NULL){
        minion_add_to_end(&list_copy, current_og->monster);
        current_og = current_og->next;
    }
    return list_copy;
}
int minion_list_is_empty(minion_node *head){
    minion_node *headptr = head;

    if(headptr == NULL){
        printf("Empty List\n");
    }
    return 0;

}

int minion_list_length(minion_node *head){
    int count = 0;   
    minion_node *current = head;

    if(current == NULL){
        return count;
    }else {
        while (current != NULL){ 
        count++; 
        current = current->next; 
        } 
    return count; 
    } 
}
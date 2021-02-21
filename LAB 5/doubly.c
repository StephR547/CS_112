#include "doubly.h"

void add_to_empty_list(doubly **head_ptr, char element){
    doubly *new_node = malloc(sizeof(doubly));    
    new_node->element = element;    
    new_node->next = NULL;    
    new_node->prev = NULL;    
    *head_ptr = new_node;
}

void display(doubly *head){
    doubly *current = head;    
    printf("NULL");    
    while (current != NULL){       
         printf(" <- { %d } -> ", current->element);        
         current = current->next; 
    }    
    printf("NULL\n");
}

void add_to_start(doubly **head_ptr, char element){
    if (*head_ptr == NULL){
        add_to_empty_list(head_ptr, element);
}else {    
    doubly *new_node = malloc(sizeof(doubly));    
    new_node->element = element;    
    new_node->prev = NULL;    
    new_node->next = *head_ptr;    
    (*head_ptr)->prev = new_node;    
    *head_ptr = new_node;    
    }
}

void add_at_index(doubly **head_ptr, char element, int index){
    if (index == 0){        
        add_to_start(head_ptr, element);   
    }else{
        doubly *current = *head_ptr;       
        int current_index = 0;
        while (current_index < (index - 1)){    
            if (current != NULL){       
                current = current->next;    
            }else{        
                printf("Index is invalid, insertion not performed\n");        
                return;    
                }    
                current_index++;
            }
            doubly *new_node = malloc(sizeof(doubly));
            new_node->element = element;        
            new_node->prev = current;        
            new_node->next = current->next;        
            current->next = new_node;        
            if (new_node->next != NULL) {            
                new_node->next->prev = new_node;        
         }    
    }      
}

void add_to_end(doubly **head_ptr, char element){
    if (*head_ptr == NULL){        
        add_to_start(head_ptr, element);    
    }else{        
        doubly *current = *head_ptr;        
        while (current->next != NULL){        
            current = current->next;    
            }    
        doubly *new_node = malloc(sizeof(doubly));    
        new_node->element = element;    
        current->next = new_node;    
        new_node->prev = current;    
        new_node->next = NULL;    
        }
}
void forwards_backwards(doubly *head){
    doubly *current = head;    
    printf("Starting at the front\n");    
    while (current->next != NULL) {        
        printf("%d\n", current->element);        
        current = current->next;    
        }    
    printf("Reached the end %d, turning around\n", current->element);    
    while (current->prev != NULL){        
        printf("%d\n", current->element);        
        current = current->prev;   
        }    
    printf("Reached the front %d!\n", current->element);
}

/* 
#include "int_linked.h"

void insert_sorted(i_node **head_ptr, int element){
    if(*head_ptr == NULL){
        i_add_to_start_of_list(head_ptr, element);
    }else{
        i_node *current = *head_ptr;
        while(current->next != NULL && element > current->next->data){
            current = current->next;
        }
        printf("Need to insert after %d\n", current->data);
        i_node *new_node = malloc(sizeof(i_node));
        new_node->data = element;
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    i_node *my_list = NULL;
    while(1){
        int number; 
        printf("Please enter a number:");
        scanf("%d", &number);
        insert_sorted(&my_list, number);
        i_display_list(my_list);
    }
}
*/
#include "int_linked.h"
#include "time.h"

void insert_sorted(i_node **head_ptr, int element){
    if(*head_ptr == NULL){
        i_add_to_start_of_list(head_ptr, element);
    }else{
        i_node *current = *head_ptr;
        while(current->next != NULL && element > current->next->data){
            current = current->next;
        }
        i_node *new_node = malloc(sizeof(i_node));
        new_node->data = element;
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    srand(time(NULL));
    i_node *my_list = NULL;
    for(int i = 0; i < 100000; i++){
        int number = rand()%100;
        insert_sorted(&my_list, number);
        if(i % 1000 == 0){
            printf("DONE: %d",number);
        }
    }
    
}
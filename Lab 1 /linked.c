#include "linked.h"
 
void add_to_start(node **head_ptr, int element){
   node *node_ptr = malloc(sizeof(node));
   node_ptr->data = element;
   node_ptr->next = *head_ptr;
   *head_ptr = node_ptr;
}
void display(node *head){
   node *current = head;
   while(current != NULL){
       printf("{ %d } ->", current->data);
       current = current->next;
   }
   printf("NULL\n");
}

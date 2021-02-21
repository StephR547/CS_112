#include "linked.h"
 
int compare(node **head, node **second_head){
   node *current = *head;
   node *sorted_list = *second_head;
   node *sorted_head_num = *second_head;

   int biggest_num;
   
   while(current != NULL){
       if(biggest_num < current->data){
           if(sorted_head_num == NULL){
               biggest_num = current->data;
           }else if(current->data < sorted_head_num->data){
               biggest_num = current->data;
           }
       }else{
               printf("Nothing In List\n");
           }
       current = current->next;
   }
   return biggest_num;
}   

int main(){
   node *my_list = NULL;
   node *my_sorted_list = NULL;
   FILE *input = fopen("input.txt", "r");
   while(! feof(input)){
       int num;
       fscanf(input, "%d", &num);
       add_to_start(&my_list, num);
   }
   node *current = my_list;
    while(current != NULL){
        int big_num = compare(&my_list, &my_sorted_list);
        add_to_start(&my_sorted_list, big_num);
        current = current->next;
   }

   printf("My Orginal List:");
   display(my_list);
 
   printf("My New List:");
   display(my_sorted_list);
}

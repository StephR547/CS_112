#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
   int data;
   struct node *next;
}node;
 
void add_to_start(node **head_ptr, int element);
void display(node *head);
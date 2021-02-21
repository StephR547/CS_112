#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node{
    char *data;
    struct s_node *next;
}s_node;

int s_list_contains(s_node *head, char *element);

void s_add_to_start_of_list(s_node **head_ptr, char *data_to_add);
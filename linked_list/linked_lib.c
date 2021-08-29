#include <stdlib.h>
#include "linked_lib.h"

int list_add(struct linked *list, int val, int index){
    
    // Getting to the previous node 
    int i = 1;
    for (i; i < index - 1 || list->link != NULL; i++){
         list = list->link;
    }
    if (list->link == NULL && i != index - 1)
        return ERROR;
        
    // Backuping the next node's link
    struct linked *next_list_link = list->link == NULL ? NULL : (list->link)->link;
    
    // Creating a new node
    struct linked *new_list = malloc(sizeof(struct linked));
    new_list->value = val;
    new_list->link = next_list_link; 

    // Overwriting the next node
    list->link = new_list;
    return i;
    
} 

int list_remove(struct linked **list_pointer, int index){
    struct linked *list = *list_pointer;
    // Getting to the previous node 
    int i = 1;
    for (i; i < index - 1 && list->link != NULL ; i++){
         list = list->link;
    }
    if (list->link == NULL)
        return ERROR;
    else if (index != 1 && i != index - 1)
        return ERROR;

    
    // Backing up the next node's link
    struct linked *next_list_link;
    if (list->link == NULL)
        next_list_link = NULL;
    else if (index == 1)
        next_list_link = list->link;
    else
        next_list_link = (list->link)->link;
    
    // Clearing the memory
//    if (index != 1)
    free(index == 1 ? list : list->link);
    
    // Overwriting the next node
    if (index == 1)
        *list_pointer = next_list_link;
    else
        list->link = next_list_link;
    return i;
}

int list_contains(struct linked *list, int val){
    // Iteration throught the to the nodes 
    int i = 1;
    for (i; list->value != val && list->link != NULL; i++){
         list = list->link;
    }
    if (list->link == NULL && list->value != val)
        return ERROR;
    else
        return i;
}

#include <stdio.h>
#include <stdlib.h>
#include "linked_lib.h"


int main () {
    // Creating a new node
    struct linked *list = malloc(sizeof(struct linked));
    list->value = 1;
    list->link = NULL;
    printf("initial list single value %i\n", list->value);
    printf("adding 2, 2-nd position %i\n", list_add(list, 2, 2));
    printf("adding 3, 3-rd position %i\n", list_add(list, 3, 3));
    printf("addin 4, 4-th position %i\n", list_add(list, 4, 4));
    
    struct linked *list_copy = list;
    printf("list values:");
    while (list_copy->link != NULL){
        printf("%i ", list_copy->value);
        list_copy = list_copy->link;
    }
    printf("\n");

    int val = 4;
    printf("list contains %i %s\n", val, list_contains(list, val)  != ERROR ? "true" : "false");
    printf("list remove %i %s\n", val, list_remove(&list, val) != ERROR ? "true" : "false");
    printf("list contains %i %s\n", val, list_contains(list, val) != ERROR ? "true" : "false");
    printf("list values:");
    while (list->link != NULL){
        printf("%i ", list->value);
        list = list->link;
    }
    printf("\n");


}


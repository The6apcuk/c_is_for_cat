#ifndef LINKED_LIB_H
#define LINKED_LIB_H
#define ERROR -1

struct linked {int value;  struct linked *link; };

int list_contains(struct linked *list, int val);

int list_remove(struct linked **list, int index);

int list_add(struct linked *list, int val, int index);
#endif

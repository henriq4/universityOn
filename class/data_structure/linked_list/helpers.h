#include <stdio.h>
#include <stdlib.h>

struct List* create_list();
struct List* insert_list(struct List* list, int value);
void print_list(struct List* list);
int empty_list(struct List* list);
struct List* search(struct List* list, int v);
struct List* remove_item(struct List* list, int val);
void liberate_list(struct List* list);
struct List* ordenate_insert(struct List* list, int val);
int equality_lists(struct List* list1, struct List* list2);

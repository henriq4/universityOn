#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

List* create_list();
List* insert_list(List* list, int value);
void print_list(List* list);
int empty_list(List* list);
List* search(List* list, int v);
List* remove_item(List* list, int val);
void liberate_list(List* list);
List* ordenate_insert(List* list, int val);
int equality_lists(List* list1, List* list2);

#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

// Definindo a estrutura de um nó da lista
struct List {
  int value; // valor
  struct List* next; // referência para próximo nó
};

List* create_list();
List* insert_in_list(List* list, int value);
void print_list(List* list);
int is_list_empty(List* list);
List* search_item_in_list(List* list, int v);
List* remove_item_in_list(List* list, int val);
void free_list(List* list);
List* ordeneted_insert_in_list(List* list, int val);
int is_lists_equals(List* list1, List* list2);

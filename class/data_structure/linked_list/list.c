#include "helpers.h"
#include <string.h>

// Criar uma lista vazia
List *create_list() { return NULL; }

// Insere um valor dentro da lista
List *insert_in_list(List *list, int value) {
  List *new_item = (List *)malloc(sizeof(List));

  new_item->value = value;
  new_item->next = list;

  return new_item;
}

// Printa os valores de cada elemento dentro da lista
void print_list(List *list) {
  List *l;

  for (l = list; l != NULL; l = l->next) {
    printf("Value: %d\n", l->value);
  }
}

// Verificar se uma lista está vazia
int is_list_empty(List *list) {
  if (list == NULL) {
    return 1;
  }

  return 0;
}

// Procurar por um elemento na lista pelo seu valor
List *search_item_in_list(List *list, int value) {
  List *l;

  for (l = list; l != NULL; l = l->next) {
    if (l->value == value) {
      return l;
    }
  }

  return NULL;
}

// remove item from the list
List *remove_item_in_list(List *list, int value) {
  List *previous = create_list();
  List *l = list;

  while (l != NULL && l->value != value) {
    previous = l;
    l = l->next;
  }

  if (l == NULL) {
    return list;
  }

  if (previous == NULL) {
    list = l->next;
  } else {
    previous->next = l->next;
  }

  free(l);
  return list;
}

// Libera item por item da lista
void free_list(List *list) {
  List *keeper;
  List *l = list;

  while (l != NULL) {
    keeper = l->next;
    free(l);
    l = keeper;
  }
}

// Insere elemento de forma ordenada
List *ordeneted_insert_in_list(List *list, int value) {
  List *new_item;

  List *previous = create_list();
  List *l = list;

  while (l != NULL && l->value < value) {
    previous = l;
    l = l->next;
  }

  new_item = (List *)malloc(sizeof(List));
  new_item->value = value;

  if (previous == NULL) {
    new_item->next = list;
    list = new_item;
  } else {
    new_item->next = previous->next;
    previous->next = new_item;
  }

  return list;
}

// Verifica se duas listas têm seus valores iguais
int is_lists_equals(List *list1, List *list2) {
  List *l1;
  List *l2;

  for (l1 = list1, l2 = list2; l1 != NULL && l2 != NULL;
       l1 = l1->next, l2 = l2->next) {
    if (l1->value == l2->value) {
      return 1;
    }
  }

  return 0;
}

#include "helpers.h"

int main() {
  List *list = create_list();

  printf("-------------------------------\n");

  list = insert_in_list(list, 42);
  list = insert_in_list(list, 59);
  list = insert_in_list(list, 23);
  list = insert_in_list(list, 22);
  print_list(list);

  printf("-------------------------------\n");

  printf("A lista está vazia: %d\n", is_list_empty(list));

  printf("-------------------------------\n");

  int n;
  printf("Digite um valor para procurar na lista: ");
  scanf("%d", &n);

  List *val = search_item_in_list(list, n);

  if (val == NULL) {
    printf("Valor %d não está presente na lista\n", n);
  } else {
    printf("Item encontrado na lista\n");
  }

  printf("-------------------------------\n");

  remove_item_in_list(list, 23);
  print_list(list);

  printf("-------------------------------\n");

  list = ordeneted_insert_in_list(list, 40);
  print_list(list);

  printf("-------------------------------\n");

  free(list);
  if (list == NULL) {
    printf("Lista liberada com sucesso!\n");
  } else {
    printf("Ops, houve algum problema em liberar a lista\n");
    exit(1);
  }
}

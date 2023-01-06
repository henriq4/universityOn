#include <stdio.h>

int main(void) {
  int handle_km, gas;
  char category;

  printf("Digite o Km rodado: ");
  scanf("%d", &handle_km);

  printf("Digite a categoria: ");
  scanf(" %c", &category);

  switch (category) {
  case 'a':
    category = 15;
    break;

  case 'b':
    category = 12;
    break;

  case 'c':
    category = 10;
    break;

  default:
    category = 0;
  }

  gas = handle_km / category;

  if (category == 0) {
    printf("Categoria inexistente");
  } else if (category == 15 || category == 12 || category == 10) {
    printf("Seu consumo de litros foi: %dL \n", gas);
  } else {
    printf("Ops.. deu algo errado!");
  }
}
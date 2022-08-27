#include <stdio.h>

int num_toys_permitted_func(int height, int age) {
  int counter = 0;

  // Barca Viking
  if (height >= 150 && age >= 12) {
    counter++;
  }

  // Elevator of Death
  if (height >= 140 && age >= 14) {
    counter++;
  }

  // Final Killer
  if (height >= 170 || age >= 16) {
    counter++;
  }

  return counter;
}

int main() {
  int height, age;

  printf("Qual a altura?\n");
  printf("Digite aqui: ");
  scanf("%d", &height);

  printf("Qual a idade?\n");
  printf("Digite aqui: ");
  scanf("%d", &age);

  int num_toys_permitted = num_toys_permitted_func(height, age);

  printf("A pessoa pode andar em %d brinquedos\n", num_toys_permitted);
}

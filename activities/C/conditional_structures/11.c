#include <stdio.h>

int main(void) {
  int height, age;

  int count = 0;

  printf("Digite sua altura (em cm): ");
  scanf("%d", &height);

  printf("Digite sua idade: ");
  scanf("%d", &age);

  if (height > 150 && age > 12) {
    count++;
  }

  if (height > 140 && age > 14) {
    count++;
  }

  if (height > 170 && age > 16) {
    count++;
  }

  if (count >= 1) {
    printf("Você pode andar em %d brinquedos\n", count);
  } else {
    printf("Vocce n pode andar em nenhum brinquedo");
  }
}
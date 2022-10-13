#include <stdio.h>

int main(void) {
  int age = 0;
  int less_18_count = 0;
  int high_30_count = 0;

  do {
    printf("Digite a idade (0 - cancelar): ");
    scanf("%d", &age);

    if (age == 0) {
      break;
    }

    if (age > 0 && age < 18) {
      less_18_count++;
    } else if (age > 30 && age <= 150) {
      high_30_count++;
    }

  } while (age != 0);

  printf("Menores que 18: %d\n", less_18_count);
  printf("Maiores que 30: %d\n", high_30_count);
}

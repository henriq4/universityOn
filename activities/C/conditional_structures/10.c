#include <stdio.h>

// Desafio: tente utilizar apenas 4 comandos if.

int main() {
  const int total_count = 3;

  int swap_var;
  int array_nums[total_count];

  printf("Digite o primeiro número: ");
  scanf("%d", &array_nums[0]);

  printf("Digite o segundo número: ");
  scanf("%d", &array_nums[1]);

  printf("Digite o terceiro número: ");
  scanf("%d", &array_nums[2]);

  for (int i = 0; i < total_count - 1; i++) {
    for (int j = 0; j < total_count - i - 1; j++) {
      if (array_nums[j] < array_nums[j + 1]) {
        swap_var = array_nums[j];
        array_nums[j] = array_nums[j + 1];
        array_nums[j + 1] = swap_var;
      }
    }
  }

  for (int k = 0; k < total_count; k++) {
    printf("%d", array_nums[k]);

    if ((total_count - (k + 1)) != 0) {
      printf(" > ");
    } else {
      printf("\n");
    }
  }
}

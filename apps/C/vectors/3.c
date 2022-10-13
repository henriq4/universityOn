#include <stdio.h>

int main() {
  int nums = 0;
  int vec[nums];
  int swap_var = 0;

  printf("Digite quantos números deseja inserir: ");
  scanf("%d", &nums);

  for (int i = 0; i < nums; i++) {
    printf("Número %d: ", i + 1);
    scanf("%d", &vec[i]);
  }

  for (int i = 0; i < nums - 1; i++) {
    for (int j = 0; j < nums - i - 1; j++) {
      if (vec[j] < vec[j + 1]) {
        swap_var = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = swap_var;
      }
    }
  }

  printf("Vetor ordenado:\n");
  for (int k = 0; k < nums; k++) {
    printf("\t%d\n", vec[k]);
  }
}
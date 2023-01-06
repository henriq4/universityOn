#include <stdio.h>

int main() {
  int vec[20];
  int present_nums[20];
  int last_num = 0;
  int count = 0;
  int k = 0;

  for (int i = 0; i < 21; i++) {
    printf("Número %d", i);
    scanf("%d", &vec[i]);
  }

  for (int j = 20; j >= 0; j--) {
    if (j == 20) {
      last_num = vec[j];

      continue;
    }

    if (last_num == vec[j]) {
      count++;

      present_nums[k] = j;
    }

    k++;
  }

  printf("Esteve presente: %d vezes, nas posições:\n", count);

  for (int l = 0; l < count; l++) {
    printf("\tNa posição %d", l);
    scanf("%d", &vec[l]);
  }
}
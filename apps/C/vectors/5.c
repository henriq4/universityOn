#include <stdio.h>

int main() {
  float vec[49]; // 50 posições

  for (int i = 0; i < 50; i++) {
    printf("Digite o salário %d: ", i);
    scanf("%f", &vec[i]);

    if (vec[i] > 1904 && vec[i] <= 2827) {
      vec[i] = (vec[i] * 0.075) + vec[i];
    }

    else if (vec[i] > 2827 && vec[i] <= 3751) {
      vec[i] = (vec[i] * 0.15) + vec[i];
    }

    else if (vec[i] > 3751 && vec[i] <= 4665) {
      vec[i] = (vec[i] * 0.225) + vec[i];
    }

    else if (vec[i] > 4665) {
      vec[i] = (vec[i] * 0.275) + vec[i];
    }
  }

  printf("Salário final dos funcionários\n");

  for (int j = 0; j < 50; j++) {
    printf("%d: ", j);
    scanf("%f", &vec[j]);
  }
}
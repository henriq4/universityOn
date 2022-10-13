#include <stdio.h>

#define PROD 30

void main() {
  float v[PROD];

  for (int i = 0; i < PROD; i++) {
    printf("Digite o valor do %dº produto: ", i + 1);
    scanf("%f", &v[i]);

    v[i] += v[i] * 0.08;
  }

  printf("Valor dos produtos:\n");

  for (int i = 0; i < PROD; i++) {
    printf("\t%.2f\n", v[i]);
  }
}

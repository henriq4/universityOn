#include <stdio.h>
#include <stdlib.h>

int sum_vet(int *vetX, int *vetY, int n) {
  int i, *sum;

  sum = (int *)malloc(n * sizeof(int *));

  if (sum == NULL) {
    printf("Erro de alocação\n");
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    sum[i] = vetX[i] + vetY[i];
  }

  return sum;
}

int main() {
  int vetX[4] = {1, 2, 3, 4};
  int vetY[4] = {1, 2, 3, 4};

  int *sum;

  sum = sum_vet(vetX, vetY, 4);

  for (int i = 0; i < 4; i++) {
    printf("%d\n", *(sum + i));
  }

  free(sum);
}

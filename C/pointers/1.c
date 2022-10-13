#include <stdio.h>

#define LEN 10

int negativos(int *vet, int len);

int main() {
  // Write C code here
  int vet[LEN] = {-4, -2, -5, 0, -10, 2, 9, 12};

  int *point = vet;

  // printf("%d", point);

  int num_negativos = negativos(point, LEN);

  printf("Total de números negativos no array: %d\n", num_negativos);

  return 0;
}

int negativos(int *vet, int len) {
  int negativos_count = 0;

  for (int i = 0; i < len; i++) {
    if (*(vet + i) < 0) {
      negativos_count++;
    }
  }

  return negativos_count;
}
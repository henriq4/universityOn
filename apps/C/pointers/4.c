#include <stdio.h>

#define LEN 5

int find(int *vet, int len, int *less, int *bigger);

void main() {
  int vet[LEN] = {4213, 232, 3412321, 432, 5543};
  int *point_vet = &vet;
  int less, bigger;

  find(point_vet, LEN, &less, &bigger);

  printf("Menor número: %d\n", less);
  printf("Maior número: %d\n", bigger);
}

int find(int *vet, int len, int *less, int *bigger) {
  for (int i = 0; i < len; i++) {
    if (i == 0) {
      *less = *(vet + i);
      *bigger = *(vet + i);
    }

    if (*(vet + i) > less) {
      *less = *(vet + i);
    }

    if (*(vet + i) < bigger) {
      *bigger = *(vet + i);
    }
  }

  return 0;
}

#include <stdio.h>

#define LEN 10

int get_bigger(int *vet, int length, int *pos);

int main() {
  int vet[LEN] = {0, 10, 412, 1, 529, -329, 5321, -31230, 23};
  int *point_vet = &vet;
  int pos = 0;

  int bigger = get_bigger(point_vet, LEN, &pos);

  printf("Maior número: %d\n", bigger);
  printf("Posição no array: %d\n", pos);

  return 0;
}

int get_bigger(int *vet, int len, int *pos) {
  int bigger = 0;

  for (int i = 0; i < len; i++) {
    if (*(vet + i) > bigger) {
      bigger = *(vet + i);

      *pos = i;
    }
  }

  return bigger;
}

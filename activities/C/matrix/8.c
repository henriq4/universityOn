#include <stdio.h>

#define LIN 5
#define COL 3

int main() {
  int mat[LIN][COL];
  int sum_swap = 0;
  int vet[LIN];

  for (int i = 0; i < LIN; i++) {
    for (int j = 0; j < COL; j++) {
      printf("Digite o elemento da matriz na posição [%d][%d]: ", i, j);
      scanf("%d", mat[i][j]);

      sum_swap += mat[i][j];
    }

    vet[i] = sum_swap;
    sum_swap = 0;
  }

  for (i = 0; i < LIN; i++) {
    printf("Soma da linha %d: %d\n", i, vet[i]);
  }
}

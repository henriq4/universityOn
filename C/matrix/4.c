#include <stdio.h>

#define ORD 5;

void main() {
  int mat[ORD][ORD];
  int sum = 0;

  for (int i = 0; i < ORD; i++) {
    for (int j = 0; j < ORD; j++) {
      printf("Digite o valor da matriz na posição [%d][%d]: ", i, j);
      scanf("%d", &mat[i][j]);

      if (i == j) {
        sum += mat[i][j];
      }
    }
  }

  int avarage = sum / ORD;

  puts("Média dos elementos na diagonal principal: %d", avarage);
}

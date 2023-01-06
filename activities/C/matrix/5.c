#include <stdio.h>

void main() {
  int ord = 0;

  printf("Digite um valor para a matriz quadrada: ");
  scanf("%d", &ord);

  int mat[ord][ord];
  int sum = 0;

  for (int i = 0; i < ord; i++) {
    for (int j = 0; j < ord; j++) {
      printf("Digite o valor da matriz na posição [%d][%d]", i, j);
      scanf("%d", mat[i][j]);

      if (j > i) {
        sum = mat[i][j];
      }
    }
  }

  printf("Soma dos números acima da diagonal principal: %d", sum);
}

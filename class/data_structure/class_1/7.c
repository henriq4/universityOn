#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Número de linhas e colunas da matriz quadrada: ");
  scanf("%d", &n);

  int col = n;
  int row = n;

  int **m;

  m = (int **)calloc(row, sizeof(int *));
  for (int i = 0; i < row; i++) {
    m[i] = calloc(col, sizeof(int));
  }

  if (m == NULL) {
    printf("Memória não alocada! encerrando...\n");
    exit(1);
  }

  int minor_d;
  int big_d;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("Distância [%d][%d]: ", i + 1, j + 1);
      scanf("%d", &m[i][j]);

      printf(" \n");

      if (i == 0 && j == 0) {
        minor_d = m[i][j];
        big_d = m[i][j];
      }

      if (m[i][j] < minor_d) {
        minor_d = m[i][j];
      }

      if (m[i][j] > big_d) {
        big_d = m[i][j];
      }
    }
  }

  printf("******************************\n\n");

  printf("Maior distância: %d\n", big_d);
  printf("Menor distância: %d\n", minor_d);

  for (int i = 0; i < row; i++) {
    free(m[i]);
  }
  free(m);

  return 0;
}

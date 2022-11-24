#include <stdio.h>
#include <stdlib.h>

int search_num(int num, int **arr, int row, int col);

int main() {
  int n = 10;

  int r, c;

  printf("Digite o numero de linhas: ");
  scanf("%d", &r);

  printf("Digite o numero de colunas: ");
  scanf("%d", &c);

  int **mat = (int **)malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++) {
    mat[i] = (int *)malloc(c * sizeof(int));
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("Digite um número: ");
      scanf("%d", &mat[i][j]);
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (search_num(n, mat, i, j) == 1) {
        printf("Match!!\n");

        return 0;
      }
    }
  }

  printf("Ops..não deu match\n");

  free(mat);

  return 0;
}

int search_num(int num, int **arr, int row, int col) {
  if (arr[row][col] == num) {
    return 1;
  }

  return 0;
}

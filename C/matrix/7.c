#include <stdio.h>

int main() {
  int col, lin;
  int element = 0;

  printf("Digite o número de colunas da matriz: ");
  scanf("%d", &col);

  printf("Digite o número de linhas da matriz: ");
  scanf("%d", &lin);

  int mat[lin][col];

  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      printf("Digite o elemento da matriz na posição [%d][%d]: ", i, j);
      scanf("%d", mat[i][j]);
    }
  }

  printf("Digite o número que deseja buscar: ");
  scanf("%d", &element);

  for (i = 0; i < lin; i++) {
    for (j = 0; j < col; j++) {
      if (element == mat[i][j]) {
        printf("Elemento encontrado na posição [%d][%d]\n", i, j);
      }
    }
  }
}

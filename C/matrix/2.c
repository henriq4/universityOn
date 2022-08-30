#include <stdio.h>

#define LIN 4
#define COL 5

int biggest_num(int mat[LIN][COL]);

void main() {
  int matrix[LIN][COL];

  for (int i = 0; i < LIN; i++) {
    for (int j = 0; j < COL; j++) {
      printf("Digite o valor na posição [%d][%d]", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("O maior número é: %d", biggest_num(matrix));
}

int biggest_num(int mat[LIN][COL]) {
  int biggest = mat[0][0];

  for (int i = 0; i < LIN; i++) {
    for (int j = 0; j < COL; j++) {
      if (mat[i][j] > biggest) {
        biggest = mat[i][j];
      }
    }
  }

  return biggest;
}

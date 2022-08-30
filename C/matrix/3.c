#include <stdio.h>

#define LIN 5
#define COL 3

void main() {
  int position = 0;
  int count = 0;

  int matrix[LIN][COL];
  int arr[15];

  for (int i = 0; i < LIN; i++) {
    for (int j = 0; j < COL; j++) {
      printf("Digite o valor na posição [%d][%d]", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);

      if (matrix[i][j] % 7 == 0) {
        arr[position] = matrix[i][j];
        count++;
      }

      position++;
    }
  }

  for (int k = 0; k < count; k++) {
    printf("São múltiplos de 7: %d\n", arr[k]);
  }
}

#include <stdio.h>
#include <stdlib.h>

int main() {
  int r, c;

  printf("Digite o número de linhas: ");
  scanf("%d", &r);

  printf("Digite o número de colunas: ");
  scanf("%d", &c);

  int i, j, count;

  int *arr[r];
  for (i = 0; i < r; i++) {
    arr[i] = (int *)malloc(c * sizeof(int));
  }

  // Note that arr[i][j] is same as *(*(arr+i)+j)
  count = 0;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count
    }
  }

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (arr == NULL) {
        continue;
      }

      printf("%d ", arr[i][j]);
    }
  }

  /* Code for further processing and free the
    dynamically allocated memory */

  for (int i = 0; i < r; i++) {
    free(arr[i]);
  }

  return 0;
}

#include <stdio.h>

int main() {
  int m = 0, n = 0;
  int sum_par = 0, sum_odd = 0;

  do {
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &m);
  } while (m < 2 || m > 15);

  do {
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &n);
  } while (n < 3 || n > 20);

  int matrix[m][n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("Digite o valor para a posição [%d][%d]: ", i + 1, j + 1);
      scanf("%d", &matrix[m][n]);

      if (matrix[m][n] % 2 == 0) {
        sum_par += matrix[m][n];
      } else {
        sum_odd += matrix[m][n];
      }
    }
  }

  printf("A soma dos valores pares é: %d\n", sum_par);
  printf("A soma dos valores ímpares é: %d\n", sum_odd);
}

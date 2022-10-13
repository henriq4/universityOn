#include <stdio.h>

#define LEN 4

void main() {
  int m[LEN][LEN];

  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      printf("Digite o valor da linha %d e coluna %d: ", i + 1, j + 1);
      scanf("%d", &m[i][j]);
    }
  }

  int c = 0;
  int x;

  printf("Digite o valor que deseja procurar: ");
  scanf("%d", &x);

  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      if (m[i][j] == x) {
        c++;
      }
    }
  }

  printf("O valor foi encontrado %d vezes\n", c);
}

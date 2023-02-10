#include <stdio.h>

int r_pair(int n) {
  if (n < 0) {
    return 0;
  }

  if ((n % 2) == 0) {
    printf("%d\n", n);
  }

  return r_pair(n - 1);
}

void main() {
  int num;

  printf("Digite o número: ");
  scanf("%d", &num);

  r_pair(num);
}

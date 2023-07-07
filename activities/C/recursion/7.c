#include <stdio.h>

int r_pair(int n, int sum) {
  if (n < 0) {
    printf("Soma: %d\n", sum);

    return 0;
  }

  if ((n % 2) == 0) {
    sum += n;
  }

  return r_pair(n - 1, sum);
}

void main() {
  int num;

  printf("Digite o número: ");
  scanf("%d", &num);

  r_pair(num, 0);
}

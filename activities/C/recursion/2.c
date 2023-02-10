#include <stdio.h>

int r_pair(int n, int saver) {
  if (n > saver) {
    return 0;
  }

  if ((n % 2) == 0) {
    printf("%d\n", n);
  }

  return r_pair(n + 1, saver);
}

void main() {
  int num;

  printf("Digite o número: ");
  scanf("%d", &num);

  r_pair(0, num);
}

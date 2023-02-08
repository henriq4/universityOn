#include <stdio.h>

int mult(int a, int b, int saver, int m) {
  if (b == 0) {
    printf("%d . %d = %d\n", a, saver, m);

    return 0;
  }

  m += a;

  mult(a, b - 1, saver, m);
}

void main() {
  int a, b;

  printf("a: ");
  scanf("%d", &a);

  printf("b: ");
  scanf("%d", &b);

  mult(a, b, b, 0);
}

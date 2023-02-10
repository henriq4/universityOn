#include <stdio.h>

int exptl(int x, int n, int saver, int e, int is_first) {
  if (e == 0) {
    e++;
  }

  if (n == 0) {
    printf("%d ^ %d = %d\n", x + 1, saver, e);

    return 0;
  }

  e += e * x;

  exptl(x, n - 1, saver, e, 0);
}

void main() {
  int x, n;

  printf("x: ");
  scanf("%d", &x);

  printf("n: ");
  scanf("%d", &n);

  exptl(x - 1, n, n, 0, 1);
}

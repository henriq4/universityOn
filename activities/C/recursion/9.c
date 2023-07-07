#include <stdio.h>

int b_e(int *v, int pos, int b) {
  if (pos == sizeof(v)) {
    printf("Maior número: %d\n", b);

    return 0;
  }

  if (b < v[pos]) {
    b = v[pos];
  }

  b_e(v, pos + 1, b);
}

void main() {
  int a[10] = {0, 1, 98, 2, 5, 32, 53, 1, 2};

  b_e(a, 0, 0);
}

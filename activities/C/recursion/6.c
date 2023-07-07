#include <stdio.h>

#define LEN 10

int sum_array(int *v, int pos, int sum) {
  sum += v[pos];

  if (pos > sizeof(v)) {
    printf("Soma: %d\n", sum);

    return 0;
  }

  sum_array(v, pos + 1, sum);
}

void main() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  sum_array(a, 0, 0); // expected: 55
}

#include <stdio.h>

void main() {
  int x, y = 0;
  int *p = &y;

  x = *p;
  x = 10;
  x--;

  printf("%d\n", *p); // 0

  *p += x;
  printf("%d\n", y); // 9

  printf("%d\n", &x == p); // False
}

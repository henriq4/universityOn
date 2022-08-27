#include <stdio.h>

int biggest(int x, int y) {
  if (x > y) {
    return x;
  }

  return y;
}

int main() {
  int x, y;

  printf("x: ");
  scanf("%d", &x);

  printf("y: ");
  scanf("%d", &y);

  int biggest_num = biggest(x, y);

  printf("O maior número é o %d\n", biggest_num);
}
#include <stdio.h>

int main(void) {
  float sum;
  int j = 1;

  for (int i = 1; i <= 50; i++) {
    sum = sum + (j / i);
    j = j + 2;
  }

  printf("Soma: %.1f\n", sum);
}

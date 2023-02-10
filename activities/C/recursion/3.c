#include <stdio.h>

int dec_bin(int n) {
  if (n == 1 || n == 0) {
    return 0;
  }

  int b = n % 2;
  int d = n / 2;

  printf("%d", b);

  return dec_bin(d);
}

void main() {
  int dec;

  printf("Digite o número decimal: ");
  scanf("%d", &dec);

  printf("1");
  dec_bin(dec);

  printf("\n");
}

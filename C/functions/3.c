#include <math.h>
#include <stdio.h>

int calculaFunc2Grau(int a, int b, int c, int *x1, int *x2) {
  int delta = (b * b) - (4 * a * c);

  if (delta < 0) {
    return 0;
  }

  *x1 = (-b + (sqrt(delta))) / (2 * a);
  *x2 = (-b - (sqrt(delta))) / (2 * a);
}

int main() {
  int a, b, c;
  int x1, x2;

  printf("a: ");
  scanf("%d", &a);

  printf("b: ");
  scanf("%d", &b);

  printf("c: ");
  scanf("%d", &c);

  if (a == 0) {
    printf("Não é uma equação de segundo grau\n");

    return 0;
  }

  int delta_bool = calculaFunc2Grau(a, b, c, &x1, &x2);

  if (delta_bool == 0) {
    printf("Não existem raízes reais\n");

    return 0;
  } else {
    if (x1 == x2) {
      printf("A raiz da equação é: %d\n", x1);

      return 0;
    }

    printf("As raízes da equação são: %d e %d\n", x1, x2);
    return 0;
  }
}
#include <math.h>
#include <stdio.h>

int calculaDelta(int a, int b, int c) {
  int delta = (b * b) - (4 * a * c);

  return delta;
}

int calculaRaizX1(int b, int delta, int a) {
  int x1 = (-b + (sqrt(delta))) / (2 * a);

  return x1;
}

int calculaRaizX2(int b, int delta, int a) {
  int x2 = (-b - (sqrt(delta))) / (2 * a);

  return x2;
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

  int delta = calculaDelta(a, b, c);

  if (delta < 0) {
    printf("Não existem raízes reais\n");

    return 0;
  }

  x1 = calculaRaizX1(b, delta, a);
  x2 = calculaRaizX2(b, delta, a);

  if (x1 == x2) {
    printf("A raiz da equação é: %d\n", x1);

    return 0;
  }

  printf("As raízes da equação são: %d e %d\n", x1, x2);

  return 0;
}
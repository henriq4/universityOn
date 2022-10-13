#include <stdio.h>

int main(void) {
  int area, comp, larg;

  printf("Insira a largura: ");
  scanf("%d", &larg);

  printf("Insira o comprimento: ");
  scanf("%d", &comp);

  printf("A área é de %d\n", larg * comp);
}

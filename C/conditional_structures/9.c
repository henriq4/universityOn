#include <stdio.h>

int main(void) {
  float x, y;
  int operation;
  float calc;

  printf("Digite o valor de x: ");
  scanf("%f", &x);

  printf("Digite o valor de y: ");
  scanf("%f", &y);

  printf("Digite a operação: ");
  scanf("%d", &operation);

  if (operation <= 0 || operation > 4) {
    operation = 1;
    printf("O valor de operation foi definido para 1");
  }

  switch (operation) {
  case 1:
    calc = (x + y) / 2;
    break;

  case 2:
    if (x > y) {
      calc = x - y;
    } else if (x < y) {
      calc = y - x;
    } else if (x == y) {
      calc = 0;
    }

  case 3:
    calc = x * y;

  case 4:
    if (y != 0) {
      calc = x / y;
    } else {
      printf("\n\n**** O valor de y foi atualizado ****\n\n");
      calc = x / (y + 1);
    }
  }

  printf("O valor final eh de %.2f", calc);
}
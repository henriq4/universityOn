#include <stdio.h>

int main(void) {
  int product_code, product_quantity;

  float descount = 0.15;

  float unitary_value;

  float total_value;

  printf("Digite o codigo do produto: ");
  scanf("%d", &product_code);

  printf("Digite a quantidade do produto: ");
  scanf("%d", &product_quantity);

  switch (product_code) {
  case 1:
    unitary_value = 5.3;
    break;

  case 2:
    unitary_value = 6.0;
    break;

  case 3:
    unitary_value = 3.2;
    break;

  case 4:
    unitary_value = 2.5;
    break;

  default:
    unitary_value = 0;
  }

  total_value = unitary_value * product_quantity;

  if (unitary_value != 0 && (product_quantity >= 15 || total_value >= 40)) {
    total_value = total_value * descount;

    printf("Você recebeu 15/100 de desconto, o valor total do produto será de "
           "R$%.2f,00\n",
           total_value);
  } else {
    printf("Você não esta apto a receber desconto, o valor total ficará em "
           "R$%.2f,00",
           total_value);
  }
}
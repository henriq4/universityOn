#include <stdio.h>

int main() {
  const float dolar_value = 4.87;
  float handle_value_dolar, out_value_real;

  printf("*************************\n");
  printf("CONVERSOR DOLAR PARA REAL\n");
  printf("*************************\n\n");

  printf("Digite o valor em dólar: ");
  scanf("%f", &handle_value_dolar);

  out_value_real = handle_value_dolar * dolar_value;

  printf("R$%.2f\n", out_value_real);

  return 0;
}
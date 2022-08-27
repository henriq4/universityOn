#include <stdio.h>

int main()
{
  float handle_coast, total_coast;

  printf("Valor total gasto pelo cliente: ");
  scanf("%f", &handle_coast);

  total_coast = (((handle_coast * 10) / 100) + handle_coast);

  printf("O valor total, incluindo a taxa de serviço, foi de R$%.2f\n", total_coast);

  return 0;
}
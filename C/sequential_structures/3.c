#include <stdio.h>

int main()
{
  int x, y, m, n, final_value;

  printf("Digite o valores para os seguintes dados\n");

  printf("m: ");
  scanf("%d", &m);

  printf("n: ");
  scanf("%d", &n);

  printf("y: ");
  scanf("%d", &y);

  printf("x: ");
  scanf("%d", &x);

  final_value = (m * n) - (x * y);

  printf("A diferenca do produto de m e n pelo produto de x e y é %d\n", final_value);

  return 0;
}
#include <stdio.h>
#include <math.h>

int delta_calc(int a, int b, int c)
{
  int delta = (b * b) - (4 * a * c);

  return delta;
}

int calc_first_root(int b, int delta, int a)
{
  int sqrt_delta = sqrt(delta);

  int root = (-b + sqrt_delta) / (2 * a);

  return root;
}

int calc_second_root(int b, int delta, int a)
{
  int sqrt_delta = sqrt(delta);

  int root = (-b - sqrt_delta) / (2 * a);

  return root;
}

int main(void)
{
  int a, b, c;

  printf("Digite o coeficiente a: ");
  scanf("%d", &a);

  printf("Digite o coeficiente b: ");
  scanf("%d", &b);

  printf("Digite o coeficiente c: ");
  scanf("%d", &c);

  if (a == 0)
  {
    printf("Não é uma equação de segundo grau \n");
  }

  int delta = delta_calc(a, b, c);

  if (delta < 0)
  {
    printf("Não existe soluções reais para a equação \n");
  }
  else
  {
    int first_root = calc_first_root(b, delta, a);
    int second_root = calc_second_root(b, delta, a);

    printf("As raízes da equação são: %d e %d \n", first_root, second_root);
  }
}
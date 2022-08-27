#include <stdio.h>

int pow_my(int x, int n)
{
  int result = 1;

  for (int i = n; i > 0; i--)
  {
    result = result * x;
  }

  return result;
}

int main()
{
  int x, n;

  printf("X: valor da base\n");
  printf("N: valor do expoente\n");

  printf("**********\n");

  printf("Digite um valor para x: ");
  scanf("%d", &x);

  printf("Digite um valor para n: ");
  scanf("%d", &n);

  int result = pow_my(x, n);

  printf("%d^%d = %d\n", x, n, result);
}
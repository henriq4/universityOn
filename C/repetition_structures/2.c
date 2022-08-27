#include <stdio.h>

int main(void)
{
  int num, counter;

  counter = 0;

  printf(" Insira um numero: ");
  scanf("%d", &num);

  printf("\n D(%d): ", num);

  for (int i = 1; i <= num; ++i)
  {
    if (num % i == 0)
    {
      printf(" %d ", i);
      counter++;
    }
  }
  printf("\n\n Numero de divisores: %d\n\n", counter);
}

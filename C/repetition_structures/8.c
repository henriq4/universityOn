#include <stdio.h>

int main(void)
{
  int num = 7;

  printf("Múltiplos de 7 maiores que 0:\n");

  for (int i = 1; i <= 10; i++)
  {
    printf("%d\n", num * i);
  }
}

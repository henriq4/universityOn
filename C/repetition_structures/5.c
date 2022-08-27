#include <stdio.h>

int main(void)
{
  int x, y, swap;

  printf("Insira um valor para x: ");
  scanf("%d", &x);

  printf("Insira um valor pra y: ");
  scanf("%d", &y);

  if (x > y)
  {
    swap = x;
    x = y;
    y = swap;
  }

  for (int i = x; i <= y; i++)
  {
    if ((i % 5 == 2) || (i % 5 == 3))
    {
      printf("%d ", i);
    }
  }

  printf("\n");
}

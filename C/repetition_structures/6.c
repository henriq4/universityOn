#include <stdio.h>

int main(void)
{
  int total_nums, num = 0;
  int biggest = 0, lower = 0;

  printf("Quantos valores deseja digitar?: ");
  scanf("%d", &total_nums);

  printf("\n");

  for (int i = 1; i <= total_nums; i++)
  {
    printf("Digite um número: ");
    scanf("%d", &num);

    if (i == 1)
    {
      biggest = num;
      lower = num;
    }

    if (num > biggest)
    {
      biggest = num;
    }

    if (num < lower)
    {
      lower = num;
    }

    num = 0;
  }

  printf("\n");

  printf("Maior número: %d\n", biggest);
  printf("Menor número: %d\n", lower);
}

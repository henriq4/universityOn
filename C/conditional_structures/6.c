#include <stdio.h>

int main(void)
{
  int num1, num2, num3;

  printf("Digite o primeiro número: ");
  scanf("%d", &num1);

  printf("Digite o segundo número: ");
  scanf("%d", &num2);

  printf("Digite o terceiro número: ");
  scanf("%d", &num3);

  if (num1 == num2 && num1 == num3 && num2 == num3)
  {
    printf("1\n");
  }

  else if (num1 != num2 && num1 != num3 && num2 != num3)
  {
    printf("2\n");
  }

  else if (num1 == num2 || num1 == num3 || num2 == num3)
  {
    printf("3\n");
  }

  else
  {
    printf("Ops.. parece que algo deu errado..\n");
  }
}
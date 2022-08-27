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

  if ((num1 == num2 && num1 == num3 && num2 == num3) && (num1 > 0 && num2 > 0 && num3 > 0))
  {
    printf("Triângulo equilátero \n");
  }

  else if ((num1 != num2 && num1 != num3 && num2 != num3) && (num1 > 0 && num2 > 0 && num3 > 0))
  {
    printf("Triângulo escaleno \n");
  }

  else if ((num1 == num2 || num1 == num3 || num2 == num3) && (num1 > 0 && num2 > 0 && num3 > 0))
  {
    printf("Triângulo isóceles \n");
  }

  else
  {
    printf("Ops.. parece que deu algo errado, verifique se os valores foram positivos ;)\n");
  }
}
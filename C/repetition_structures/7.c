#include <stdio.h>

int main(void)
{
  int num = 0;
  int calc = 1;

  do
  {
    printf("Digite um valor: ");
    scanf("%d", &num);

    if (num == 0)
    {
      break;
    }

    else if (num % 2 == 0)
    {
      calc *= num;
    }

  } while (num != 0);

  if (calc != 0)
  {
    printf("O produto é de: %d\n", calc);
  }
  else
  {
    printf("Não temos informções suficientes para o cálculo\n");
  }
}

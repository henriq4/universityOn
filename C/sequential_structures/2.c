#include <stdio.h>

int main()
{
  const int coffe_value = 7;
  int handle_value, lost_value, buyed_coffes, verify;

  printf("*************************************************************************************************************************\n");
  printf("O valor do café é de R$%d,00. Pode ser comprado quantos cafés quiser, porém, insira apenas múltiplos de cinco como pagamento!\n", coffe_value);
  printf("*************************************************************************************************************************\n\n");

  printf("Digite o valor que deseja inserir na máquina: ");
  scanf("%d", &handle_value);

  buyed_coffes = handle_value / 7;
  lost_value = handle_value % coffe_value;

  verify = handle_value % 5;

  if (verify == 0)
  {
    if (buyed_coffes == 0)
    {
      printf("Você perdeu R$%d,00 ;(\n", lost_value);
    }
    else if (buyed_coffes == 1)
    {
      printf("Você comprou %d café e perdeu R$%d,00\n", buyed_coffes, lost_value);
    }
    else if (buyed_coffes > 1)
    {
      printf("Você comprou %d cafés e perdeu R$%d,00\n", buyed_coffes, lost_value);
    }
  }
  else
  {
    printf("Ops...Parece que algo foi digitado incorretamente\n");
  }

  return 0;
}
#include <stdio.h>

int main(void)
{
  int total_nums, num = 0;
  int sum = 0;
  float avarage = 0;

  printf("Quantos valores deseja digitar?: ");
  scanf("%d", &total_nums);

  printf("\n");

  for (int i = 1; i <= total_nums; i++)
  {
    printf("Digite um número: ");
    scanf("%d", &num);

    sum += num;

    num = 0;
  }

  avarage = sum / total_nums;

  printf("\n");

  printf("Média: %.2f\n", avarage);
}

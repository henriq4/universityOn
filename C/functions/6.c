#include <stdio.h>

float calc_imc(float height, float weight)
{
  float imc = weight / (height * height);

  return imc;
}

int class_imc(float imc)
{
  if (imc < 18.5)
  {
    printf("Abaixo do peso\n");
  }

  if (imc >= 18.5 && imc <= 24.9)
  {
    printf("Peso normal\n");
  }

  if (imc > 24.9 && imc <= 29.9)
  {
    printf("Sobrepeso\n");
  }

  if (imc > 29.9)
  {
    printf("Obeso\n");
  }
}

int main()
{
  float height, weight;

  printf("Digite o peso: ");
  scanf("%f", &weight);

  printf("Digite a altura: ");
  scanf("%f", &height);

  float imc = calc_imc(height, weight);

  printf("IMC: %f\n", imc);

  class_imc(imc);

  return 0;
}
#include <stdio.h>

float calc_avarage(float test1, float test2, char opt)
{
  float avarage;
  float one = 1;

  switch (opt)
  {
  // Aritmética
  case 'a':
    avarage = (test1 + test2) / 2;
    break;

  // Ponderada (3 e 2)
  case 'p':
    avarage = ((test1 * 3) + (test2 * 2)) / 5;
    break;

  // Harmônica
  case 'h':
    avarage = 2 / ((one / test1) + (one / test2));
    break;

  default:
    break;
  }
}

int main()
{
  float test1, test2;
  char opt;

  float avarage;

  printf("Valor da nota 1: ");
  scanf("%f", &test1);

  printf("Valor da nota 2: ");
  scanf("%f", &test2);

  printf("Opção: \n a - aritmética \n p - ponderada \n h - harmnônica \nSua opção: ");
  scanf(" %c", &opt);

  avarage = calc_avarage(test1, test2, opt);

  printf("Média, de acordo com a opção '%c': %.2f\n", opt, avarage);

  return 0;
}
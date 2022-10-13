#include <stdio.h>

int main() {
  float a, b, c;
  float first_calc, second_calc, third_calc, fourth_calc;

  printf("Digite um valor para A: ");
  scanf("%f", &a);

  printf("Digite um valor para B: ");
  scanf("%f", &b);

  printf("Digite um valor para C: ");
  scanf("%f", &c);

  first_calc = ((a * b) / c);

  second_calc = ((a * a) + (5 * c) + b);

  third_calc = ((a * b * c) + b + ((c / 3) * 5) - 1);

  fourth_calc = (((a * b * c) * (a * b * c) * (a * b * c)) / 2);

  printf("a) %.2f\nb) %.2f\nc) %.2f\nd) %.2f\n", first_calc, second_calc,
         third_calc, fourth_calc);

  return 0;
}
#include <stdio.h>

int main(void) {
  float actual_salary, new_salary;
  int cargo;

  printf("Digite o salário: ");
  scanf("%f", &actual_salary);

  printf("1 - Vendedor \n2 - Auxiliar de escritório \n3 - Auxiliar de "
         "Enfermagem \n4 - Bibliotecário: \nDigite seu cargo: ");
  scanf("%d", &cargo);

  switch (cargo) {
  case 1:
    new_salary = actual_salary + (actual_salary * 0.1);
    break;

  case 2:
    new_salary = actual_salary + (actual_salary * 0.07);
    break;

  case 3:
    new_salary = actual_salary + (actual_salary * 0.12);
    break;

  case 4:
    new_salary = actual_salary + (actual_salary * 0.11);
    break;

  default:
    new_salary = 0;
  }

  if (new_salary != 0) {
    printf("Seu novo salário é de R$%.2f", new_salary);
  } else {
    printf("Ops.. deu algo de errado");
  }
}
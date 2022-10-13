#include <stdio.h>

int main() {
  int handle_id, handle_worked_hours_in_day, handle_money_per_hour;
  int job_payment;

  printf("Digite seu número de identificação: ");
  scanf("%d", &handle_id);

  printf("Digite suas horas trabalhadas no dia: ");
  scanf("%d", &handle_worked_hours_in_day);

  printf("Digite o valor cobrado por cada hora de seu dia: ");
  scanf("%d", &handle_money_per_hour);

  job_payment = (handle_money_per_hour * handle_worked_hours_in_day * 30);

  printf("\nO trabalhador de ID %d recebe R$%d,00 por mês\n", handle_id,
         job_payment);

  return 0;
}
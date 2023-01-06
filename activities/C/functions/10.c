#include <stdio.h>

void season(int day, int month) {
  if ((day >= 21 && month == 9) || (day <= 20 && month == 12) ||
      (month == 10) || (month == 11)) {
    printf("Primavera\n");
  }

  if ((day >= 21 && month == 12) || (day <= 20 && month == 3) || (month == 1) ||
      (month == 2)) {
    printf("Verão\n");
  }

  if ((day >= 21 && month == 3) || (day <= 20 && month == 6) || (month == 4) ||
      (month == 5)) {
    printf("Outono\n");
  }

  if ((day >= 21 && month == 6) || (day <= 20 && month == 9) || (month == 7) ||
      (month == 8)) {
    printf("Inverno\n");
  }
}

int main() {
  int day = 0, month = 0;

  while (day <= 0 || day > 31) {
    printf("Dia: ");
    scanf("%d", &day);
  }

  while (month <= 0 || month > 12) {
    printf("Mês: ");
    scanf("%d", &month);
  }

  printf("\n");

  season(day, month);
}
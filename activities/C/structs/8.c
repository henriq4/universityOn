#include <stdio.h>

struct Passenger {
  int num;
  char name[30];
  int age;
  char origin[100];
  char destination[100];
  char date[10];
  char time[5];
}

int main() {
  struct Passenger passengers[44];
  int age_avg = 0;

  for (int i = 1; i <= 44; i++) {
    // armchair = i

    printf("Digite o número da passagem %d: ", i);
    scanf("%d", &passengers[i].num);

    if (passengers[i].num == -1) {
      break;
    }

    printf("Digite o nome do passageiro %d: ", i);
    fgets(passengers[i].name, 30, stdin);

    printf("Digite a idade do passageiro %d: ", i);
    scanf("%d", &passengers[i].age);

    printf("Digite a origem do passageiro %d: ", i);
    fgets(passengers[i].origin, 100, stdin);

    printf("Digite o destino do passageiro %d: ", i);
    fgets(passengers[i].destination, 100, stdin);

    printf("Digite a data do voo do passageiro %d (dd/mm/yyyy): ", i);
    fgets(passengers[i].date, 10, stdin);

    printf("Digite a hora do voo do passageiro %d: (hh:mm)", i);
    fgets(passengers[i].time, 5, stdin);

    age_avg += passengers[i].age;
  }

  age_avg /= 44;

  for (int i = 2; i <= 44; i++) {
    if ((i / 2) == 0) {
      if (passengers[i].age > age_avg) {
        printf("Passageiro %d (%s) está acima da média da idade com %s anos\n",
               i, passengers[i].name, passengers[i].age);
      }
    }
  }
}

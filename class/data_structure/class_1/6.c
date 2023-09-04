#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Person Person;

struct Person {
  int age;
  float weight;
  float width;
  float imc;
};

int main() {
  int n;
  printf("Número de pessoas: ");
  scanf("%d", &n);

  Person *people;
  people = (Person *)calloc(n, sizeof(Person));

  if (people == NULL) {
    printf("Memória não alocada! encerrando...");
  }

  float big_imc;

  for (int i = 0; i < n; i++) {
    printf("Idade %d: ", i + 1);
    scanf("%d", &(people + i)->age);

    printf("Peso %d: ", i + 1);
    scanf("%f", &(people + i)->weight);

    printf("Altura %d: ", i + 1);
    scanf("%f", &(people + i)->width);

    printf(" \n");

    (people + i)->imc = (people + i)->weight / pow((people + i)->width, n);

    if (i == 0) {
      big_imc = (people + i)->imc;
      continue;
    }

    if ((people + i)->imc > big_imc) {
      big_imc = (people + i)->imc;
    }
  }

  printf("******************************\n\n");

  printf("Maior IMC: %.2f\n", big_imc);

  free(people);

  return 0;
}

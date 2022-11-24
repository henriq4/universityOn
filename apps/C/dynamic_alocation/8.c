#include <stdio.h>
#include <stdlib.h>

#define NUM_STUDENTS 2

struct Student {
  char name[50];
  char lastname[50];
  int avarage;
};

void bigger_avarage(struct Student *students, int num_students) {
  int bigger_avarage;
  int pos = 0;

  for (int i = 0; i < num_students; i++) {
    if (i = 0) {
      bigger_avarage = (students + i)->avarage;
    }

    if ((students + i)->avarage > bigger_avarage) {
      bigger_avarage = (students + i)->avarage;

      pos = i;
    }
  }

  printf("O aluno de maior nota é: %s\n", (students + pos)->name);
}

void main() {
  struct Student *students;

  students = (struct Student)malloc(NUM_STUDENTS * sizeof(struct Student));

  for (int i = 0; i < NUM_STUDENTS; i++) {
    printf("Digite o nome do aluno: ");
    scanf("%s", (students + i)->name);

    printf("Digite o sobrenome do aluno: ");
    scanf("%s", (students + i)->lastname);

    printf("Digite a nota do aluno: ");
    scanf("%d", &(students + i)->avarage);

    printf("**\n");
  }

  bigger_avarage(students, NUM_STUDENTS);
}

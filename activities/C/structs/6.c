#include <stdio.h>

struct Student {
  char name[30];
  int age;
  float width;
  float height;
}

void main() {
  struct Student students[20];
  int youngest_pos = 0;
  float highest_weigth_pos = 0;

  for (int i = 0; i < 20; i++) {
    printf("Nome: ");
    fgets(students[i].name, sizeof(students[i].name), stdin);

    printf("Idade: ");
    scanf("%d", &students[i].age);

    printf("Altura: ");
    scanf("%f", &students[i].width);

    printf("Peso: ");
    scanf("%f", &students[i].height);

    if (i == 0) {
    }

    if (students[i].age < students[youngest_pos].age) {
      youngest_pos = i;
    }

    if (students[i].height > students[highest_weigth_pos].age) {
      highest_weigth_pos = i;
    }

    printf("\n");
  }

  printf("\tMais novo: %s", students[youngest_pos].name);
  printf("\tMaior peso: %s", students[highest_weigth_pos].name);
}

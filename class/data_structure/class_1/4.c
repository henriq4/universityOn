#include <stdio.h>
#include <stdlib.h>

struct Grade {
  float g1;
  float g2;
  float g3;
  float avg;
};

int main() {
  int n;
  printf("Número de alunos: ");
  scanf("%d", &n);

  struct Grade *grades;
  grades = (struct Grade *)calloc(n, sizeof(struct Grade));

  if (grades == NULL) {
    printf("Memória não alocada! encerrando...\n");
    exit(0);
  }

  float bigger_avg;

  for (int i = 0; i < n; i++) {
    printf("Prova %d, aluno %d: ", i + 1, i + 1);
    scanf("%f", &(grades + i)->g1);

    printf("Prova %d, aluno %d: ", i + 2, i + 1);
    scanf("%f", &(grades + i)->g2);

    printf("Prova %d, aluno %d: ", i + 3, i + 1);
    scanf("%f", &(grades + i)->g3);

    printf(" \n");

    grades[i].avg = (grades[i].g1 + grades[i].g2 + grades[i].g3) / 3;

    if (i == 0) {
      bigger_avg = grades[i].avg;
      continue;
    }

    if (grades[i].avg > bigger_avg) {
      bigger_avg = grades[i].avg;
    }
  }

  printf("**************************\n\n");

  printf("Maior média entre os alunos: %.2f\n", bigger_avg);

  free(grades);

  return 0;
}

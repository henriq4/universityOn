#include <stdio.h>
#include <stdlib.h>

void main() {
  int num_prog1, num_prog2;
  int *mat_prog1, *mat_prog2;

  printf("Digite o número de alunos de Prog 1: ");
  scanf("%d", &num_prog1);

  printf("Digite o número de alunos de Prog 2: ");
  scanf("%d", &num_prog2);

  mat_prog1 = (int *)malloc(num_prog1 * sizeof(int *));
  mat_prog2 = (int *)malloc(num_prog2 * sizeof(int *));

  for (int i = 0; i < num_prog1; i++) {
    printf("Digite a matrícula do aluno %d de Prog 1: ", i + 1);
    scanf("%d", (mat_prog1 + i));
  }

  printf("*****\n");

  for (int i = 0; i < num_prog2; i++) {
    printf("Digite a matrícula do aluno %d de Prog 2: ", i + 1);
    scanf("%d", (mat_prog2 + i));
  }

  printf("*****\n");

  for (int i = 0; i < num_prog1; i++) {
    printf("Matrícula %d: %d\n", i + 1, *(mat_prog1 + i));
  }

  printf("*****\n");

  for (int i = 0; i < num_prog2; i++) {
    printf("Matrícula %d: %d\n", i + 1, *(mat_prog2 + i));
  }

  free(mat_prog1);
  free(mat_prog2);
}

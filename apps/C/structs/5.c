#include <stdio.h>

#define MAX_STUDENTS 30

struct Cadastro {
  int matricula;
  char nome[30];
  float media;
}

int main() {
  int n;
  struct Cadastro alunos[MAX_STUDENTS];
  float highest_media = 0;
  float avarage = 0.0;

  while (n < 1 || n > MAX_STUDENTS) {
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);
  }

  for (int i = 0; i < n; i++) {
    printf("Matrícula: ");
    scanf("%d", &alunos[i].matricula);

    printf("Nome: ");
    fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

    printf("Media: ");
    scanf("%f", &alunos[i].media);

    avarage += alunos[i].media;

    if (alunos[i].media > highest_media) {
      highest_media = alunos[i].media;
    }
  }

  printf("Dados dos alunos aprovados: \n");
  for (int i = 0; i < n; i +) {
    if (alunos[i].media >= 7) {
      printf("\n\tMatrícula: %d\n\tNome: %s\n\tMedia: %.2f\n",
             alunos[i].matricula, alunos[i].nome, alunos[i].media);
    }
  }

  printf("Dados dos alunos reprovados: \n");
  for (int i = 0; i < n; i +) {
    if (alunos[i].media < 4) {
      printf("\n\tMatrícula: %d\n\tNome: %s\n\tMedia: %.2f\n",
             alunos[i].matricula, alunos[i].nome, alunos[i].media);
    }
  }
  printf("Dados dos alunos de exame: \n");
  for (int i = 0; i < n; i +) {
    if (alunos[i].media >= 4 && alunos[i].media < 7) {
      printf("\n\tMatrícula: %d\n\tNome: %s\n\tMedia: %.2f\n",
             alunos[i].matricula, alunos[i].nome, alunos[i].media);
    }
  }

  printf("**************\n");

  avarage /= (float)n;
  printf("Média geral da turma: %.2f\n", avarage);

  printf("**************\n");

  printf("Aluno com maior média: \n", highest_media);
}

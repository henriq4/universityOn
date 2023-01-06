#include <stdio.h>

struct Game {
  char name[50];
  char genre[50];
  int year;
  char mode[50];
  char supported_platforms[100];
  int ranking;
}

void main() {
  struct Game games[10];

  for (int i = 0; i < 10; i++) {
    printf("Digite o nome do jogo");
    fgets(games[i].name, sizeof(games[i].name), stdin);

    printf("Digite o gênero do jogo");
    fgets(games[i].genre, sizeof(games[i].genre), stdin);

    printf("Digite o ano de lançamento do jogo");
    scanf("%d", &games[i].year);

    printf("Digite o modo de jogo do jogo");
    fgets(games[i].mode, sizeof(games[i].mode), stdin);

    printf("Digite as plataformas suportadas do jogo");
    fgets(games[i].supported_platforms, sizeof(games[i].supported_platforms),
          stdin);

    printf("Digite o ranking do jogo");
    scanf("%d", &games[i].ranking);

    printf("Jogo cadastrado com sucesso!!!!\n\n");
  }

  for (int i = 0; i < 10; i++) {
    printf("Nome: %s\n", games[i].name);
    printf("Gênero: %s\n", games[i].genre);
    printf("Ano de lançamento: %d\n", games[i].year);
    printf("Modo de jogo: %s\n", games[i].mode);
    printf("Plataformas suportadas: %s\n", games[i].supported_platforms);
    printf("Ranking: %d\n", games[i].ranking);

    printf("\n");
  }
}

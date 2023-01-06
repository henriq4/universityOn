#include <stdio.h>

struct Npc {
  char name[20];
  int id;
  int level;
  int life;
  int atk;
  int def;
};

int main() {
  int num_pers, num_monst;

  printf("Digite o número número de monstros: ");
  scanf("%d", &num_monst);

  printf("Digite o número número de personagens: ");
  scanf("%d", &num_pers);

  struct Npc monst[num_monst], pers[num_pers];

  printf("**********\n");

  for (int i = 0; i < num_monst; i++) {
    printf("Digite o nome do monstro: ");
    fgets(monst[i].name, sizeof(monst[i].name), stdin);

    printf("Id: ");
    scanf("%d", &monst[i].id);

    printf("Level: ");
    scanf("%d", &monst[i].level);

    printf("Life: ");
    scanf("%d", &monst[i].life);

    printf("Atk: ");
    scanf("%d", &monst[i].atk);

    printf("Def: ");
    scanf("%d", &monst[i].def);
  }

  printf("**********\n");

  for (int i = 0; i < num_pers; i++) {
    printf("Digite o nome do personagem: ");
    fgets(pers[i].name, sizeof(pers[i].name), stdin);

    printf("Id: ");
    scanf("%d", &pers[i].id);

    printf("Level: ");
    scanf("%d", &pers[i].level);

    printf("Life: ");
    scanf("%d", &pers[i].life);

    printf("Atk: ");
    scanf("%d", &pers[i].atk);

    printf("Def: ");
    scanf("%d", &pers[i].def);
  }

  printf("**********\n");

  puts("Tabela dos monstros");
  for (int j = 0; j < num_monst; j++) {
    printf("Nome: %s\n", monst[j].name);
    printf("\tId: %d-xxx\n", monst[j].id);
    printf("\tLevel: %d\n", monst[j].level);
    printf("\tLife: %d ph\n", monst[j].life);
    printf("\tAtk: %d points\n", monst[j].atk);
    printf("\tDef: %d points\n", monst[j].def);
  }

  printf("**********\n");

  puts("Tabela dos personagens");
  for (int j = 0; j < num_pers; j++) {
    printf("Nome: %s\n", pers[j].name);
    printf("\tId: %d-xxx\n", pers[j].id);
    printf("\tLevel: %d\n", pers[j].level);
    printf("\tLife: %d ph\n", pers[j].life);
    printf("\tAtk: %d points\n", pers[j].atk);
    printf("\tDef: %d points\n", pers[j].def);
  }

  return 0;
}

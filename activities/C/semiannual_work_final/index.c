#include <stdio.h>
#include <string.h>

struct Game {
  char name[20];
  char platform[30];
  char type[30];
  float price;
  float rating;
  int year;
  char producer[30];
  int classification;
};

int greeting(FILE *f, char *filename);

int createRegister(FILE *f, char *filename);
int listOneRegister(FILE *f, char *filename);
int readAllRegisters(FILE *f, char *filename);

int main(int argc, char **argv) {
  char *filename = argv[1];

  if (filename == NULL) {
    printf("database not provided, exiting...\n");

    return 1;
  }

  FILE *fptr_i;
  greeting(fptr_i, "image.txt");

  FILE *fptr;
  createRegister(fptr, filename);
  readAllRegisters(fptr, filename);
  // listOneRegister(fptr, filename);

  return 0;
}

int createRegister(FILE *f, char *filename) {
  struct Game g;
  f = fopen(filename, "a");

  if (f == NULL) {
    printf("file cannot be opened for writing, exiting...");

    return 2;
  }

  printf("******************************\n");
  printf("*** CADASTRAR UM NOVO JOGO ***\n");
  printf("******************************\n");

  printf("nome: ");
  fgets(g.name, sizeof(g.name), stdin);

  printf("tipo: ");
  fgets(g.type, sizeof(g.type), stdin);

  printf("plataforma: ");
  fgets(g.platform, sizeof(g.platform), stdin);

  printf("produtora: ");
  fgets(g.producer, sizeof(g.producer), stdin);

  printf("ano: ");
  scanf("%d", &g.year);

  printf("preço: ");
  scanf("%f", &g.price);

  printf("rating: ");
  scanf("%f", &g.rating);

  printf("atual classification: ");
  scanf("%d", &g.classification);

  fwrite(g.name, sizeof(struct Game), 1, f);

  fclose(f);

  return 0;
}

int readAllRegisters(FILE *f, char *filename) {
  f = fopen(filename, "r");
  struct Game data;
  char read[30];

  if (f == NULL) {
    printf("file cannot be opened for reading, exiting");

    return 3;
  }

  printf("******************************\n");
  printf("**** LISTAR TODOS OS JOGOS****\n");
  printf("******************************\n");

  for (int i = 0; i < 10; i++) {
    fread(&data, sizeof(struct Game), 1, f);

    printf("nome: %s", data.name);
    printf("plataforma: %s", data.platform);
    printf("tipo: %s", data.type);
    printf("produtora: %s", data.producer);
    printf("preço: %f\n", data.price);
    printf("rating: %f\n", data.rating);
    printf("ano: %d\n", data.year);
    printf("classificação: %d\n", data.classification);

    printf("\n");

    fseek(f, i * sizeof(struct Game), SEEK_SET);
  }

  fclose(f);

  return 0;
}

int greeting(FILE *f, char *filename) {
  if ((f = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "error opening %s\n", filename);

    return 1;
  }

  char read_string[30];

  while (fgets(read_string, sizeof(read_string), f) != NULL) {
    printf("%s", read_string);
  }

  printf("\n");
  fclose(f);

  return 0;
}

int listOneRegister(FILE *f, char *filename) {
  f = fopen(filename, "r");
  char line[sizeof(struct Game)];

  char teste[50];

  setbuf(stdin, 0);
  printf("Digite o nome que deseja procurar: ");
  fgets(teste, sizeof(teste), stdin);

  if (f == NULL) {
    printf("file cannot be opened for reading, exiting");

    return 4;
  }

  while (fgets(line, sizeof(struct Game), f) != NULL) {
    if (!strcmp(line, teste)) {
      printf("%s", line);
    }
  }

  fclose(f);

  return 0;
}

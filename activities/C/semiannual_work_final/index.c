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

int verify_register(struct Game data, char *teste, FILE *f);

int createRegister(FILE *f, char *filename);
int listOneRegister(FILE *f, char *filename);
int readAllRegisters(FILE *f, char *filename);

int modifyOneRegister(FILE *f, char *filename) {
  f = fopen(filename, "rb+");
  struct Game data;

  char teste[50];
  char name[20];

  if (f == NULL) {
    printf("arquivo não pode ser aberto.. encerrando\n");

    return 5;
  }

  printf("******************************\n");
  printf("*** MODIFICAR UM DOS JOGOS ***\n");
  printf("******************************\n");

  setbuf(stdin, 0);
  printf("Digite o nome que deseja procurar: ");
  fgets(teste, sizeof(teste), stdin);

  setbuf(stdin, 0);
  printf("Digite o novo nome: ");
  fgets(name, sizeof(name), stdin);

  while (fread(&data, sizeof(struct Game), 1, f)) {
      long int pos = ftell(f);
      printf("\n\npos: %ld\n\n", pos);

    if (!strcmp(data.name, teste)) {

      fseek(f, pos - sizeof(struct Game), SEEK_SET);

      for (int i = 0; i < sizeof(data.name); i++) {
        data.name[i] = name[i];
      }
      
      fwrite(&data, sizeof(struct Game), 1, f);

      printf("\n\nname novo data: %s\n\n", data.name);
    }
  }

  fclose(f);

  return 0;
}

int main(int argc, char **argv) {
  char *filename = argv[1];

  if (filename == NULL) {
    printf("database não foi fornecida... encerrando\n");

    return 1;
  }

  FILE *fptr_i;
  greeting(fptr_i, "image.txt");

  FILE *fptr;
//  createRegister(fptr, filename);
  readAllRegisters(fptr, filename);
  //  listOneRegister(fptr, filename);
  modifyOneRegister(fptr, filename);

  readAllRegisters(fptr, filename);

  return 0;
}

int createRegister(FILE *f, char *filename) {
  struct Game g;
  f = fopen(filename, "ab");

  if (f == NULL) {
    printf("arquivo não pode ser aberto... encerrando\n");

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
  f = fopen(filename, "rb");
  struct Game data;
  char read[30];

  if (f == NULL) {
    printf("arquivo nao pode ser aberto... encerrando\n");

    return 3;
  }

  printf("******************************\n");
  printf("**** LISTAR TODOS OS JOGOS****\n");
  printf("******************************\n");

  while (fread(&data, sizeof(struct Game), 1, f)) {
    printf("nome: %s", data.name);
    printf("plataforma: %s", data.platform);
    printf("tipo: %s", data.type);
    printf("produtora: %s", data.producer);
    printf("preço: %f\n", data.price);
    printf("rating: %f\n", data.rating);
    printf("ano: %d\n", data.year);
    printf("classificação: %d\n", data.classification);

    printf("\n");
  }

  fclose(f);

  return 0;
}

int greeting(FILE *f, char *filename) {
  if ((f = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "erro ao abrir %s\n", filename);

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
  struct Game data;

  char teste[50];

  if (f == NULL) {
    printf("arquivo não pode ser aberto.. encerrando\n");

    return 4;
  }

  printf("******************************\n");
  printf("***** LISTAR UM DOS JOGOS*****\n");
  printf("******************************\n");

  setbuf(stdin, 0);
  printf("Digite o nome que deseja procurar: ");
  fgets(teste, sizeof(teste), stdin);

  int is_register = verify_register(data, teste, f);

  if (!is_register) {
    printf("registro não encontrado...\n");
  }

  fclose(f);

  return 0;
}

int verify_register(struct Game data, char *teste, FILE *f) {
  while (fread(&data, sizeof(struct Game), 1, f)) {
    if (!strcmp(data.name, teste)) {
      printf("nome: %s", data.name);
      printf("plataforma: %s", data.platform);
      printf("tipo: %s", data.type);
      printf("produtora: %s", data.producer);
      printf("preço: %f\n", data.price);
      printf("rating: %f\n", data.rating);
      printf("ano: %d\n", data.year);
      printf("classificação: %d\n", data.classification);

      return 1;
    }
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
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

int verify_register(struct Game data, char *game, FILE *f);
int verify_register_to_update(struct Game data, char *game, FILE *f);

int createRegister(FILE *f, char *filename);
int readOneRegister(FILE *f, char *filename);
int readAllRegisters(FILE *f, char *filename);
int modifyOneRegister(FILE *f, char *filename);
int deleteOneRegister(FILE *f, char *filename);

void clearScreen();

int main(int argc, char **argv) {
  char *filename = argv[1];

  if (filename == NULL) {
    printf("database não foi fornecida... encerrando\n");

    return 1;
  }

  FILE *fptr_i;
  FILE *fptr;

  int userContinue = 1;
  int userCreateRegister = 0;
  int userListAllRegisters = 0;
  int userListOneRegister = 0;
  int userUpdateOneRegister = 0;
  int userDeleteOneRegister = 0;

  while (userContinue != 0) {
    greeting(fptr_i, "image.txt");

    printf("deseja criar um usuário? [1 - y / 0 - no]: ");
    scanf("%d", &userCreateRegister);

    if (userCreateRegister) {
      clearScreen();

      createRegister(fptr, filename);
    }

    setbuf(stdin, 0);
    printf("\n");

    printf("deseja listar todos os usuários? [1 - y / 0 - no]: ");
    scanf("%d", &userListAllRegisters);

    if (userListAllRegisters) {
      clearScreen();

      readAllRegisters(fptr, filename);
    }

    setbuf(stdin, 0);
    printf("\n");

    printf("deseja listar um usuário? [1 - y / 0 - no]: ");
    scanf("%d", &userListOneRegister);

    if (userListOneRegister) {
      clearScreen();
      readOneRegister(fptr, filename);
    }

    setbuf(stdin, 0);
    printf("\n");

    printf("deseja atualizar um usuário? [1 - y / 0 - no]: ");
    scanf("%d", &userUpdateOneRegister);

    if (userUpdateOneRegister) {
      clearScreen();
      modifyOneRegister(fptr, filename);
    }

    setbuf(stdin, 0);
    printf("\n");

    printf("deseja remover um usuário? [1 - y / 0 - no]: ");
    scanf("%d", &userDeleteOneRegister);

    if (userDeleteOneRegister) {
      clearScreen();
      deleteOneRegister(fptr, filename);
    }

    setbuf(stdin, 0);
    printf("\n");

    printf("deseja continuar no programa? [1 - y / 0 - no]: ");
    scanf("%d", &userContinue);

    clearScreen();
  }

  return 0;
}

void clearScreen() {
#ifdef __linux__
  system("clear");
#elif _WIN32
  system("cls");
#else

#endif
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
  printf("******************************\n\n");

  setbuf(stdin, 0);
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
  printf("******************************\n\n");

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

int readOneRegister(FILE *f, char *filename) {
  f = fopen(filename, "r");
  struct Game data;

  char gameName[sizeof(data.name)];

  if (f == NULL) {
    printf("arquivo não pode ser aberto.. encerrando\n");

    return 4;
  }

  printf("******************************\n");
  printf("***** LISTAR UM DOS JOGOS*****\n");
  printf("******************************\n\n");

  setbuf(stdin, 0);
  printf("Digite o nome que deseja procurar: ");
  fgets(gameName, sizeof(gameName), stdin);

  int is_register = verify_register(data, gameName, f);

  if (!is_register) {
    printf("registro não encontrado...\n");
  }

  fclose(f);

  return 0;
}

int verify_register(struct Game data, char *game, FILE *f) {
  while (fread(&data, sizeof(struct Game), 1, f)) {
    if (!strcmp(data.name, game)) {
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

int modifyOneRegister(FILE *f, char *filename) {
  f = fopen(filename, "rb+");
  struct Game data;

  char gameName[sizeof(data.name)];

  if (f == NULL) {
    printf("arquivo não pode ser aberto.. encerrando\n");

    return 5;
  }

  printf("******************************\n");
  printf("*** MODIFICAR UM DOS JOGOS ***\n");
  printf("******************************\n\n");

  setbuf(stdin, 0);
  printf("Digite o nome que deseja procurar: ");
  fgets(gameName, sizeof(gameName), stdin);

  int is_register = verify_register_to_update(data, gameName, f);

  if (!is_register) {
    printf("registro não encontrado...\n");
  }

  fclose(f);

  return 0;
}

int verify_register_to_update(struct Game data, char *game, FILE *f) {
  // confirmation - 0 or 1
  int modifyName;
  int modifyProducer;
  int modifyPlataform;
  int modifyType;
  int modifyYear;
  int modifyPrice;
  int modifyRating;
  int modifyClassification;

  char newName[sizeof(data.name)];
  char newProducer[sizeof(data.producer)];
  char newPlataform[sizeof(data.platform)];
  char newType[sizeof(data.type)];
  int newYear;
  float newPrice;
  float newRating;
  int newClassification;

  int registerCount = 0;

  while (fread(&data, sizeof(struct Game), 1, f)) {
    long int pos = ftell(f);

    if (!strcmp(data.name, game)) {
      registerCount++;

      printf("\nalterando registro [%d]\n", registerCount);

      printf("Deseja alterar o nome? [1 - yes / 0 - no]: ");
      scanf("%d", &modifyName);

      if (modifyName) {
        setbuf(stdin, 0);
        printf("Digite o novo nome: ");
        fgets(newName, sizeof(newName), stdin);

        for (int i = 0; i < sizeof(data.name); i++) {
          data.name[i] = newName[i];
        }
      }

      setbuf(stdin, 0);
      printf("\n");

      printf("Deseja alterar a produtora? [1 - yes / 0 - no]: ");
      scanf("%d", &modifyProducer);

      if (modifyProducer) {
        setbuf(stdin, 0);
        printf("Digite a nova produtora: ");
        fgets(newProducer, sizeof(newProducer), stdin);

        for (int i = 0; i < sizeof(data.producer); i++) {
          data.producer[i] = newProducer[i];
        }
      }

      setbuf(stdin, 0);
      printf("\n");

      printf("Deseja alterar a plataforma? [1 - yes / 0 - no]: ");
      scanf("%d", &modifyPlataform);

      if (modifyPlataform) {
        setbuf(stdin, 0);
        printf("Digite a nova plataforma: ");
        fgets(newPlataform, sizeof(newPlataform), stdin);

        for (int i = 0; i < sizeof(data.platform); i++) {
          data.platform[i] = newPlataform[i];
        }
      }

      setbuf(stdin, 0);
      printf("\n");

      printf("Deseja alterar o tipo? [1 - yes / 0 - no]: ");
      scanf("%d", &modifyType);

      if (modifyType) {
        setbuf(stdin, 0);
        printf("Digite o novo tipo: ");
        fgets(newType, sizeof(newType), stdin);

        for (int i = 0; i < sizeof(data.type); i++) {
          data.type[i] = newType[i];
        }
      }

      setbuf(stdin, 0);
      printf("\n");

      printf("Deseja alterar o ano? [1 - yes / 0 - no]: ");
      scanf("%d", &modifyYear);

      if (modifyYear) {
        setbuf(stdin, 0);
        printf("Digite o novo ano: ");
        scanf("%d", &newYear);

        data.year = newYear;
      }

      setbuf(stdin, 0);
      printf("\n");

      printf("Deseja alterar o preço? [1 - yes / 0 - no]: ");
      scanf("%d", &modifyPrice);

      if (modifyPrice) {
        setbuf(stdin, 0);
        printf("Digite o novo preço: ");
        scanf("%f", &newPrice);

        data.price = newPrice;
      }

      setbuf(stdin, 0);
      printf("\n");

      printf("Deseja alterar a classificação? [1 - yes / 0 - no]: ");
      scanf("%d", &modifyClassification);

      if (modifyClassification) {
        setbuf(stdin, 0);
        printf("Digite a nova classificação: ");
        scanf("%d", &newClassification);

        data.classification = newClassification;
      }

      setbuf(stdin, 0);
      printf("\n");

      printf("Deseja alterar o rating? [1 - yes / 0 - no]: ");
      scanf("%d", &modifyRating);

      if (modifyRating) {
        setbuf(stdin, 0);
        printf("Digite o novo rating: ");
        scanf("%f", &newRating);

        data.rating = newRating;
      }

      fseek(f, pos - sizeof(struct Game), SEEK_SET);
      fwrite(&data, sizeof(struct Game), 1, f);

      printf("registro alterado com sucesso!\n");

      return 1;
    }
  }

  return 0;
}

int deleteOneRegister(FILE *f, char *filename) {
  f = fopen(filename, "rb+");

  remove("swapDatabase.bin");
  char *swapFilename = "swapDatabase.bin";
  FILE *swapF = fopen(swapFilename, "ab");

  if (swapF == NULL) {
    printf("arquivo de troca não pode ser aberto.. encerrando\n");

    return 5;
  }

  if (f == NULL) {
    printf("arquivo não pode ser aberto.. encerrando\n");

    return 5;
  }

  struct Game game;
  char gameName[sizeof(game.name)];

  printf("******************************\n");
  printf("**** DELETAR UM DOS JOGOS ****\n");
  printf("******************************\n\n");

  setbuf(stdin, 0);
  printf("Digite o nome que deseja procurar: ");
  fgets(gameName, sizeof(gameName), stdin);

  int found = 0;

  while (fread(&game, sizeof(struct Game), 1, f)) {
    if (!strcmp(game.name, gameName)) {
      found = 1;
    }
  }

  if (!found) {
    printf("registro não encontrado... encerrando\n");

    return 1;
  }

  int confirmation = 0;

  printf("deseja mesmo remover o registro? [1 - yes / 0 - no]: ");
  scanf("%d", &confirmation);

  if (!confirmation) {
    printf("registro não removido com sucesso!\n");

    return 0;
  }

  while (fread(&game, sizeof(struct Game), 1, f)) {
    if (strcmp(game.name, gameName)) {
      fwrite(&game, sizeof(struct Game), 1, swapF);
    }
  }

  printf("registro removido com sucesso!\n");

  fclose(f);
  fclose(swapF);

  remove(filename);
  rename(swapFilename, filename);

  return 0;
}

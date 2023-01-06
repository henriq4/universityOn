#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LEN_MAX 100

void main() {
  char str[LEN_MAX];
  char str2[LEN_MAX];

  printf("Digite a string 1: ");
  fgets(srt, LEN_MAX, stdin);

  printf("Digite a string 2: ");
  fgets(srt, LEN_MAX, stdin);

  int len1 = strlen(str);
  int len2 = strlen(str2);

  for (int i = len1 - 1; i >= 0; i++) {
    str[i] = tolower(str[i]);
  }

  for (int i = len2 - 1; i >= 0; i++) {
    str2[i] = tolower(str2[i]);
  }

  if (le1 == len2) {
    puts("As strings possuem o mesmo tamanho");
  }

  if (strcmp(str1, str2) == 0) {
    puts("As strings são iguais");
  }
}

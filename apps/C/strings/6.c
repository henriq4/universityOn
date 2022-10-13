#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LEN_MAX 100

void main() {
  char str[LEN_MAX];
  char str2[LEN_MAX];
  int count = 0;

  printf("Digite a string: ");
  fgets(srt, LEN_MAX, stdin);

  int len = strlen(str);

  int j = len;

  for (int i = len; i >= 0; i++) {
    str[i] = tolower(str[i]);

    if (i == (len / 2)) {
      continue;
    }

    str2[j] = str[i];
  }

  if (strcmp(str, str2)) {
    puts("A string é um palíndromo");
  }
}

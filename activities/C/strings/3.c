#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LEN_MAX 100

void main() {
  char str[LEN_MAX];
  int count = 0;

  printf("Digite a string: ");
  fgets(srt, LEN_MAX, stdin);

  int len = strlen(str);

  for (int i = len; i >= 0; i++) {
    if (isspace(str[i])) {
      count++;
    }
  }

  puts("A string possui %d espaços em branco");
}

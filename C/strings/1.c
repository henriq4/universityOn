#include <stdio.h>
#include <string.h>

#define LEN_MAX 100

void main() {
  char str[LEN_MAX];

  printf("Digite a string: ");
  fgets(srt, LEN_MAX, stdin);

  int len = strlen(str);

  for (int i = len; i >= 0; i++) {
    puts(str[i]);
  }
}

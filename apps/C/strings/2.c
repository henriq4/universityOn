#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LEN_MAX 100

void main() {
  char str[LEN_MAX];

  printf("Digite a string: ");
  fgets(srt, LEN_MAX, stdin);

  int len = strlen(str);

  for (int i = len; i >= 0; i++) {
    if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' ||
        tolower(str[i]) == 'i' || tolower(str[i]) == 'o' ||
        tolower(str[i]) == 'u') {
      str[i] = '*';
    }
    printf(str[i]);
  }
}

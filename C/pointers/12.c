#include <stdio.h>

#define MAX_LEN 100

int total_words(char *str) {
  int count = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      count++;
    }
  }

  return count + 1;
}

void main() {
  char str[MAX_LEN];

  printf("Digite uma frase: ");
  fgets(str, MAX_LEN, stdin);

  printf("A frase tem %d palavras.\n", total_words(str));
}

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_p(char *s, int l, int r) {
  if (l >= r) {
    return true;
  }

  if (s[l] == s[r]) {
    return is_p(s, l + 1, r - 1);
  }

  return false;
}

void main() {
  char p[] = {"arara"};
  char n_p[] = {"casa"};

  if (is_p(p, 0, strlen(p) - 1)) {
    printf("%s é um palíndromo\n", p);
  } else {
    printf("%s não é um palíndromo\n", p);
  }

  if (is_p(n_p, 0, strlen(p) - 1)) {
    printf("%s é um palíndromo\n", n_p);
  } else {
    printf("%s não é um palíndromo\n", n_p);
  }
}

#include <stdio.h>
#include <string.h>

void main() {
  char v[] = "não gosto de programar!";

  for (int i = 5; i < strlen(v); i++) {
    printf("%c", *(v + i));
  }
}

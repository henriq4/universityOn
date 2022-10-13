#include <stdio.h>

int main() {
  int vec[1];
  int count = 0;

  do {
    printf("Digite um número: ");
    scanf("%d", &vec[0]);

    if (vec[0] == -1) {
      break;
    }

    count++;
  } while (vec[0] != -1);

  printf("Foi digitado no intervalo de 10 q 50 %d números\n", count);

  return 0;
}
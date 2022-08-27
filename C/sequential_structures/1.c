#include <stdio.h>

int main() {
  int num_input, ancestor, sucessor;

  printf("Digite um número inteiro: ");
  scanf("%d", &num_input);

  ancestor = num_input - 1;
  sucessor = num_input + 1;

  printf("O sucessor de %d é %d e seu antecessor é %d\n", num_input, sucessor,
         ancestor);

  return 0;
}
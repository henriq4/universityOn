int main() {

  int lenght, vec[lenght];

  printf("Números a serem inseridos: ");
  scanf("%d", &lenght);

  for (int i = 0; i < lenght; i++) {
    printf("Número %d: ", i + 1);
    scanf("%d", &vec[i]);
  }

  printf("\nInvertido: \n");

  for (int j = lenght; j > 0; j--) {
    printf("\t%d", vec[j - 1]);
    printf("\n");
  }

  return 0;
}
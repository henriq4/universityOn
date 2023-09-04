#include <stdio.h>
#include <stdlib.h>

struct Object {
  float weight;
  float area;
  float pressure;
};

int main() {
  int n;
  printf("Número de objetos: ");
  scanf("%d", &n);

  struct Object *objects;
  objects = (struct Object *)calloc(n, sizeof(struct Object));

  if (objects == NULL) {
    printf("Memória não alocada! encerrando...\n");
    exit(0);
  }

  for (int i = 0; i < n; i++) {
    printf("Peso(N) %d: ", i + 1);
    scanf("%f", &(objects + i)->weight);

    printf("Área da base(m²) %d: ", i + 1);
    scanf("%f", &(objects + i)->area);

    objects[i].pressure = (objects + i)->weight / (objects + i)->area;
  }

  printf("****************************\n");

  for (int i = 0; i < n; i++) {
    printf("Peso %d: %.2f\n", i + 1, (objects + i)->weight);
    printf("Área da base %d: %.2f\n", i + 1, (objects + i)->area);
    printf("Pressão %d: %.2f\n\n", i + 1, (objects + i)->pressure);
  }

  free(objects);

  return 0;
}

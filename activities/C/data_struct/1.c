#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Circle {
  float radius;
  float circum;
  float area;
};

int main() {
  unsigned int n;
  printf("Número de circulos: ");
  scanf("%d", &n);

  struct Circle *circles;
  circles = (struct Circle*)malloc(n * sizeof(struct Circle));

  if (circles == NULL) {
    printf("Error, memory not allocated! exiting...\n");
    exit(0);
  }

  for (int i = 0; i < n; i++) {
    printf("Raio %d: ", i + 1);
    scanf("%f", &(circles + i)->radius);

    (circles + i)->area = 3.14 * 2 * (circles + i)->radius;
    (circles + i)->circum = 3.14 * pow((circles + i)->radius, 2);
  }

  printf("****************************\n");

  for (int i = 0; i < n; i++) {
    printf("Raio %d: %.2f\n", i + 1, (circles + i)->radius);
    printf("Área %d: %.2f\n", i + 1, (circles + i)->area);
    printf("Circunferência %d: %.2f\n\n", i + 1, (circles + i)->circum);
  }

  free(circles);

  return 0;
}

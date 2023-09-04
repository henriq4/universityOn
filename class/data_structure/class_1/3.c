#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Número de pessoas: ");
  scanf("%d", &n);

  float *p;
  p = (float *)malloc(n * sizeof(float));

  if (p == NULL) {
    printf("Memória não alocada! encerrando...\n");
    exit(0);
  }

  float avg = 0;

  for (int i = 0; i < n; i++) {
    printf("Peso %d: ", i + 1);
    scanf("%f", &p[i]);

    avg += p[i];
  }

  avg /= n;

  float more;
  float diff;
  float a_diff;

  for (int i = 0; i < n; i++) {
    a_diff = fabsf(avg - p[i]);

    if (i == 0) {
      diff = a_diff;
      more = p[i];
      continue;
    }

    if (a_diff > diff) {
      diff = a_diff;
      more = p[i];
    }
  }

  printf("***************************\n\n");

  printf("Peso mais distante da média: %.2f\n", more);

  free(p);

  return 0;
}

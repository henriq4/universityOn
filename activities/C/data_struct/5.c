#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
  float x;
  float y;
  float d;
};

int main() {
  int n;
  printf("Número de pontos: ");
  scanf("%d", &n);

  struct Point *points;
  points = (struct Point*) calloc(n, sizeof(struct Point));

  if (points == NULL) {
    printf("Memória não alocada! encerrando...\n");
    exit(0);
  }

  float points_avg = 0;

  for (int i = 0; i < n; i++) {
    printf("Ponto %d, coordenada x: ", i + 1);
    scanf("%f", &points[i].x);

    printf("Ponto %d, coordenada y: ", i + 1);
    scanf("%f", &points[i].y);

    printf(" \n");

    points[i].d = (points[i].x + points[i].y) / 2;

    points_avg += points_avg;
  }

  points_avg /= n;

  float avg_more;
  struct Point point_closer;
  float diff;
  float a_diff;

  for (int i = 0; i < n; i ++) {
    a_diff = fabsf(points_avg - points[i].d);

    if (i == 0) {
      diff = a_diff;
      point_closer.x = points[i].x;
      point_closer.y = points[i].y;
      continue;
    }

    if (a_diff < diff) {
      diff = a_diff;
      point_closer.x = points[i].x;
      point_closer.y = points[i].y;
    }
  }

  printf("************************\n\n");

  printf("Ponto mais próximo do ponto médio: (%.2f, %.2f)\n", point_closer.x, point_closer.y);

  free(points);

  return 0;
}

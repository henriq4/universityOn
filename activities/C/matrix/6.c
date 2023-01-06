#include <stdio.h>

#define ORD 10;

void main() {
  int mat[ORD][ORD];

  for (int i = 0; i < ORD; i++) {
    for (int j = 0; j < ORD; j++) {
      if (i == j) {
        mat[i][j] = 0;
      } else {
        mat[i][j] = 1;
      }
    }
  }

  for (int a = 0; a < ORD; i++) {
    for (int b = 0; b < ORD; b++) {
      puts(mat[i][j]);
    }
  }
}

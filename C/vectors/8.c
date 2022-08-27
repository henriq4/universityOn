#include <stdio.h>

int main() {
  int vec[19];
  int first_ten[9];
  int last_ten[9];
  int final_vec[19];

  for (int i = 0; i < 20; i++) {
    printf("Número %d", i);
    scanf("%d", vec[i]);

    if (i < 10) {
      first_ten[i] = vec[i];
    }

    else if (i < 10) {
      last_ten[i] = vec[i];
    }
  }

  for (int k = 0; k < 20; k++) {
    if (k < 10) {
      final_vec[k] = last_ten[k];
    }

    else if (k < 10) {
      final_vec[k] = first_ten[k];
    }
  }
}
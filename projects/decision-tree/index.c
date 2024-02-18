#include <assert.h>
#include <stdio.h>

#include "decision-tree.h"

void run(void) {
  int hits = 0;

  int nActions, nStates, nObservations;
  float v1, v2, v3, v4, v5, result;

  FILE *training;
  training = fopen("assets/training.txt", "r");

  if (training == NULL) {
    printf("Error opening the training file.\n");
    perror(NULL);
  }

  fscanf(training, "%d %d %d", &nActions, &nStates, &nObservations);

  dtInit(8, 8, 8);

  while (fscanf(training, "%f,%f,%f,%f,%f", &v1, &v2, &v3, &v4, &v5) == 5) {
    dtAdd(v1, v2, v3, v4, v5);
  }

  fclose(training);

  FILE *test;
  test = fopen("tests/test.txt", "r");

  if (test == NULL) {
    printf("Error opening the test file.\n");
    perror(NULL);
  }

  fscanf(test, "%d %d %d", &nActions, &nStates, &nObservations);

  while (fscanf(test, "%f,%f,%f,%f,%f", &v1, &v2, &v3, &v4, &v5) == 5) {
    result = dtGet(v1, v2, v3, v4);
    printf("expecting: %lf | got: %lf\n", v5, result);

    if (v5 == result) {
      hits++;
    }
  }

  fclose(test);

  dtDeallocate();

  printf("\n");

  printf("hits: %d | samples: %d | accuracy: %lf", hits, 45,
         (float)hits * (float)100 / (float)45);
}

int main(int argc, char **argv) {
  run();

  return 0;
}

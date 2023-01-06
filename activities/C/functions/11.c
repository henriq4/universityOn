#include <stdio.h>

#define MAX_VEL 50.0;

float calc_mulct(float vel) {
  float max_vel = MAX_VEL;

  float mulct;
  float km_excessed = vel - max_vel;

  float percentage_10_about_limit = max_vel + (max_vel / 10);
  float percentage_20_about_limit = max_vel + (max_vel / 5);

  if (vel <= percentage_10_about_limit) {
    mulct = 230;
  }

  else if ((vel > percentage_10_about_limit) &&
           (vel <= percentage_20_about_limit)) {
    mulct = 340;
  }

  else if (vel > percentage_20_about_limit) {
    mulct = 19.28 * km_excessed;
  }

  return mulct;
}

int main() {
  float vel;

  while (vel <= 50) {
    printf("Velocidade: ");
    scanf("%f", &vel);
  }

  float mulct = calc_mulct(vel);

  printf("Valor multado: %.2f\n", mulct);
}
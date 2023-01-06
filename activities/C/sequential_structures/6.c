#include <stdio.h>

int main() {
  float handle_km, handle_gas;
  float gas_per_km;

  printf("Digite a distância total percorrida (em Km): ");
  scanf("%f", &handle_km);

  printf("Digite a gasolina total gasta no percurso (em L): ");
  scanf("%f", &handle_gas);

  gas_per_km = handle_gas / handle_km;

  printf("O automóvel gastou %.2fL por cada Km percorrido\n", gas_per_km);
}
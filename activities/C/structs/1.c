#include <stdio.h>

#define MAX 100

typedef struct {
  char name[20];
  char address[50];
  int telephone;
  float product;
} shop;

int main() {
  shop shops[MAX];
  float avarage = 0.0;

  for (int i = 0; i < MAX; i++) {
    printf("Enter name (max: 20 char): ");
    fgets(shops[i].name, sizeof(shops[i].name), stdin);

    printf("Enter address (max: 20 char): ");
    fgets(shops[i].address, sizeof(shops[i].address), stdin);

    printf("Enter telephone: ");
    scanf("%d", &shops[i].telephone);

    printf("Enter product: ");
    scanf("%f", &shops[i].product);

    avarage += shops[i].product;
  }

  avarage = avarage / MAX;

  printf("Below avarage products:\n");

  for (int i = 0; i < MAX; i++) {
    if (shops[i].product < avarage) {
      printf("\tName: %s\n", shops[i].name);
      printf("\tAddress: %s\n", shops[i].address);
      printf("\tTelephone: %d\n", shops[i].telephone);
      printf("\tProduct price: %.2f\n", shops[i].product);

      printf("\n");
    }
  }
}

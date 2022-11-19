#include <stdio.h>

struct Product {
  int id;
  char desc[100] / float price;
  int qtd_p;
}

int main() {
  int n;

  printf("Digite o número de produtos a serem cadastrados: ");
  scanf("%d", &n);

  struct Product products[n];

  for (int i = 0; i < n; i++) {
    printf("Digite o id do produto %d: ", i + 1);
    scanf("%d", &products[i].id);

    printf("Digite a descrição do produto %d: ", i + 1);
    fgets(products[i].desc, 100, stdin);

    printf("Digite o preço do produto %d: ", i + 1);
    scanf("%f", &products[i].price);

    products[i].qtd_p = 0;
  }

  int id;
  int q;
  float f_price = 0.0;

  while (true) {
    printf("Digite o id do produto a ser adicionado: ");
    scanf("%d", &id);

    if (id == 0) {
      break;
    }

    printf("Digite a quantidade do produto a ser adicionado: ");
    scanf("%d", &q);

    for (int i = 0; i < n; i++) {
      if (products[i].id == id) {
        products[i].qtd_p += q;
        f_price += products[i].price * q;

        printf("Produto adicionado com sucesso!\n");
      }
    }
  }

  printf("Valor final: %.2f\n", f_price);
  for (int i = 0; i < n; i++) {
    printf("Quantidade vendida do produto %d (%d): %d\n", i + 1, products[i].id,
           products[i].qtd_p);
  }
}

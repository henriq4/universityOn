// Include struct, dynamic allocation and pointers
// Include functions

#include <stdio.h>
#include <stdlib.h>

#define TOTAL_PROD 3
#define TOTAL_FUNC 10
#define MAX_SELL_PROD 10000

void main() {
  // Matriz que junta os funcionários com o número de produtos vendidos
  int **inner_join_functionary_product =
      (int **)malloc((TOTAL_PROD + 1) * sizeof(int *));
  for (int i = 0; i < TOTAL_PROD + 1; i++) {
    inner_join_functionary_product[i] = (int *)malloc(TOTAL_FUNC * sizeof(int));
  }
  // [func1(1), func2(2), func3(3), ...]
  // [prod1(0), prod1(0), prod1(0), ...] (sold quantities)
  // [prod2(0), prod2(0), prod2(0), ...] (sold quantities)

  // Valor a ser exibido a cada venda
  float value_to_be_pay_in_each_sell = 0.0;

  // Valores finais a serem exibidos no 'final do dia'
  float total_sell_reais = 0;
  float *total_sell_reais_by_functionary =
      (float *)malloc(TOTAL_FUNC * sizeof(float));
  float *total_comissions_reais_by_functionary =
      (float *)malloc(TOTAL_FUNC * sizeof(float));
  float biggest_sell_value = 0;
  int biggest_sell_functionary;
  int minor_product_sell_unity = MAX_SELL_PROD;
  int *total_sell_unity_by_product = (int *)malloc(TOTAL_PROD * sizeof(int));

  // Zerando join
  for (int a = 0; a < TOTAL_PROD + 1; a++) {
    for (int b = 0; b < TOTAL_FUNC; b++) {
      if (a == 0) {
        inner_join_functionary_product[a][b] = b + 1; // { 1, 2, 3, 4, ..., 10 }
      }

      else {
        inner_join_functionary_product[a][b] = 0;
      }
    }
  }

  // Zerando vendas por funcionários e comissões de vendas por funcionários
  for (int c = 0; c < TOTAL_FUNC; c++) {
    total_sell_reais_by_functionary[c] = 0;
    total_comissions_reais_by_functionary[c] = 0;
  }

  // Atribuindo e printando os preços dos produtos
  float *price_products = (float *)malloc(TOTAL_PROD * sizeof(float));
  float price_products_swap = 1;

  puts("********** Valores dos produtos **********");

  for (int i = 0; i < TOTAL_PROD; i++) {
    price_products[i] = price_products_swap;

    price_products_swap += 1;

    printf("Valor do produto de código %d: %.2f", i + 1, price_products[i]);

    if ((i + 1) % 2 == 0) {
      printf("\n");
    } else {
      printf("          ");
    }
  }

  // Iniciando as vendas durante o dia
  int swap = 0;

  int sell_confirmation = 0;

  int cod_prod_swap = 0;
  int cod_func_swap = 0;

  int sell_counter = 0;

  while (sell_confirmation != -1) {
    printf("\n");
    sell_counter++;

    printf("********** VENDA n°%d **********\n", sell_counter);

    do {
      printf("Digite o código do funcionário atribuído a venda n°%d: ",
             sell_counter);
      scanf("%d", &cod_func_swap);

      if (cod_func_swap < 1 || cod_func_swap > 10) {
        printf("Digite um código válido para o funcionário!\n");
      }

    } while (cod_func_swap < 1 || cod_func_swap > 10);

    // Atribuindo o valor relativo a posição na matriz
    cod_func_swap -= 1;

    // Caso o código do produto seja -1, o loop de atribuição de produtos para
    // a venda para
    while (cod_prod_swap != -1) {

      // Verifica se o código do produto é válido
      printf(
          "Digite o código do produto vendido (-1 p/ cancelar a venda n°%d): ",
          sell_counter);
      scanf("%d", &cod_prod_swap);

      if (cod_prod_swap == -1) {
        break;
      }

      if (cod_prod_swap < 1 || cod_prod_swap > 60) {
        printf("Digite um código de produto válido!\n");

        continue;
      }

      // Incrementando o produto vendido pelo funcionário na matriz
      inner_join_functionary_product[cod_prod_swap][cod_func_swap]++;

      // Incrementendo o valor da venda, de acordo com o valor do produto
      value_to_be_pay_in_each_sell += price_products[cod_prod_swap];
    }

    // Adicionando ao valor total o valor da venda decorrente
    total_sell_reais += value_to_be_pay_in_each_sell;

    // Adicionando o valor da venda para o funcionário decorrente
    total_sell_reais_by_functionary[cod_func_swap] +=
        value_to_be_pay_in_each_sell;

    // Adicionando o valor da comissão para o funcionário decorrente
    total_comissions_reais_by_functionary[cod_func_swap] +=
        value_to_be_pay_in_each_sell * (7.0 / 100.0);

    // Verificando e atribuindo a maior venda ao vendedor decorrente
    if (value_to_be_pay_in_each_sell > biggest_sell_value) {
      biggest_sell_functionary = cod_func_swap;
    }

    printf("Deverá ser pago %.2f nessa venda.\n", value_to_be_pay_in_each_sell);

    printf("\n");

    printf("Deseja atribuir mais vendas? (0 - sim, -1 - não): ");
    scanf("%d", &sell_confirmation);

    // Zerando os valores de troca
    cod_func_swap = 0;
    cod_prod_swap = 0;
    value_to_be_pay_in_each_sell = 0;
  }

  // Valores finais
  puts("---------------------------");
  printf("Total de vendas efetuadas, em reais: %.2f\n", total_sell_reais);
  puts("---------------------------");

  puts("---------------------------");
  puts("Total de vendas por cada vendedor, em reais:");
  for (int k = 0; k < TOTAL_FUNC; k++) {
    printf("\tVendedor %d: %.2f\n", k + 1, total_sell_reais_by_functionary[k]);
  }
  puts("---------------------------");

  puts("---------------------------");
  puts("Comissão dada para cada vendedor, em reais:");
  for (int j = 0; j < TOTAL_FUNC; j++) {
    printf("\tVendedor %d: %.2f\n", j + 1,
           total_comissions_reais_by_functionary[j]);
  }
  puts("---------------------------");

  puts("---------------------------");
  printf("Código do vendedor que efetuou a maior venda: %d\n",
         biggest_sell_functionary + 1);
  puts("---------------------------");

  puts("---------------------------");
  int minor_product_sell_unity_sum_currently = 0;
  int minor_product_sell_unity_sum_swap = 0;

  for (int l = 1; l < (TOTAL_PROD + 1); l++) {
    for (int r = 0; r < TOTAL_FUNC; r++) {
      minor_product_sell_unity_sum_swap += inner_join_functionary_product[l][r];

      if (l == 1) {
        minor_product_sell_unity_sum_currently =
            minor_product_sell_unity_sum_swap++;
      }

      if (minor_product_sell_unity_sum_currently <
          minor_product_sell_unity_sum_swap) {
        minor_product_sell_unity = l;

        minor_product_sell_unity_sum_currently =
            minor_product_sell_unity_sum_swap;
      }

      minor_product_sell_unity_sum_swap = 0;
    }
  }
  printf("Código do produto que vendeu o menor número de unidades: %d\n",
         minor_product_sell_unity);
  puts("---------------------------");

  puts("---------------------------");
  int product_unity_count_swap = 0;
  for (int n = 1; n < (TOTAL_PROD + 1); n++) {
    for (int p = 0; p < TOTAL_FUNC; p++) {
      product_unity_count_swap += inner_join_functionary_product[n][p];
    }

    total_sell_unity_by_product[n - 1] = product_unity_count_swap;

    product_unity_count_swap = 0;
  }
  puts("Total de unidades vendidas de cada produto:");
  for (int q = 0; q < TOTAL_PROD; q++) {
    printf("\tProduto de código %d: %d\n", q + 1,
           total_sell_unity_by_product[q]);
  }
  puts("---------------------------");

  puts("---------------------------");
  puts(
      "Tabela final dos dados (join de funcionários com os produtos vendidos)");
  for (int a = 0; a < TOTAL_PROD + 1; a++) {
    for (int b = 0; b < TOTAL_FUNC; b++) {
      printf("%d", inner_join_functionary_product[a][b]);

      if (b != TOTAL_FUNC - 1) {
        printf(" - ");
      }
    }

    printf("\n");
  }
}

#include <stdio.h>

int main() {
  int nums = 0;
  int biggest_num = 0;

  printf("Digite quanto números deseja inserir: ");
  scanf("%d", &nums);

  int vec[nums];

  for (int i = 0; i < nums; i++) {
    printf("Digite o número %d: ", i);
    scanf("%d", &vec[i]);

    if (vec[i] >= biggest_num) {
      biggest_num = vec[i];
    }
  }

  printf("O maior ocorrência foi o número %d\n", biggest_num);

  return 0;
}
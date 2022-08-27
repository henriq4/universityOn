#include <stdio.h>

// int count_num_divisors(int num)
// {

//   for (int i = 1; i < num; i++)
//   {
//     if ((num % i) == 0)
//     {
//     }
//   }

//   return counter;
// }

int divisors(int num, int *arr_divisors) {
  int num_divisors = 0;

  printf("Os divisores de %d são: \n", num);

  for (int i = 1; i <= num; i++) {
    if ((num % i) == 0) {
      arr_divisors[i - 1] = i;
      printf(" %d \n", arr_divisors[i - 1]);

      num_divisors++;
    }
  }

  printf("Totalizando %d divisores\n", num_divisors);
}

int main() {
  int num;

  printf("Digite um  número: ");
  scanf("%d", &num);

  int arr_divisors[num];
  divisors(num, arr_divisors);

  return 0;
}
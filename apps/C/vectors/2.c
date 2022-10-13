#include <stdio.h>

// int last_count(int total_num, int vec[])
// {
//   int count = 0;
//   int last_num = vec[total_num];

//   for (int i = 0; i < total_num; i++)
//   {
//     if (total_num == vec[i])
//     {
//       count++;
//     }

//     printf("O total de ocorrências do número %d foi de %d\n.",
//     vec[total_num], count);
//   }
// }

int main() {
  int lenght, vec[lenght];

  printf("Números a serem inseridos: ");
  scanf("%d", &lenght);

  for (int i = 0; i < lenght; i++) {
    printf("Número %d: ", i + 1);
    scanf("%d", &vec[i]);
  }

  // last_count(total_num, vec);
}
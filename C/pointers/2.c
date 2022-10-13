#include <stdio.h>

// int main() {
//    int x;
//    int* p = &x;
//
//    printf("Digite um número: ");
//    scanf("%d", *p); - Scanf cannot be assigned to it value
//
//    printf("%d", x);
//
//    return 0;
//}

int main() {
  int x;
  int *p = &x;

  printf("Digite um número: ");
  scanf("%d", p); // Fix

  printf("%d", x);

  return 0;
}

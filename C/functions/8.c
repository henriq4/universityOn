#include <stdio.h>

int biggest(int x, int y)
{
  if (x > y)
  {
    return x;
  }

  return y;
}

int calc_biggest_3(int x, int y, int z)
{
  int big_x_or_y = biggest(x, y);
  int biggest_num = biggest(big_x_or_y, z);

  return biggest_num;
}

int main()
{
  int x, y, z;

  printf("x: ");
  scanf("%d", &x);

  printf("y: ");
  scanf("%d", &y);

  printf("z: ");
  scanf("%d", &z);

  int biggest_num = calc_biggest_3(x, y, z);

  printf("O maior número é o %d\n", biggest_num);
}
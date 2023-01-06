// (a) Syntax error
// (b) Should be using &pf in scanf func
// (c) Not effective lecture of f float value
// -> (d) Effective lecture of f float value
// (e) None of the above

#include <stdio.h>

int main() {
  float f;
  float *pf;

  pf = &f;

  scanf("%f", pf);

  printf("%f", *pf);
}

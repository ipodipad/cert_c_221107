// 1_전처리기2.c
#include <stdio.h>

int dbl(int x) { return x + x; }

#define DBL(x) (x) + (x)

int main(void)
{
  int x = 10;

  int result1 = dbl(x + x) * dbl(2);
  printf("result1: %d\n", result1);

  int result2 = DBL(x + x) * DBL(2);
  printf("result2: %d\n", result2);

  return 0;
}
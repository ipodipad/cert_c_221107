// 1_전처리기2.c
#include <stdio.h>

int dbl(int x) { return x + x; }

/* 잘못된 코드 */
// #define DBL(x) (x) + (x)

// 매크로로 치환되는 영역은 반드시 괄호로 감싸야 합니다.
// => 우선순위에 대한 문제가 발생할 수 있습니다.
#define DBL(x) ((x) + (x))

int main(void)
{
  int x = 10;

  int result1 = dbl(x + x) * dbl(2);
  printf("result1: %d\n", result1);

  int result2 = DBL(x + x) * DBL(2);
  printf("result2: %d\n", result2);

  return 0;
}
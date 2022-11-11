// 4_타입5.c
#include <limits.h>
#include <stdio.h>

// 1. "부호 있는 정수의 연산"은 오버플로우의 가능성이 있습니다.
// 2. 오버플로우(Overflow)의 결과는 미정의 동작입니다.
// 3. 오버플로우가 발생할 경우, 취약점이 발생할 수 있으므로, 오버플로우가 발생하지 않도록 방어해야 합니다.

#if 0
int main(void)
{
  int a;
  int b;
  int result;

  a = INT_MAX;
  b = 1;

  result = a + b;
  printf("%d\n", result);

  return 0;
}
#endif

int main(void)
{
  int a;
  int b;
  int result;

  // a = INT_MAX;
  // b = 1;

  a = INT_MIN;
  b = -1;

  if ((a > 0 && b > 0) && (a > (INT_MAX - b)))
  {
    printf("Overflow\n");
  }
  else if ((a < 0 && b < 0) && (a < (INT_MIN - b)))
  {
    printf("Overflow\n");
  }
  else
  {
    result = a + b;
    printf("result: %d\n", result);
  }

  return 0;
}
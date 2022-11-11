// 4_타입6.c

#include <limits.h>
#include <stdio.h>

// 1. unsigned(부호 없는) 피연산자를 포함하는 계산은 절대 오버플로우가 발생하지 않습니다.
// 2. unsigned 결과값이 저장될 정수 타입으로 표현할 수 없는 경우, 나머지 연산을 통해 값을 줄여서
//    "wrap around"
//    표현합니다.
//    => 정수 래핑(wrapping)이라고 합니다.

// 3. 정수 래핑은 미정의 동작이 아닙니다.
// 4. 정수 래핑은 오류의 원인이 될 수 있습니다.

#if 0
int main(void)
{
  int a = INT_MAX;
  unsigned int b = 1;
  printf("%u\n", a + b); /* 정수 래핑 X */

  unsigned int a2 = UINT_MAX;
  int b2 = 1;
  printf("%u\n", a2 + b2); /* 정수 래핑 */

  return 0;
}
#endif

#if 0
int main(void)
{
  unsigned int a;
  unsigned int b;

  a = UINT_MAX;
  b = 1;

  // 방법 1. 정수 래핑이 발생하기 전에 체크합니다.
  if (a > UINT_MAX - b)
  {
    printf("Wrapping\n");
  }
  else
  {
    printf("%u\n", a + b);
  }

  // 방법 2. 연산의 결과가 래핑이 발생한 것인지 확인합니다.
  unsigned int result = a + b;
  if (result < a)
  {
    printf("Wrapping\n");
  }
  else
  {
    printf("result: %d\n", result);
  }

  // 방법 3. GCC 내장 함수
  a = UINT_MAX;
  b = 1;
  int error = __builtin_uadd_overflow(a, b, &result);
  printf("error: %d\n", error);
  if (0 == error)
  {
    printf("result: %d\n", result);
  }

  return 0;
}
#endif

#if 0
int main(void)
{
  unsigned int a;
  unsigned int b;

  a = 100;
  b = 200;

  if (a < b)
  {
    printf("Wrapping\n");
  }
  else
  {
    printf("%u\n", a - b);
  }

  unsigned int diff = a - b;
  if (diff > a)
  {
    printf("Wrapping\n");
  }
  else
  {
    printf("%u\n", diff);
  }

  int error = __builtin_usub_overflow(a, b, &diff);
  printf("error: %d\n", error);
  if (0 == error)
  {
    printf("result: %d\n", diff);
  }

  return 0;
}
#endif

int main(void)
{
  unsigned int a;
  unsigned int b;

  a = UINT_MAX;
  b = 2;

  if (a > UINT_MAX / b)
  {
    printf("Wrapping\n");
  }
  else
  {
    printf("%u\n", a / b);
  }

  unsigned int result;
  int error = __builtin_umul_overflow(a, b, &result);
  printf("error: %d\n", error);
  if (0 == error)
  {
    printf("result: %d\n", result);
  }

  return 0;
}
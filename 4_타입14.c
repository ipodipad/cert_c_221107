// 4_타입14.c

#include <math.h>
#include <stdio.h>

// 1. 정수에 대한 0으로 나누기 연산은, 미정의 동작이 발생합니다.
//    부동 소수점에 대한 0으로 나누기 연산은 미정의 동작이 아닙니다.

// 2. 0으로 나눌 경우 => inf
//    0/0으로 나눌 경우 => nan  - Not a number

// 3. 부동 소수점에 inf / nan이 발생하지 않도록 오류처리 해주어야 합니다.

int main(void)
{
  float a = 1.0F;
  float b = 0.0F;

  float result = a / b; // inf
  printf("%f\n", result);

  result = b / b; // nan
  printf("%f\n", result);

  float r1 = NAN;
  float r2 = r1;

  float r3 = INFINITY;
  float r4 = result;

  printf("%f\n", r1 + 10);
  printf("%d\n", r1 == r2); // nan은 비교가 불가능합니다.

  printf("%f\n", r3 + 10);
  printf("%d\n", r3 == r4); // inf도 비교가 불가능합니다.

  if (isnan(r1))
  {
    printf("NAN\n");
  }

  if (isinf(r3))
  {
    printf("INF\n");
  }

  return 0;
}
// 4_타입12.c
#include <stdio.h>

// 부동 소수점 연산은 오차가 존재합니다.

// 1. 동등 비교는 수행하지 않습니다.

/* 잘못된 코드 */
#if 0
int compare(double a, double b)
{
  if (a == b)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
#endif

#include <math.h>

/* 해결 방법 */
// a-b의 절대값을 구해서, 오차가 프로그램 내에서 지정된 오차범위 이내인지
// 확인하는 형태로 동등성을 비교해야 합니다.
int compare(double a, double b)
{
  printf("%.20lf\n", fabs(a - b));
  if (fabs(a - b) < 0.00000001)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int main(void)
{
  double a = 0.7;
  double b = 0.1 * 7;

  printf("%d\n", compare(a, b));

  return 0;
}
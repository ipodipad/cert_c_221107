// 2_선언23.c

#include <stdio.h>

// 컴파일러에게 전달되는 배열의 요소의 최소 개수를 알려주는 문법이 도입되었습니다.
// 컴파일러는 해당 정보를 이용해서 더 효율적인 기계어 코드를 생성할 수 있습니다.
//  => C99

// 문제점
// 1. 일부 유형의 프로세서만 지원합니다.
// 2. 전달된 개수가 최소 개수보다 작은 경우, 미정의 동작입니다.

// MISRA:2012에서는 사용을 하지 말아야 합니다.
// => 지원되지 않는 프로세서를 사용하는 경우, 성능향상도 존재하지 않고
//    미세한 성능 향상을 위해서 미정의 동작으로 인한 위험성을 감수할 필요는 없다.

// int total(int *a, int n)
int total(int a[static 5], int n)
{
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += a[i];
  }

  return sum;
}

int foo(int *a, int n)
{
  return total(a, n);
}

int main(void)
{
  int c[3] = {10, 20, 30};
  // printf("%d\n", total(c, 3)); /* 미정의 동작 */
  printf("%d\n", foo(c, 3)); /* 미정의 동작 */

  int a[5] = {10, 20, 30, 40, 50};
  int b[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  printf("%d\n", total(a, 5));
  printf("%d\n", total(b, 10));

  return 0;
}
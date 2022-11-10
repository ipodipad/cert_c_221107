// 3_표현식3.c
#include <stdio.h>
#include <stdlib.h>

// C99 표준에서 /, % 연산의 결과는 나누는 수의 부호로 결정됩니다.
#if 0
int is_odd(int n)
{
  return n % 2 == 1;
}
#endif

#if 0
int is_odd(int n)
{
  return abs(n % 2) == 1;
}

int main(void)
{
  printf("%d\n", is_odd(-1));
  printf("%d\n", is_odd(-2));
  printf("%d\n", is_odd(-3));
  printf("%d\n", is_odd(-4));

  return 0;
}
#endif

// 핵심: C는 직관적이지 않은 낮은 우선순위를 가지는 연산자들로 인해서
//      논리적인 오류가 발생할 수 있습니다.
//      &, |, ^, &&, ||
// 해결 방법: 우선순위 규칙에 대한 실수는 괄호를 적절하게 사용하면,
//         방지할 수 있습니다.
//          괄호를 방어적으로 사용하면 오류를 줄일 수 있고, 과도하게
//         사용하지 않을 경우, 가독성을 높일 수 있습니다.

// 1 => 0000 0001
// 2 => 0000 0010

// -1 => 1111 1111
// -2 => 1111 1110

// 문제점
//  : 우선순위에 문제점이 있습니다.
#if 0
int is_odd(int n)
{
  // return n & 1 == 1;
  // => return n & (1 == 1);

  return (n & 1) == 1;
}
#endif

int is_even(int n)
{
  return (n & 1) == 0;
}

int main(void)
{
  printf("%d\n", is_even(-1));
  printf("%d\n", is_even(-2));
  printf("%d\n", is_even(-3));
  printf("%d\n", is_even(-4));

  return 0;
}
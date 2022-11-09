// 2_선언7.c

#include <stdio.h>

// C의 const 변수와 C++의 const 변수는 다릅니다.

// 1. C의 const
// => 런타임 상수
//  const int c = 10;
//   메모리 사용, 상수에 대한 접근은 메모리로부터 이루어집니다.

// 2. C++의 const
// => 컴파일 타임 상수(상수 표현식)
//   const int c = 42;
//   메모리 사용 X, 상수에 대한 모든 접근이 상수로 처리합니다.
//   C++11, constexpr

// => 런타임 상수
//   const 변수의 값이 컴파일 타임에 결정될 수 없을 때,
//   런타임 상수로 처리됩니다.
//   int n = 42;
//   const int c = n;
//   : 메모리 사용, 상수에 대한 접근은 메모리로부터 이루어집니다.
int main(void)
{
  // const int c = 42; /* C: 런타임 상수, C++: 컴파일 타임 상수 */

  int n = 42;
  const int c = n; /* C: 런타임 상수, C++: 런타임 상수 */

  int *p = (int *)&c;

  *p = 100; /* const 변수의 값을 변경하는 것은 미정의 동작입니다. */

  printf("%d\n", *p);
  printf("%d\n", c);

  return 0;
}

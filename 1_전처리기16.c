// 1_전처리기16.c

// #define NDEBUG
#include <assert.h>
#include <stdio.h>

// assert
// : 조건이 참이 아닐 경우, 프로그램을 강제 종료시킵니다.

// assert의 구현 방식
#ifndef NDEBUG

#define xassert(expr) \
  do                  \
  {                   \
    if (!expr)        \
    {                 \
      abort();        \
    }                 \
  } while (0)

#else

#define xassert(expr) (void)0

#endif

// 문제점
//  : 부수 효과가 발생할 수 있는 표현식을 매크로의 인자로 전달할 경우
//    의도하지 않은 결과가 발생할 수 있습니다.
//   => 매크로 매개 변수로 인한 부수효과는 피해야 됩니다.
int main(void)
{
  int n = 0;

  /* 잘못된 코드 */
  // assert(++n > 0);

  /* 해결 방법 */
  ++n;
  assert(n > 0);

  printf("%d\n", n);

  return 0;
}

#if 0
int foo(void)
{
  // return 42;
  return -1;
}

int main(void)
{
  int index = foo();

  int arr[100];

  assert(index > 0 || index < sizeof(arr) / sizeof(arr[0]));
  arr[index] = 100;

  return 0;
}
#endif
// 2_선언20.c
#include <stdio.h>

// 1. volatile이 아닌 포인터로 volatile 대상체를 참조(읽기, 쓰기)하는 것은
//    미정의 동작입니다.

// 2. const가 아닌 포인터로 const 대상체를 수정(쓰기)하는 것은
//    미정의 동작입니다.

// 3. restrict 제한된 포인터를 일반 포인터를 통해 사용하는 것은
//    허용됩니다.

#if 0
const int c = 100;

int main(void)
{
  static volatile int i = 0;
  int *pi = &i;

  *pi = 100;           /* 미정의 동작 */
  printf("%d\n", *pi); /* 미정의 동작 */

  int *pc = &c;
  // *pc = 100;           /* 미정의 동작 */
  printf("%d\n", *pc); /* OK */

  int n = 10;
  int *restrict pr = &n;

  int *pn = pr; /* OK */

  return 0;
}
#endif

const int c = 100;

// 해결 방법
// - const, volatile 로 한정된 대상체에 대해서 포인터를 통해 사용할 때,
//   정확한 한정자가 지정되어야 합니다.

int main(void)
{
  static volatile int i = 0;
  volatile int *pi = &i;

  *pi = 100;
  printf("%d\n", *pi);

  const int *pc = &c;
  // *pc = 100;           /* 컴파일 오류 */
  printf("%d\n", *pc); /* OK */

  int n = 10;
  int *restrict pr = &n;

  int *pn = pr; /* OK */

  return 0;
}